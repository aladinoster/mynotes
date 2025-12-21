#include <cuda_runtime.h>
#include <iostream>

// Standard libraries for image loading/saving
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

/**
 * KERNEL: colorToGrayScaleKernel
 * Processes a 3-channel RGB image into a 1-channel Grayscale image.
 */
__global__ void colorToGrayScaleKernel(unsigned char *Pout, unsigned char *Pin,
                                       int width, int height) {
  // Calculate global 2D coordinates
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  int row = blockIdx.y * blockDim.y + threadIdx.y;

  // Boundary check to prevent accessing memory outside the image
  if (col < width && row < height) {
    // Linear index for 1-channel output (Grayscale)
    int grayOffset = row * width + col;

    // Linear index for 3-channel input (RGB)
    int rgbOffset = grayOffset * 3;

    // Read RGB values
    unsigned char r = Pin[rgbOffset];
    unsigned char g = Pin[rgbOffset + 1];
    unsigned char b = Pin[rgbOffset + 2];

    // Apply luma formula (NTSC) and write to output
    // We use 0.21f, 0.71f, 0.07f to account for human eye sensitivity
    Pout[grayOffset] = (unsigned char)(0.21f * r + 0.71f * g + 0.07f * b);
  }
}

/**
 * MAIN: Host execution flow
 */
int main() {
  int width, height, channels;
  const char *input_file = "input.png";
  const char *output_file = "output.png";

  // 1. LOAD IMAGE: Force 3 channels (RGB)
  unsigned char *h_Pin = stbi_load(input_file, &width, &height, &channels, 3);
  if (!h_Pin) {
    std::cerr << "Error: Could not open " << input_file
              << ". Ensure the file exists." << std::endl;
    return -1;
  }

  std::cout << "Loaded image: " << width << "x" << height << " with "
            << channels << " channels." << std::endl;

  // 2. ALLOCATE HOST MEMORY: For the result
  unsigned char *h_Pout =
      (unsigned char *)malloc(width * height * sizeof(unsigned char));

  // 3. ALLOCATE DEVICE MEMORY: (void**)& is used to modify the pointer
  // addresses
  unsigned char *d_Pin, *d_Pout;
  size_t sizeRGB = width * height * 3 * sizeof(unsigned char);
  size_t sizeGray = width * height * sizeof(unsigned char);

  cudaMalloc((void **)&d_Pin, sizeRGB);
  cudaMalloc((void **)&d_Pout, sizeGray);

  // 4. COPY DATA: Host to Device
  cudaMemcpy(d_Pin, h_Pin, sizeRGB, cudaMemcpyHostToDevice);

  // 5. CONFIGURE GRID: 16x16 threads per block
  dim3 dimBlock(16, 16, 1);
  dim3 dimGrid((width + dimBlock.x - 1) / dimBlock.x,
               (height + dimBlock.y - 1) / dimBlock.y, 1);

  // 6. LAUNCH KERNEL
  std::cout << "Launching CUDA Kernel..." << std::endl;
  colorToGrayScaleKernel<<<dimGrid, dimBlock>>>(d_Pout, d_Pin, width, height);

  // Synchronize to check for kernel errors
  cudaDeviceSynchronize();

  // 7. COPY RESULT: Device back to Host
  cudaMemcpy(h_Pout, d_Pout, sizeGray, cudaMemcpyDeviceToHost);

  // 8. SAVE IMAGE: 1 channel output
  stbi_write_png(output_file, width, height, 1, h_Pout, width);
  std::cout << "Success! Grayscale image saved as: " << output_file
            << std::endl;

  // 9. CLEANUP
  stbi_image_free(h_Pin);
  free(h_Pout);
  cudaFree(d_Pin);
  cudaFree(d_Pout);

  return 0;
}
