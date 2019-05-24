/*
BOJ 17204 - 죽음의 게임
https://www.acmicpc.net/problem/17204

이미 방문한 정점이 나왔는데 k가 등장하지 않았다면 평생 도달하지 못함
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int vec[151], cnt;
bool visited[151];
int main() {
	int n, k, x;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		vec[i] = x;
	}
	for (int i = 0;; i = vec[i]) {
		if (visited[i]) break;
		visited[i] = true;
		if (i == k) return !printf("%d", cnt);
		cnt++;
	}
	printf("-1");

	return 0;
}