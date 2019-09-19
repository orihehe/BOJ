'''
BOJ 10826 - 피보나치 수 4
https://www.acmicpc.net/problem/10826
'''
from sys import stdin
input = stdin.readline
''' 🐣🐥 '''

arr = [0]*10001
arr[0], arr[1] = 0, 1
n=int(input())
for i in range(2, n+1):
    arr[i]=arr[i-1]+arr[i-2]
print(arr[n])