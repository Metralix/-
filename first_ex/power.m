clear; clc;
DATA_N = 15000;
PSS_N = 2048;
data = zeros(48, DATA_N);
pss = zeros(3, PSS_N);
for n = 0:47
    s = load(['data' , num2str(n) , '.txt']);
    for i = 1 :DATA_N;
        data(n+1, i) = s(2*i-1)+j*s(2*i);
    end
end

for n = 0:2
    s = load(['pss' , num2str(n) , '.txt']);
    for i = 1 :PSS_N;
        pss(n+1, i) = s(2*i-1)+j*s(2*i);
    end
end

p = mean(abs(data),2);
[m,I] =max(p);
p_sort = sort(p);

pss_number = 1;
N_LEN = DATA_N - PSS_N;
cor = zeros(48, N_LEN);
for n = 1 : 48
    for m = 1 : N_LEN
        cor(n, m) = real(sum(data(n, m:m+PSS_N-1) .* conj(pss(pss_number, :))));
    end
end

[Y,I] = max(cor,[],2);
[M,I] = max(Y)