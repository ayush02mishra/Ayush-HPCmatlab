addpath ~/SC14/MEXsrc
	[rank,size]=MPI_Init;
system('hostname','-echo');
rng(1);
N=2.4E8;
NN=10;
timecost=zeros(NN,1);
data=rand(N,1);
for ii=1:NN
	if(rank==0)
		system('rm *.bp','-echo');
		pause(15);
		MPI_Barrier;
		tic;
		paraIO(data,N);
		MPI_Barrier;
		timecost(ii)=toc;
	else
		MPI_Barrier;
		paraIO(data,N);
		MPI_Barrier;
	end
	
end
%tic;
%save a.mat
%toc;
if(rank==0)
	filename=num2str(size);
	timecost
	save(filename,'timecost');
end
	MPI_Barrier;
	MPI_Finalize;
exit
