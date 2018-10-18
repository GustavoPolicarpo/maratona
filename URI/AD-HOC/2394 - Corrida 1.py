# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Corrida 1
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2394

n, m = map (int, raw_input().split() )
v = [0]*(n)
for i in range(n):
    tempo = 0
    r = [0]*(m)
    r = map (int, raw_input().split() )
    for j in range(m):
        tempo = tempo+r[j]
    v[i]=tempo
mt = v[0]
ans = 1
for i in range(1, n):
    if(mt > v[i]):
        mt = v[i]
        ans = i+1
print ans


