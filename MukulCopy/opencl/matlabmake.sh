#!/bin/bash
#SBATCH -n 1
#SBATCH -t 00:10:00
module load matlab/2015a
module load gcc/4.9.2
rm -r CLmatlab
mkdir CLmatlab
Files=./source/*.c
mexcompiler="CC=gcc"
for file in $Files
do
    echo $file
    #mex $file $mexcompiler COPTIMFLAGS="-O2 -DNDEBUG" LDOPTIMFLAGS="-O2" -I/usr/local/cuda-7.5/include -L/usr/local/cuda-7.5/lib64 -lOpenCL
    #mex $file $mexcompiler COPTIMFLAGS="-O2 -DNDEBUG" LDOPTIMFLAGS="-O2" -I/home/mhdave1/libs/AMDAPPSDK-3.0/include -L/home/mhdave1/libs/AMDAPPSDK-3.0/lib/x86_64 -lOpenCL
	mex $file $mexcompiler COPTIMFLAGS="-O2 -DNDEBUG" LDOPTIMFLAGS="-O2" -I/home/amishr24/AMDAPPSDK-3.0/include -L/home/amishr24/AMDAPPSDK-3.0/lib/x86_64/ -lOpenCL
done
mv *.mexa64 CLmatlab
cp ./source/*.m CLmatlab
chgrp -R A2C2dev CLmatlab
