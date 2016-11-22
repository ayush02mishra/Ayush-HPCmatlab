clear
parpool
N=4096;
A=rand(N*N,1);
B=rand(N*N,1);
C=zeros(N*N,1);
tic
parfor i=1:N*N
    ty=ceil(i/N);
    tx=mod(i,N);
    if tx==0
        tx=N;
    end

    for k=1:N
        elementA = A((ty-1) * N + k);
        elementB = B((k-1) * N + tx);
        C(i) = C(i) + elementA * elementB;
    end
end
toc
delete(gcp('nocreate'));
