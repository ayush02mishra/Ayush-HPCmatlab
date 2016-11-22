% Attempt to complete materix multiplication on GPU from Matlab
addpath ../../CLmatlab/

% Get OpenCL Environment:
GetOpencl
% Declaring opencl objects: 
platform=cl_platform_id;
devices(1)=cl_device_id;
% devices(2)=cl_device_id;
% No need to define context and queue as they are not passed as arguments during their initialisation
% context=cl_context;
% queue=cl_command_queue;
num_platforms=0;
num_devices=0;

% Note: For all the following functions, 'err' value should be zero for 'SUCCESS' otherwise less than zero

% Acquiring available platforms
[err,platform,num_platforms]=clGetPlatformIDs(1)
num_platforms
% Getting devices: Now working on CPUs and GPUs both!
[err,devices,num_devices]=clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,1)
num_devices
% Creating context from the devices
context=clCreateContext(NULL,1,devices,NULL,NULL,err);
err
% Creating command queues: 1 for each device
%queue(1)=clCreateCommandQueueWithProperties(context,devices(1),NULL,err);
queue(1)=clCreateCommandQueue(context,devices(1),NULL,err);
err
% queue(2)=clCreateCommandQueue(context,devices(2),0,err);
% err
N=4096;
b1=rand(N);
buff1=reshape(b1',[],1);
b2=rand(N);
buff2=reshape(b2',[],1);
result_buff=zeros(1,N*N);

tic

% Creating the buffers: 'buff1' is copied to 'input_buffer' using flag CL_MEM_COPY_HOST_PTR
% In flags, note the use of 'bitor' matlab function instead of '|' C operator. In matlab, '|' is logical OR
% Find solution if possible
input_buffer1=clCreateBuffer(context,bitor(CL_MEM_READ_ONLY,CL_MEM_COPY_HOST_PTR),8*length(buff1),buff1,err)
err
input_buffer2=clCreateBuffer(context,bitor(CL_MEM_READ_ONLY,CL_MEM_COPY_HOST_PTR),8*length(buff2),buff2,err)
err
output_buffer=clCreateBuffer(context,CL_MEM_WRITE_ONLY,8*length(buff1),NULL,err)
err

kernel_string=fileread('multiply.cl');
%kernel_string(end+1)=char(0);
len=length(kernel_string);
program=clCreateProgramWithSource(context,1,kernel_string,len,err)
err

err=clBuildProgram(program,1,devices,NULL,NULL,NULL)

kernel_name='multiply';
kernel=clCreateKernel(program,kernel_name,err)
err

sizeof_cl_mem
err=clSetKernelArg(kernel,2,sizeof_cl_mem,input_buffer1)
err=clSetKernelArg(kernel,3,sizeof_cl_mem,input_buffer2)
err=clSetKernelArg(kernel,1,sizeof_cl_mem,output_buffer)

global_size(1)=N;
global_size(2)=N;
local_size(1)=1;
local_size(2)=1;
err=clEnqueueNDRangeKernel(queue,kernel,2,NULL,global_size,local_size,0,NULL,NULL)

err=clEnqueueReadBuffer(queue,output_buffer,CL_TRUE,0,8*length(buff1),result_buff,0,NULL,NULL)

toc

result_buff=reshape(result_buff,N,N);
result_buff=result_buff';

buff_check=b1*b2;
display('checking------');
nnz(~(buff_check==result_buff))
max(max(buff_check-result_buff))
