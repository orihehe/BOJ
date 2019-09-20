'''
BOJ 9020 - 골드바흐의 추측
https://www.acmicpc.net/problem/9020
'''
from sys import stdin
input = stdin.readline

''' 🐣🐥 '''
sosu = [True]*10001
lst = []
t=int(input())
for i in range(2, 10001):
        if not sosu[i]: continue
        lst.append(i)
        for j in range(i, 10001):
            if i*j>=10001: break
            sosu[i*j] = False
while t:
    t-=1
    x = int(input())
    ans = [0,0]
    lm = len(lst)
    for i in range(0, lm):
        if(x-lst[i] < lst[i]): break
        if(sosu[x-lst[i]]):
            ans[0],ans[1] = [lst[i],x-lst[i]]
    print(ans[0],ans[1])