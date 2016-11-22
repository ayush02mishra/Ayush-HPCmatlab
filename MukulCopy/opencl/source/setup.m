function [openclenv]=setup(num,devicetype,kernelname)
% out: kernel, queue, context
GetOpencl
% Declaring opencl objects:
platform=cl_platform_id;
for i=1:num
    devices(i)=cl_device_id;
end
num_platforms=0;
num_devices=0;

% Acquiring available platforms
err=clGetPlatformIDs(1,platform,num_platforms);
if err~=0
    error(['Error code ' num2str(err) ' while getting platform ID']);
end

if devicetype=='CPU'
    err=clGetDeviceIDs(platform,CL_DEVICE_TYPE_CPU,num,devices,num_devices);
elseif devicetype=='GPU'
    err=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,num,devices,num_devices);
end
if err~=0
    error(['Error code ' num2str(err) ' while getting device IDs']);
end

% Creating context from the devices
context=clCreateContext(NULL,num,devices,NULL,NULL,err);
if err~=0
    error(['Error code ' num2str(err) ' while creating context']);
end

% Creating command queues: 1 for each device
for i=1:num
    %queue(num)=clCreateCommandQueueWithProperties(context,devices(num),NULL,err);
    queue(num)=clCreateCommandQueue(context,devices(num),NULL,err);
    if err~=0
        error(['Error code ' num2str(err) ' while creating queue for device number ' num2str(num)]);
    end
end

% Read in kernel code as string
kernel_string=fileread(kernelname);
len=length(kernel_string);
% Create and build program
program=clCreateProgramWithSource(context,1,kernel_string,len,err);
if err~=0
    error(['Error code ' num2str(err) ' while creating program with source']);
end

err=clBuildProgram(program,0,NULL,NULL,NULL,NULL);
if err~=0
    error(['Error code ' num2str(err) ' while creating context']);
end

kernel_name=kernelname(1:(end-3));
% Create kernel
kernel=clCreateKernel(program,kernel_name,err);
if err~=0
    error(['Error code ' num2str(err) ' while creating kernel']);
end

openclenv = struct('context',context,'queue',queue,'kernel',kernel);

disp(['Context and command queues successfully created, program built and kernel created for ' ...
    num2str(num_devices) ' device(s) using ' num2str(num_platforms) ' platform(s)']);

end
