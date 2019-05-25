/*
BOJ 14466 - 소가 길을 건너간 이유 6
https://www.acmicpc.net/problem/14466

길 정보를 set에 저장해두고, 길을 건너지 않아도 되는 쌍을 묶어 계산해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
bool visited[101][101];
set<pair<pii, pii>> sss;
vector<int> vec;
int n, cnt, rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 }, bb[101][101];
void dfs(int r, int c) {
	visited[r][c] = true;
	cnt += bb[r][c];
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 1 || nc < 1 || nr > n || nc > n || visited[nr][nc]) continue;
		pii a = { r,c }, b = { nr,nc };
		if (a > b)swap(a, b);
		if (sss.find({ a,b }) != sss.end()) continue;
		dfs(nr, nc);
	}
}
int main() {
	int k, r, sum = 0, x, y;
	ll ans = 0;
	pii a, b;
	scanf("%d %d %d", &n, &k, &r);
	while (r--) {
		scanf("%d %d %d %d", &a.first, &a.second, &b.first, &b.second);
		if (a > b) swap(a, b);
		sss.insert({ a,b });
	}
	while (k--) {
		scanf("%d %d", &x, &y);
		bb[x][y]++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				vec.push_back(cnt);
				sum += cnt;
			}

	for (int v : vec) {
		sum -= v;
		ans += 1LL * v*sum;
	}
	printf("%lld", ans);

	return 0;
}