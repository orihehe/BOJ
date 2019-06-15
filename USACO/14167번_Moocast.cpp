/*
BOJ 14167 - Moocast
https://www.acmicpc.net/problem/14167

크루스칼
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct edge {
	int v1, v2, val;
	bool operator<(const edge &a) const {
		return val < a.val;
	}
};
pii arr[1001];
vector<edge> vec;
int n, p[1001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int kru(){
	sort(vec.begin(), vec.end());
	int cnt = 0;
	for (edge v : vec) {
		if (find(v.v1) == find(v.v2)) continue;
		cnt++;
		merge(v.v1, v.v2);
		if (cnt == n - 1) return v.val;
	}
}
int main() {
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { a,b };
		p[i] = i;
		for (int j = 0; j < i; j++) {
			int aa = a - arr[j].first, bb = b - arr[j].second;
			vec.push_back({ i,j,aa*aa + bb * bb });
		}
	}
	printf("%d", kru());

	return 0;
}