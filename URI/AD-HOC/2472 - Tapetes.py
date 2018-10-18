# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Tapetes
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2472

n, m = map (int, raw_input().split() )
ans = (n-m+1)*(n-m+1) + m-1
print ans
