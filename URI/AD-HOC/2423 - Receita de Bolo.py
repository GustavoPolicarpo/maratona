# Author: Gustavo Policarpo
# Name: Receita de Bolo
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2423

a, b, c = map ( int, raw_input().split() )
aa = a/2
bb = b/3
cc = c/5
print min(aa, min(bb, cc))
