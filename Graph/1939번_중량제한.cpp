/*
BOJ 1939 (https://www.acmicpc.net/problem/1939)

크루스칼 알고리즘 사용, 가중치가 큰 간선들을 먼저 선택한다.
두 공장이 이어졌을 때 반복문을 나오고, 마지막에 사용한 간선의 가중치를 출력해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct edge {
	int a, b, v;
};
bool operator < (edge& e1, edge& e2) {
	return e1.v > e2.v;
}
vector<edge> vec;
int parent[10001];
int n, m, a, b, c, from, to;
int find_root(int v1) {
	if (parent[v1] == v1) return v1;
	return parent[v1] = find_root(parent[v1]);
}
bool same_set(int v1, int v2) {
	return find_root(v1) == find_root(v2);
}
void merge(int v1, int v2) {
	v1 = find_root(v1), v2 = find_root(v2);
	if (v1 == v2) return;
	parent[v1] = v2;
}
int kru() {
	int cur;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (edge &e : vec) {
		if (same_set(from, to)) break;
		if (same_set(e.a, e.b)) continue;
		cur = e.v;
		merge(e.a, e.b);
	}
	return cur;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec.push_back({ a,b,c });
	}
	sort(vec.begin(), vec.end());
	scanf("%d %d", &from, &to);
	printf("%d", kru());

	return 0;
}