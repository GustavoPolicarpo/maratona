# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Sedex
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2375

n = input()
a, b, c = map( int, raw_input().split() )
if (n <= a) & (n <= b) & (n <= c):
    print "S"
else:
    print "N"

