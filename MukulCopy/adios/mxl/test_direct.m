system('hostname','-echo');
rng(1);
N=2.4E8;
data=rand(N,1);
NN=10;
timecost=zeros(NN,1);
for ii=1:NN
	pause(15);
	system('rm a.mat','-echo');
	tic;
	save('a.mat','data','-v6');
	timecost(ii)=toc
end
filename='Direct';
timecost
save(filename,'timecost');
exit
