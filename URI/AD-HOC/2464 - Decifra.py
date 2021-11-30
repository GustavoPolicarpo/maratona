# Author: Gustavo Policarpo
# Name: Decifra
# Level: 3
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2464

crip = raw_input()
text = raw_input()
out = ""

tamanho = len(text)
for i in range(tamanho):
    p = ord(text[i])-ord('a')
    out = out+crip[p]
    
print out
