/*
BOJ 17132 - 두더지가 정보섬에 올라온 이유
https://www.acmicpc.net/problem/17132

만족도가 큰 간선부터 보면, 현재의 만족도를 얻을 수 있다.
또한 현재 간선의 만족도를 얻는 경로의 수는 v1집합의 노드 수 * v2집합의 노드 수가 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct node {
	int v1, v2, w;
	bool operator < (const node &a) const {
		return w > a.w;
	}
};
vector<node> vec;
int p[100001], sz[100001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}
int main() {
	int n, x, y, w;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &x, &y, &w);
		vec.push_back({ x, y, w });
	}
	sort(vec.begin(), vec.end());
	for (node &v : vec) {
		ans += 1LL * v.w * sz[find(v.v1)] * sz[find(v.v2)];
		merge(v.v1, v.v2);
	}
	printf("%lld", ans);

	return 0;
}