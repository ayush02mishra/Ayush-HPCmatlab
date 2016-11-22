function launch(openclenv,global_size,local_size)

GetOpencl
if length(global_size)~=length(local_size)
    error('Global size and local size must show same number of dimensions');
end

% Limitation to launch kernel on the 1st queue only
dim=length(global_size);
err=clEnqueueNDRangeKernel(openclenv.queue(1),openclenv.kernel,dim,NULL,global_size,local_size,0,NULL,NULL);
if err~=0
    error(['Error code ' num2str(err) ' while launching kernel']);
else
    disp('Kernel successfully launched on command queue 1');
end

end
