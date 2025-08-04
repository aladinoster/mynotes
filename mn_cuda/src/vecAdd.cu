#include <cuda_runtime.h>
#include <iostream>

__global__ void vecAddKernel(float *A, float *B, float *C, int n) {
  int i = threadIdx.x + blockDim.x * blockIdx.x;
  if (i < n) {
    C[i] = A[i] + B[i];
  }
}

void vecAddCPU(float *A, float *B, float *C, int n) {
  for (int i = 0; i < n; i++)
    C[i] = A[i] + B[i];
}

void vecAddCUDA(float *A_h, float *B_h, float *C_h, int n) {
  float *A_d, *B_d, *C_d;
  size_t size = n * sizeof(float);

  // Allocate device memory
  cudaMalloc((void **)&A_d, size);
  cudaMalloc((void **)&B_d, size);
  cudaMalloc((void **)&C_d, size);

  // Copy host arrays to device
  cudaMemcpy(A_d, A_h, size, cudaMemcpyHostToDevice);
  cudaMemcpy(B_d, B_h, size, cudaMemcpyHostToDevice);

  // Launch kernel
  int blockSize = 256;
  int numBlocks = (n + blockSize - 1) / blockSize;
  vecAddKernel<<<numBlocks, blockSize>>>(A_d, B_d, C_d, n);

  // Copy result back to host
  cudaMemcpy(C_h, C_d, size, cudaMemcpyDeviceToHost);

  // Free device memory
  cudaFree(A_d);
  cudaFree(B_d);
  cudaFree(C_d);
}

int main() {
  int n = 1000; // Example size
  float *A = new float[n];
  float *B = new float[n];
  float *C = new float[n];

  // Initialize input arrays
  for (int i = 0; i < n; i++) {
    A[i] = i;
    B[i] = i * 2;
  }

  // Call CUDA vector addition
  vecAddCUDA(A, B, C, n);

  // Verify results
  for (int i = 0; i < n; i++) {
    if (C[i] != A[i] + B[i]) {
      std::cerr << "Error at index " << i << std::endl;
      break;
    }
  }

  std::cout << "Vector addition completed successfully!" << std::endl;

  delete[] A;
  delete[] B;
  delete[] C;

  return 0;
}
