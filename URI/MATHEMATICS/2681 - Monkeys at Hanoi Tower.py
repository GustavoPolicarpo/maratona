# Author: Gustavo Policarpo
# Name: Monkeys at Hanoi Tower
# Level: 8
# Category: MATHEMATICS
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2681

n = int(input());
ans = 1
base = 2
mod = 24*60*60
while(n>0):
    if(n&1):ans = (ans*base)%mod
    n>>=1
    base = (base*base)%mod
ans = ans-1
h = ans/60/60
m = (ans%3600)/60
s = ans%60
print "%02d:%02d:%02d" %(h,m, s)
