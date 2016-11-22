addpath ~/SC14/HPCMatlab/matlab
load seed.mat
rng(seed);
datasize=8; %GBi

elenum=datasize*1024*1024*1024/8;
datatemp=rand(elenum,1);
ts=tic;
save('testdata.mat','datatemp','-v7.3');
tt=toc(ts);
speedrate=datasize/tt;
disp(['Data speed ' num2str(speedrate) 'GB/s']);
exit
