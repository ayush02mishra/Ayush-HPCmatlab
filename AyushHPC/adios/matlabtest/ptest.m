poolsize=4;
%parpool(poolsize);
matlabpool('open','local',poolsize);

load seed.mat
rng(seed);
type('pdata.mat')
spmd
mf=matfile('pdata.mat','Writable',true);

datasize=8/poolsize; %GBi
elenum=datasize*1024*1024*1024/8;
datatemp=rand(elenum,1);

starti=(labindex-1)*elenum+1;
endi=labindex*elenum;
labBarrier;
ts=tic;
%save('testdata.mat','datatemp','-v7.3');
mf.gdata(starti:endi,1)=datatemp;
labBarrier;
tt=toc(ts);
speedrate=datasize/tt*poolsize;
disp(['Data speed ' num2str(speedrate) 'GB/s']);
end
%delete(gcp)
matlabpool close
exit
