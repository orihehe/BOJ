/*
BOJ 11668 - 파이프 청소
https://www.acmicpc.net/problem/11668

벡터의 외적으로 두 선분에 교차점이 존재하는지 확인 후 교차한다면 xor(enemy merge)
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii one[1001];
struct info {
	int x1, y1, x2, y2, fr;
} arr[1001];
int m, p[2001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
bool isValid() {
	for (int i = 1; i <= m; i++) if (find(i) == find(i + m)) return false;
	return true;
}
int vt(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}
int main() {
	int n, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &one[i].first, &one[i].second);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = { one[a].first,one[a].second, b, c, a };
	}
	for (int i = 1; i <= m * 2; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (arr[i].fr == arr[j].fr) continue;
			b = vt(arr[i].x2 - arr[i].x1, arr[i].y2 - arr[i].y1,
				arr[j].x1 - arr[i].x2, arr[j].y1 - arr[i].y2);
			c = vt(arr[i].x2 - arr[i].x1, arr[i].y2 - arr[i].y1,
				arr[j].x2 - arr[i].x2, arr[j].y2 - arr[i].y2);
			if (1LL * b*c > 0) continue;
			b = vt(arr[j].x2 - arr[j].x1, arr[j].y2 - arr[j].y1,
				arr[i].x1 - arr[j].x2, arr[i].y1 - arr[j].y2);
			c = vt(arr[j].x2 - arr[j].x1, arr[j].y2 - arr[j].y1,
				arr[i].x2 - arr[j].x2, arr[i].y2 - arr[j].y2);
			if (1LL * b*c > 0) continue;
			merge(i, j + m);
			merge(j, i + m);
		}
	}
	printf("%s", isValid() ? "possible" : "impossible");

	return 0;
}