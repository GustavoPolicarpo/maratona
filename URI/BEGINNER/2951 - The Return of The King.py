# Author: Gustavo Policarpo
# Name: The Return of The King
# Level: 3
# Category: BEGINNER
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2951

a = {str : int}

n, g = input().split()
n = int(n)
g = int(g)

for i in range(n):
    c, v = input().split()
    c = c
    v = int(v)
    a[c] = v

x = int(input())

arr = input().split()
sz = len(arr)
tt = 0
for i in range(sz):
    tt = tt + a[arr[i]]

print(tt)

if tt >= g:
    print('You shall pass!')
else:
    print('My precioooous')
