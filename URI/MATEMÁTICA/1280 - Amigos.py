# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Amigos
# Nível: 6
# Categoria: MATEMÁTICA
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1280


import sys
sys.setrecursionlimit(3000)

def ack2(M, N):
   return (N + 1)   if M == 0 else (
          (N + 2)   if M == 1 else (
          (2*N + 3) if M == 2 else (
          (8*(2**N - 1) + 5) if M == 3 else (
          ack2(M-1, 1) if N == 0 else ack2(M-1, ack2(M, N-1))))))


t = input()
for i in range(t):
        n, m = map( int, raw_input().split() )
        print(ack2(n, m))

