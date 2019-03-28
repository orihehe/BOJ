/*
BOJ 17024 - Grass Planting
https://www.acmicpc.net/problem/17024

필요한 색의 개수는 한 노드와 이어진 노드 개수임
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int vec[100001];
int main() {
	int n, a, b, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a]++;
		vec[b]++;
	}
	for (int i = 1; i < n; i++) {
		ans = max(vec[i] + 1, ans);
	}
	printf("%d", ans);

	return 0;
}