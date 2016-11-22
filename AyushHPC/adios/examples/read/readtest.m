addpath ~/SC14/saveadios/matlab
datasize=8; %GB
elenum=datasize*1024*1024*1024/8;
ts=tic;
readadios('data');
tt=toc(ts);
speedrate=datasize/tt;
whos;
disp(['Data speed ' num2str(speedrate) 'GB/s']);
exit
