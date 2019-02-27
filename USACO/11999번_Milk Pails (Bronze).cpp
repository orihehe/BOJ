/*
BOJ 11999 (https://www.acmicpc.net/problem/11999)
a와 b로 만들수 있는 x를 모두 저장해준다. 완탐!
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool dp[1001];
int a, b, x;
void go(int cur) {
	if (cur > x) return;
	if (dp[cur])return;
	dp[cur] = true;
	go(cur + a);
	go(cur + b);
}
int main() {
	scanf("%d %d %d", &a, &b, &x);
	go(0);
	for (int i = x; i >= 0; i--) {
		if (dp[i]) return !printf("%d", i);
	}

	return 0;
}