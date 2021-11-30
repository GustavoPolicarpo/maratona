# Author: Gustavo Policarpo
# Name: Transporte de Contêineres
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2395

a, b, c = map( int, raw_input().split() )
x, y, z = map( int, raw_input().split() )

ans = (x/a)*(y/b)*(z/c)

print ans
