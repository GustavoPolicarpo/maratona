# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Decifra
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2464

crip = raw_input()
text = raw_input()
out = ""

tamanho = len(text)
for i in range(tamanho):
    p = ord(text[i])-ord('a')
    out = out+crip[p]
    
print out
