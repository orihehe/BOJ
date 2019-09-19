'''
BOJ 7785 - 회사에 있는 사람
https://www.acmicpc.net/problem/7785
'''
from sys import stdin
input = stdin.readline
''' 🐣🐥 '''

n = int(input())
sss = set()
for i in range(n):
    a,b = map(str,input().split())
    if b=='enter':
        sss.add(a)
    else:
        sss.remove(a)
ans = sorted(sss, reverse=True)
for i in ans:
    print(i)