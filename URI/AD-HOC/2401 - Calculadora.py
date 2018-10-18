# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Calculadora
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2401

n = input()

num = 1
dem = 1

primo = [0]*4
primo = [2, 3, 5, 7]

for i in range(n):
    aux = raw_input()
    if aux[2]=='*' :
        num = num*(ord(aux[0])-48)
    else :
        dem = dem*(ord(aux[0])-48)

    for j in range(4):
        if (num%primo[j] == 0) and (dem%primo[j] == 0) :
            num = num/primo[j]
            dem = dem/primo[j]
    
print num/dem
