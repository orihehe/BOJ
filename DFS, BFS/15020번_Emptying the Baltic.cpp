/*
BOJ 15020 - Emptying the Baltic
https://www.acmicpc.net/problem/15020

원하는 지점에서부터 물을 채워나간다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[502][502];
int rgo[8] = { 1,1,1,0,0,-1,-1,-1 }, cgo[8] = { -1,0,1,-1,1,-1,0,1 };
bool visited[502][502];
struct info {
	int val, r, c;
	bool operator <(const info &a) const {
		return val > a.val;
	}
};
priority_queue<info> pq;
int main() {
	int n, m, r, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > 0) arr[i][j] = 0;
		}
	scanf("%d %d", &r, &c);
	pq.push({ arr[r][c],r,c });
	int cnt = 0, last = arr[r][c];
	visited[r][c] = true;
	ll ans = 0;
	int vv = arr[r][c], cc = 0;
	while (true) {
		cc = 0;
		while (!pq.empty() && vv >= pq.top().val) {
			info cur = pq.top();
			pq.pop();
			if (cur.val == 0) continue;
			cc++;
			for (int i = 0; i < 8; i++) {
				int nr = cur.r + rgo[i], nc = cur.c + cgo[i];
				if (nr < 0 || nc < 0 || nr > n + 1 || nc > m + 1 || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				pq.push({ arr[nr][nc],nr,nc });
			}
		}
		ans += 1LL * cnt * (vv - last);
		cnt += cc;
		last = vv;
		if (pq.empty()) break;
		else
			vv = pq.top().val;
	}

	printf("%lld", ans);

	return 0;
}