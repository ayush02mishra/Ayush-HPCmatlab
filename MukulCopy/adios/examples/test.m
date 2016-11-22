addpath ~/SC14/saveadios/matlab
addpath ~/SC14/HPCMatlab/matlab
load seed.mat
rng(seed);

GetMPIEnvironment;
commsize=0;
commrank=0;
err=MPI_Init(0,0);
err=MPI_Comm_size(MPI_COMM_WORLD,commsize);
err=MPI_Comm_rank(MPI_COMM_WORLD,commrank);

datasize=1; %GB
localsize=datasize/commsize;
elenum=localsize*1024*1024*1024/8;
testdata=rand(elenum,1); %GB
err=MPI_Barrier(MPI_COMM_WORLD);
ts=tic;
testmex('test.bp','testdata',num2str(elenum*commsize),num2str(elenum*commrank),num2str(elenum));
tt=toc(ts);
speedrate=datasize/tt;
disp(['Data speed ' num2str(speedrate) 'GB/s']);

err=MPI_Finalize;
exit
