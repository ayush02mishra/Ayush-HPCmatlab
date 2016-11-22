NULL=0;
CL_TRUE=1;
CL_FALSE=0;

[ cl_platform_id, cl_device_id, cl_context, cl_command_queue, cl_mem, cl_program, cl_kernel, cl_event, cl_sampler ] = GetOpenclStruct;

dt=whos('cl_mem');
sizeof_cl_mem=dt.bytes;

CLDeviceTypeArray=GetDeviceTypes;
CL_DEVICE_TYPE_CPU=CLDeviceTypeArray(1);
CL_DEVICE_TYPE_GPU=CLDeviceTypeArray(2);
CL_DEVICE_TYPE_ACCELERATOR=CLDeviceTypeArray(3);
CL_DEVICE_TYPE_DEFAULT=CLDeviceTypeArray(4);
CL_DEVICE_TYPE_ALL=CLDeviceTypeArray(5);

CLMemFlagsArray=GetMemFlags;
CL_MEM_READ_WRITE=CLMemFlagsArray(1);
CL_MEM_WRITE_ONLY=CLMemFlagsArray(2);
CL_MEM_READ_ONLY=CLMemFlagsArray(3);
CL_MEM_USE_HOST_PTR=CLMemFlagsArray(4);
CL_MEM_ALLOC_HOST_PTR=CLMemFlagsArray(5);
CL_MEM_COPY_HOST_PTR=CLMemFlagsArray(6);

opencl_env = struct('context',cl_context,'queue',cl_command_queue,'kernel',cl_kernel);
