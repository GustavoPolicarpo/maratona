# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Transporte de Contêineres
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2395

a, b, c = map( int, raw_input().split() )
x, y, z = map( int, raw_input().split() )

ans = (x/a)*(y/b)*(z/c)

print ans
