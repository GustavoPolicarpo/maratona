# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Pedágio
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2377

n, m = raw_input().split()
n = int(n)
m = int(m)
k, p = raw_input().split()
k = int(k)
p = int(p)
ans = n*k + n/m*p
print ans
    

