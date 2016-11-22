#module purge
#module load automake/1.15
#module load python/2.7.9
#module load mvapich2/2.1-intel-2015.3
#module load openmpi/1.8.5-gnu-4.9.2
#module load intel-mpi/5.0
#module load hdf5/1.8.14-gnu-4.9.2-openmpi-1.8.5
#module load netcdf/4.3.3.1-gnu-4.9.2
#module load hdf5/1.8.14-gnu-4.9.2-mvapich-2.1
#module load mvapich2/2.1-gnu-4.9.2

rm -r adios
rm -r adios_temp
cp -r adios-1.9.0 adios_temp
cwd=$(pwd)
cd adios_temp
chmod +x configure
chmod +x utils/gpp/gpp.py
export MPICC=mpicc
export MPICXX=mpicxx
export MPIFC=mpif90
export CC=mpicc
export CXX=icpc
export FC=mpif90
export CFLAGS="-fPIC"
./configure --prefix=$cwd/adios --with-mxml=$cwd/mxml
#sleep 60
make -j 8
#sleep 60
make install
