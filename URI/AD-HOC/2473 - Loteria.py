# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Loteria
# Nível: 1
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2473

v = [0]*6;
v = map (int, raw_input().split() )

n = [0]*6;
n = map (int, raw_input().split() )

ans = 0
for i in range(6):
    for j in range(6):
        if(v[j] == n[i]):
            ans = ans+1

if ans < 3:
    print "azar"
if ans == 3:
    print "terno"
if ans == 4:
    print "quadra"
if ans == 5:
    print "quina"
if ans == 6:
    print "sena"

