# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Elevador
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2378

n, m = raw_input().split()
n = int(n)
m = int(m)
yep = 0
total = 0
for i in range(n):
    s, e = raw_input().split()
    s = int(s)
    e = int(e)
    total += e
    total -=s
    if total > m:
        yep = 1
if yep == 1:
    print "S"
else:
    print "N"
    

