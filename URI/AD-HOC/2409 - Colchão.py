# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Colchão
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2409

v = [0]*3
v = map( int, raw_input().split() )
v.sort()
h, l = map( int, raw_input().split() )

if ( min(h, l) >= v[0] ) and ( max(h, l) >= v[1] ) :
    print "S"
else :
    print "N"
