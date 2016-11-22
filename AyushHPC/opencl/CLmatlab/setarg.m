function [output_buffer] = setarg(openclenv,inbuff,outbuff)
% return output buffer object to retrieve output later
GetOpencl
err=0;
insz=size(inbuff);
nin=insz(2);
outsz=size(outbuff);
nout=outsz(2);
% Create buffers on device for input/output to/from kernel with same size as host buffers
% and copy data to the input buffers
for i=1:nin
    input_buffer{i}=clCreateBuffer(openclenv.context,bitor(CL_MEM_READ_ONLY,CL_MEM_COPY_HOST_PTR),8*length(inbuff{i}),inbuff{i},err);
    if err~=0
        error(['Error code ' num2str(err) ' while creating input buffer ' num2str(i)]);
    end
end

for i=1:nout
    output_buffer{i}=clCreateBuffer(openclenv.context,CL_MEM_WRITE_ONLY,8*length(outbuff{i}),NULL,err);
    if err~=0
        error(['Error code ' num2str(err) ' while creating output buffer ' num2str(i)]);
    end
end

% Set the device buffers as arguments to kernel
for i=1:nin
    err=clSetKernelArg(openclenv.kernel,i,sizeof_cl_mem,input_buffer{i});
    if err~=0
        error(['Error code ' num2str(err) ' while setting input buffer ' num2str(i) ' as argument to kernel']);
    end
end
for i=1:nout
    err=clSetKernelArg(openclenv.kernel,nin+i,sizeof_cl_mem,output_buffer{i});
    if err~=0
        error(['Error code ' num2str(err) ' while setting output buffer ' num2str(i) ' as argument to kernel']);
    end
end

disp('Successfully created device buffers and set kernel arguments');

end
