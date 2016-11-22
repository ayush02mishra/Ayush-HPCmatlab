#module purge
#module load mvapich2/2.1-gnu-4.9.2
#module load openmpi/1.8.5-gnu-4.9.2
rm -r mxml
rm -r mxml_temp
cp -r mxml-2.7 mxml_temp
cwd=$(pwd)
cd mxml_temp
chmod +x configure
./configure --prefix=$cwd/mxml
sleep 5
make
sleep 5
make install
