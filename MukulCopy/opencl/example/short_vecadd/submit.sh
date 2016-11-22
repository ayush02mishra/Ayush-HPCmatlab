#!/bin/bash
#SBATCH -n 1
#SBATCH -t 00:10:00
#SBATCH -p cuda
#SBATCH -o dev.out
module load gcc/4.9.2
module load matlab/2015a
export MATLABPATH=../../CLmatlab
matlab -r "trial,exit"
