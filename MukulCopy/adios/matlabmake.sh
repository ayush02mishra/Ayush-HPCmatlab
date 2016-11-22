#source env.sh

Files=./source/*.cpp
workbase=./ADIOS
linkflag="-L$workbase/adios/lib/ -ladios -L$workbase/mxml/lib -lmxml -lm -lpthread"
compileflag="-I$workbase/adios/include -I$workbase/mxml/include"
mexcompiler="CC=mpicc CXX=mpicxx"
additionalflags="-largeArrayDims -DDEBUG"

rm -r matlab
mkdir matlab
for file in $Files
do
    echo $file
    mex $linkflag $compileflag $mexcompiler $additionalflags $file
done
mv *.mexa64 matlab
cp ./source/*.m matlab
