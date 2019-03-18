/*
BOJ 15511 - League of Overwatch at Moloco (Hard)
https://www.acmicpc.net/problem/15511

a의 적들이 벡터에 모두 저장되어있으니 그 적들끼리 merge해준다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> arr[1000001];
int p[1000001];
int getr(int a) {
	if (p[a] == a) return a;
	return p[a] = getr(p[a]);
}
void merge(int a, int b) {
	a = getr(a);
	b = getr(b);
	p[b] = a;
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < arr[i].size(); j++) {
			// i의 원수들이 같은 팀이라면 모순
			if (getr(arr[i][j]) == getr(i)) return !printf("IMPOSSIBLE");
			merge(arr[i][j], arr[i][j - 1]);
		}
	}
	printf("POSSIBLE");

	return 0;
}