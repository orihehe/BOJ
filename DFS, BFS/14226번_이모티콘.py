'''
BOJ 14226 - 이모티콘
https://www.acmicpc.net/problem/14226
'''
from sys import stdin
from collections import deque
input = stdin.readline
''' 🐣🐥 '''

MAX = 2001
n = int(input())
dist = [[-1]*MAX for i in range(MAX)]
dist[1][0]=0
q = deque()
q.append((1,0))
ans=0
while q:
    cur = q.popleft()
    if cur[0]==n:
       ans =dist[cur[0]][cur[1]]
       break
    if cur[0]+cur[1] < MAX and dist[cur[0]+cur[1]][cur[1]]==-1:
        dist[cur[0]+cur[1]][cur[1]] = dist[cur[0]][cur[1]]+1
        q.append((cur[0]+cur[1],cur[1]))
    if cur[0]-1 > 0 and dist[cur[0]-1][cur[1]]==-1:
        dist[cur[0]-1][cur[1]] = dist[cur[0]][cur[1]]+1
        q.append((cur[0]-1,cur[1]))
    if dist[cur[0]][cur[0]]==-1:
        dist[cur[0]][cur[0]]=dist[cur[0]][cur[1]]+1
        q.append((cur[0],cur[0]))
print(ans)