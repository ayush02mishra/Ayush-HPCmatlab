addpath ../../CLmatlab/

% Get OpenCL Environment:
GetOpencl
% Declaring opencl objects: 
platform=cl_platform_id;
devices(1)=cl_device_id;
%devices(2)=cl_device_id;
% No need to define context and queue as they are not passed as arguments during their initialisation
% context=cl_context;
% queue=cl_command_queue;
num_platforms=0;
num_devices=0;

% Note: For all the following functions, 'err' value should be zero for 'SUCCESS' otherwise less than zero

% Acquiring available platforms
[err,platform,num_platforms]=clGetPlatformIDs(1)
num_platforms
platform
% Getting devices: Now working on CPUs and GPUs both!
[err,devices,num_devices]=clGetDeviceIDs(platform,CL_DEVICE_TYPE_CPU,1)
num_devices
devices
% Creating context from the devices
context=clCreateContext(NULL,1,devices,NULL,NULL,err);
err
devices 
context


%err = clGetDeviceInfo(devices,CL_DEVICE_ADDRESS_BITS,NULL,NULL,size);
%display(['Global Size' num2str(size)]);

%err = clGetDeviceInfo(devices,CL_DEVICE_MAX_WORK_GROUP_SIZE,NULL,NULL,size);
%display(['Global Size' num2str(size)]);

% Creating command queues: 1 for each device
%queue(1)=clCreateCommandQueueWithProperties(context,devices(1),NULL,err);
queue(1)=clCreateCommandQueue(context,devices(1),NULL,err);
err
% queue(2)=clCreateCommandQueue(context,devices(2),0,err);
% err

buff1=zeros(2^7,1);
buff2=zeros(2^7,1);
for i=1:length(buff1)
    buff1(i)=i;
end

buff2=2*buff1;

buff_sum=0*buff1;

% Creating the buffers: 'buff1' is copied to 'input_buffer' using flag CL_MEM_COPY_HOST_PTR
% In flags, note the use of 'bitor' matlab function instead of '|' C operator. In matlab, '|' is logical OR
% Find solution if possible
input_buffer1=clCreateBuffer(context,bitor(CL_MEM_READ_ONLY,CL_MEM_COPY_HOST_PTR),8*length(buff1),buff1,err)
err
input_buffer2=clCreateBuffer(context,bitor(CL_MEM_READ_ONLY,CL_MEM_COPY_HOST_PTR),8*length(buff2),buff2,err)
err
output_buffer=clCreateBuffer(context,CL_MEM_WRITE_ONLY,8*length(buff1),NULL,err)
err

% err=clEnqueueWriteBuffer(queue(1),input_buffer,CL_TRUE,0,8*length(buff1),buff1,NULL,NULL,NULL)

% Copying from 'input_buffer' to 'output_buffer'
% err=clEnqueueCopyBuffer(queue(1),input_buffer,output_buffer,0,0,8*length(buff1),NULL,NULL,NULL)

% Reading from 'output_buffer' into 'buff2'
% err=clEnqueueReadBuffer(queue(1),output_buffer,CL_TRUE,0,8*length(buff1),buff2,0,NULL,NULL)
% Verify if buff2 is same as buff1
% buff2
tic
kernel_string=fileread('vecadd.cl');
%kernel_string(end+1)=char(0);
len=length(kernel_string);
program=clCreateProgramWithSource(context,1,kernel_string,len,err)
err

err=clBuildProgram(program,1,devices,NULL,NULL,NULL)

kernel_name='vecadd';
kernel=clCreateKernel(program,kernel_name,err)
err

sizeof_cl_mem
err=clSetKernelArg(kernel,1,sizeof_cl_mem,input_buffer1)
err=clSetKernelArg(kernel,2,sizeof_cl_mem,input_buffer2)
err=clSetKernelArg(kernel,3,sizeof_cl_mem,output_buffer)

local_size=128;
global_size=ceil(8*length(buff1)/local_size)*local_size;

err=clEnqueueNDRangeKernel(queue,kernel,1,NULL,global_size,local_size,0,NULL,NULL)

err=clEnqueueReadBuffer(queue,output_buffer,CL_TRUE,0,8*length(buff1),buff_sum,0,NULL,NULL)
toc
tic
buff_check=buff1+buff2;
toc
nnz(~(buff_check==buff_sum))

%buff_check
%buff_sum
