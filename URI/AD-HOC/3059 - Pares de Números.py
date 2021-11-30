# Author: Gustavo Policarpo
# Name: Pares de Números
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/3059

N, I, F = map(int, input().split())
arr = input().split()

ans = 0
for i in range(N):
    for j in range(i+1, N):
        val = int(arr[i]) + int(arr[j])
        if val >= I and val <= F:
            ans = ans + 1
print(ans)
