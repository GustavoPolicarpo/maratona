# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Pulo do Sapo
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2392

n, m = map( int, raw_input().split() )
v = [0]*(n+1)
for i in range(m):
    p, s = map( int, raw_input().split() )
    v[p] = 1
    pp = p
    while 42:
        pp = pp - s
        if pp < 1:
            break
        v[pp] = 1
    while 42:
        pp = pp + s
        if pp > n:
            break
        v[pp] = 1
for i in range(1, n+1):
    print v[i]

