# Author: Gustavo Policarpo
# Name: Parcelamento Sem Juros
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/3060

V = int(input())
P = int(input())

mr = V%P
tt = V/P

for i in range(P):
    if i < mr:
        print(int(V/P) + 1)
    else:
        print(int(V/P))
