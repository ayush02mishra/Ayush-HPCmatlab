cd /scratch/xguo44/saveadios
rm readtest.m readadios.*
cp ~/SC14/saveadios/examples/read/*.* .
mpirun -n 2 matlab -singleCompThread -r "readtest"
