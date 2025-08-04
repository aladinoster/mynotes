# CUDA 

How to program Paralell Processors? 

This is a good beginning 

## Installation process

You will need to install `nvcc` the NVIDIA compiler to test this scpripts:

```bash

sudo apt-key adv --fetch-keys https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/3bf863cc.pub
sudo nano /etc/apt/sources.list.d/cuda.list
sudo apt update
sudo apt install cuda
```

## Compile

```bash
nvcc -o vecAdd vecAdd.cu
```
