/*
BOJ 11971 - 속도 위반
https://www.acmicpc.net/problem/11971

배열에 차례로 i시점의 규정속도를 넣고
현재 속도와 비교하여 현재속도가 더 클 때 차이의 최댓값을 찾아 출력
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[101], ap;
int main() {
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		while (a--) {
			arr[ap++] = b;
		}
	}
	ap = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		while (a--) {
			if (b > arr[ap]) ans = max(ans, b - arr[ap]);
			ap++;
		}
	}
	printf("%d", ans);

	return 0;
}