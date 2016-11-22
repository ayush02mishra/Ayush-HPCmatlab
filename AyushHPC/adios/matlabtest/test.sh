cd /scratch/xguo44
rm -r matlabtest
cp -r ~/SC14/saveadios/matlabtest .
cd matlabtest
matlab -singleCompThread -r "test"
