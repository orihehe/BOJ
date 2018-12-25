/*
백준 1964 (https://www.acmicpc.net/problem/1964)
2번째부턴 3n+1씩 점의 개수가 늘어남.
처음엔 O(N) 으로 풀었다. 40ms
0ms 풀이가 있어서 등차수열로 다시 풀었다. O(1)
*/
#include <cstdio>
#define mod 45678
using namespace std;

int main() {
	int n, sum = 5;
	scanf("%d", &n); 
	/*for (int i = 2; i <= n; i++) {
		sum = (sum + 3 * i + 1) % mod;
	}
	printf("%d", sum);*/
	n--;
	printf("%d", (5 + (3 * n*n + 11 * n) / 2) % mod);

	return 0;
}