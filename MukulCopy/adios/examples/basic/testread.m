addpath /home/gxinchen/HPCmatlab_working/adios/matlab
addpath /home/gxinchen/HPCmatlab_working/matlab


GetMPIEnvironment;
commsize=0;
commrank=0;
err=MPI_Init(0,0);
err=MPI_Comm_size(MPI_COMM_WORLD,commsize);
err=MPI_Comm_rank(MPI_COMM_WORLD,commrank);

disp(['I am rank ' num2str(commrank) ' out of ' num2str(commsize)]);

totalsize=16*128*1024^2; %32 GB data

elenum=totalsize/commsize;
testdata=zeros(1,elenum);
err=MPI_Barrier(MPI_COMM_WORLD);
tic
readadios('test.bp','testdata',num2str(elenum*commsize),num2str(elenum*commrank),num2str(elenum));
err=MPI_Barrier(MPI_COMM_WORLD);
TimeCost=toc
checksum=DataHash(testdata(1:128:end))
%checksum=DataHash(testdata)
save(['read_checksum_' num2str(commrank) '.mat'],'checksum','totalsize','elenum','TimeCost');

err=MPI_Finalize;
exit
