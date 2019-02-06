// BOJ 16427 (https://www.acmicpc.net/problem/16427)
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x, maxV = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		maxV = max(maxV, (x*m + 999) / 1000);
	}
	printf("%d", maxV);
}