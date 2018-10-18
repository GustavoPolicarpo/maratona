# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Receita de Bolo
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2423

a, b, c = map ( int, raw_input().split() )
aa = a/2
bb = b/3
cc = c/5
print min(aa, min(bb, cc))
