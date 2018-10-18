# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Linguagem
# Nível: 2
# Categoria: MATEMÁTICA
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1623

while(7):
    n, m = raw_input().split()
    n = int(n)
    m = int(m)

    if n==0:
        break
    t = input()

    fat=n-m+1
    if fat>800:
        print "descartado"

    else:
        ans=1
        for i in range(2, fat+1):
            ans = ans*i
        if ans>t:
            print "descartado"
        else:
            print ans

