# Author: Gustavo Policarpo
# Name: A idade de Dona Mônica
# Level: 1
# Category: BEGINNER
# URL: https://www.beecrowd.com.br/judge/en/problems/view/3047

m = int(input())
a = [0]*3

for i in range(2):
	a[i] = int(input())

a[2] = m-a[0]-a[1]

a.sort()

print(a[2])
