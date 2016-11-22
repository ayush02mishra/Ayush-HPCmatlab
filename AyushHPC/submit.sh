#!/bin/bash
#SBATCH -n 1
#SBATCH -p cuda
#SBATCH -t 00:07:00
#SBATCH -o tt.out
#SBATCH -e tt.err
module load matlab/2016a
export MATLABPATH=../../matlab
srun -n 1 matlab -r "parallel,exit"

