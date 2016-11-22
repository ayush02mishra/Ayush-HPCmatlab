#module load mvapich2/1.9-gnu-4.4.7
source ~/A2C2/octsource/env.sh
rm -r octave
mkdir octave
MEXcc=mkoctfile
FLAG="--mex  "
rawinc=$(mpicxx -compile_info)
incflag=$(echo $rawinc | sed -e "s/c++/ /g")i
workbase=$HOME/SC14
linkflag="-L$workbase/adios/lib/ -ladios -L$workbase/mxml/lib -lmxml -lm"
compileflag="-I$workbase/adios/include -I$workbase/mxml/include"
#export rawlib=$(mpicc -link_info)
#export libflag=$(echo $rawlib | sed -e "s/gcc/ /g")
Files=./source/*.c*
for file in $Files
do
    echo $file
    $MEXcc $FLAG $incflag $compileflag $linkflag $file
done
mv *.mex octave
rm *.o
cp ./source/*.m octave
