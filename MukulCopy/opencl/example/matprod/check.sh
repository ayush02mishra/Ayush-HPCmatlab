#!/bin/bash
#SBATCH -p cluster
#SBATCH -n 8
#SBATCH -t 00:10:00
#SBATCH -o check.out
#SBATCH -e check.e 
module load matlab/2015a
matlab -r "check,exit"
