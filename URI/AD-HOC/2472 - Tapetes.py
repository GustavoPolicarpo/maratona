# Author: Gustavo Policarpo
# Name: Tapetes
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2472

n, m = map (int, raw_input().split() )
ans = (n-m+1)*(n-m+1) + m-1
print ans
