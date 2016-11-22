function [result_buff] = get_output(openclenv,output_buffer,result_buff)

GetOpencl
sz=size(output_buffer);
for i=1:sz(2)
    err=clEnqueueReadBuffer(openclenv.queue,output_buffer{i},CL_TRUE,0,8*length(result_buff{i}),result_buff{i},0,NULL,NULL);
    if err~=0
        error(['Error code ' num2str(err) ' while reading output buffer ' num2str(i)]);
    end
end

disp(['Successfully read ' num2str(sz(2)) ' output buffer(s) from device']);

end
