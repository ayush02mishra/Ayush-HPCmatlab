export LD_LIBRARY_PATH=~/SC14/mxml/lib:$LD_LIBRARY_PATH
export tempfolder=/scratch/xguo44/adios_test
rm -r $tempfolder
mkdir $tempfolder
cp test.m paraIO.mexa64 config.xml $tempfolder
cd $tempfolder
mpirun -n 16 matlab -r "test"
cp *.mat ~/SC14/testset/adios/mxl
