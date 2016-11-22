% Set up HPCmatlab OpenCL environment
GetOpencl
% Initialize a struct to store OpenCL environment objects
env = opencl_env;
%% Setup the context, command queues and kernel
env = setup(1,'CPU','vecadd.cl');
%% Pass number, type of devices sought and kernel file name

N = 64;
% Initialize input buffers
input_buff{1} = rand(N,1);
input_buff{2} = rand(N,1);
% Preallocate output buffer
output_buff{1} = zeros(N,1);
% The order of arguments to kernel should be same as above

%% Set arguments to kernel
device_buffs=setarg(env,input_buff,output_buff);
%% Pass environment struct, and buffer cell arrays

% Assign global and local number of work items
global_size = N;
local_size = 1;
%% Launch kernel
launch(env,global_size,local_size);
%% Pass env struct, global and local size

%% Retrieve output from device
output_buff = get_output(env,device_buffs,output_buff);
%% Pass env struct, device output buffer objects and
%% buffer to receive the output

buff_sum = output_buff{1};
buff_check = input_buff{1} + input_buff{2};
check = norm(buff_check - buff_sum)

