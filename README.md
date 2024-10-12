# NVIDIA-SMI Mock CLI Implementation

Author: Izabella Imperial

## Program Overview

This is a C++ application that replicates the output of the `nvidia-smi` command using the `ncurses` library. The program displays mock GPU information, including driver version, CUDA version, and a list of dummy processes. The layout is carefully designed using colors and borders to match the style of the real `nvidia-smi` tool.

## Entry Class

The main function is located in the `nvidia-smi.cpp` file.

## Requirements

- A C++ compiler (e.g., `g++`)
- The `ncurses` library

## Installation

### Installing `ncurses`:

- **On macOS** (using Homebrew):
  ```bash
  brew install ncurses

##Compilation and Execution

1. Navigate to the directory where nvidia-smi-mock.cpp is located.
2. Compile the program using the following command:
   ```bash
   g++ -o nvidia-smi nvdia-smi.cpp -lncurses 
3. Run the program:
   ```bash
   ./nvidia-smi
   
