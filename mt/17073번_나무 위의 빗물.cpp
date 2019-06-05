/*
BOJ 17073 - 나무 위의 빗물
https://www.acmicpc.net/problem/17073
*/
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec[500001];
ll w;
int n, a, b, lf;
double sum;
void dfs(int cur, int p, ll dw) {
	int ch;
	if (cur != 1) ch = vec[cur].size() - 1;
	else ch = vec[cur].size();
	for (int v : vec[cur]) {
		if (p == v) continue;
		dfs(v, cur, dw*ch);
	}
	if (ch == 0) {
		lf++;
		sum += (double)w / (double)dw;
	}
}
int main() {
	scanf("%d %lld", &n, &w);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1, 1);
	printf("%lf", sum / lf);

	return 0;
}