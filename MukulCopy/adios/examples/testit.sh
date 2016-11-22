cd /scratch/xguo44
rm -r saveadios
cp -r ~/SC14/saveadios/examples ./saveadios
cd saveadios
mpirun -n 4 matlab -singleCompThread -r "test"
