#!/bin/bash
#SBATCH -n 1
#SBATCH -t 00:10:00
#SBATCH -p cuda
#SBATCH -o dev.out
#SBATCH -e dev.err
#module load gcc/4.9.2
module load matlab/2016a
matlab -r "fftCudaTest,exit"
