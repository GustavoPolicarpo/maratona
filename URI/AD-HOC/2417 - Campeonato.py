# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Campeonato
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2417

a, b, c, d, e, f = map(int, raw_input().split() )

pta = a*3 + b
ptb = d*3 + e

if pta != ptb :
    if pta > ptb :
        print "C"
    else :
        print "F"
else:
    if c > f :
        print "C"
    elif f > c :
        print "F"
    else :
        print "="
