/*
BOJ 16567 - 바이너리 왕국
https://www.acmicpc.net/problem/16567

다른 두 집합이 합쳐지면 -1, 새 집합이 생기면(양쪽 비어있으면) +1
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[1000001], p[1000001], sum, mn;
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int n, m, cm, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		p[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] && arr[i + 1]) merge(i, i + 1);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1 && find(i) == i) sum++;
	}
	while (m--) {
		scanf("%d", &cm);
		if (!cm) {
			printf("%d\n", sum - mn);
		}
		else {
			scanf("%d", &x);
			x--;
			if (!arr[x]) {
				if (arr[x - 1] && arr[x + 1]) {
					merge(x - 1, x), merge(x, x + 1);
					mn++;
				}
				else if (arr[x - 1]) {
					merge(x - 1, x);
				}
				else if (arr[x + 1]) merge(x + 1, x);
				else sum++;
			}
			arr[x] = 1;
		}
	}

	return 0;
}