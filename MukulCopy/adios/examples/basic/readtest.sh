cd /oasis/scratch/gxinchen/temp_project/saveadios
pwd
mpirun_rsh -np 16 -hostfile $PBS_NODEFILE /opt/matlab/2014b/bin/matlab  -nodisplay -singleCompThread -r "testread"
