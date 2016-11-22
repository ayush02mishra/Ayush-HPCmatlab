#!/bin/bash
#SBATCH -n 9
#SBATCH -t 00:15:00
#SBATCH -o test.out
#SBATCH -e test.err
module load mvapich2/2.1-gnu-4.9.2
module load matlab/2015a
export MATLABPATH=${MATLABPATH}:../../matlab
srun -n 9 --mpi=pmi2 matlab -r "test,exit"
