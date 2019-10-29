/*
BOJ 5213 - 과외맨
https://www.acmicpc.net/problem/5213
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[501][1001], rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
int num[501][1001];
pii p[501][1001];
vector<int> ans;
int main() {
	int n, a, b, cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = i % 2; j < 2 * n - 1; j += 2) {
			scanf("%d %d", &a, &b);
			arr[i][j] = a, arr[i][j + 1] = b;
			num[i][j] = num[i][j + 1] = cnt++;
		}
	}
	memset(p, -1, sizeof(p));
	queue<pii> q;
	q.push({ 0,1 });
	p[0][0] = p[0][1] = { 0,0 };
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + rgo[i], nc = cur.second + cgo[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= 2 * n) continue;
			if (p[nr][nc].first != -1 || arr[nr][nc] != arr[cur.first][cur.second]) continue;
			p[nr][nc] = p[nr][nc + (nr % 2 == nc % 2 ? 1 : -1)] = cur;
			q.push({ nr,nc });
			q.push({ nr,nc + (nr % 2 == nc % 2 ? 1 : -1) });
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 2 * n - 1 - n % 2; j >= 0; j -= 2) {
			if (p[i][j].first == -1) continue;
			for (pii v = { i,j }; v.first != 0 || v.second != 0; v = p[v.first][v.second])
				ans.push_back(num[v.first][v.second]);
			break;
		}
		if (ans.size()) break;
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int v : ans) printf("%d ", v);

	return 0;
}