module purge
module load mvapich2/1.9-gnu-4.4.7
export workbase="/home/xguo44/A2C2"
#export LD_LIBRARY_PATH=$workbase/mxml/lib:$LD_LIBRARY_PATH
export linkflag="-L$workbase/adios/lib -ladios -L$workbase/mxml/lib -lmxml -lm -lpthread "
export compileflag="-I$workbase/adios/include -I$workbase/mxml/include "
rm a.out
rm *.bp
mpicc test.c $linkflag $compileflag
#mpiexec -n 2 ./a.out
#ls
