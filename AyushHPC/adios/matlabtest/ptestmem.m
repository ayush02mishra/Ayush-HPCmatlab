poolsize=4;
%parpool(poolsize);
matlabpool close force local
matlabpool('open','local',poolsize);

load seed.mat
rng(seed);

globalsize=32;

datasize=globalsize/poolsize; %GBi
elenum=datasize*1024*1024*1024/8;
datatemp=rand(elenum,1);
tsi=tic;
fileID=fopen('memmap.dat','wb');
fwrite(fileID,[1:elenum*poolsize],'double');
fclose(fileID);
tsie=toc(tsi);
datasize=globalsize/poolsize; %GBi
elenum=datasize*1024*1024*1024/8;
datatemp=rand(elenum,1);


spmd
mf=memmapfile('memmap.dat','Writable',true,'Format','double');



starti=(labindex-1)*elenum+1;
endi=labindex*elenum;
labBarrier;
ts=tic;
%save('testdata.mat','datatemp','-v7.3');
mf.Data(starti:endi)=datatemp;
labBarrier;
tt=toc(ts);
speedrate=datasize/(tt+tsie)*poolsize;
disp(['Data speed ' num2str(speedrate) 'GB/s']);
end
%delete(gcp)

matlabpool close
exit
