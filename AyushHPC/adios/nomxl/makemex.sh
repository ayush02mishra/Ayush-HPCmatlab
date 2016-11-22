export workbase=$HOME/SC14
#export workbase="/home1/02901/gxinchen/adios_related"
export linkflag="-L$workbase/adios/lib/ -ladios -L$workbase/mxml/lib -lmxml -lm -lpthread"
export compileflag="-I$workbase/adios/include -I$workbase/mxml/include"
#rm $mexfiles
export mexcompiler="CC=mpicc CXX=mpicxx"

mex $linkflag $compileflag $mexcompiler -g -DDEBUG testmex.cpp
