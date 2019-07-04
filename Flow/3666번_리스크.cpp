/*
BOJ 3666 - 리스크
https://www.acmicpc.net/problem/3666

내 기지에 하나의 군대는 남아있어야 하니 S에서 내 기지로 군대 -1만큼 유량을 흘려준다.
그리고 정점을 보낼 수 있는 정점, 받는 정점으로 나눠 그 사이 용량을 1만큼 준다.
그렇게 하면 다른 곳에서 받았을 때 원래 있던 모든 군대를 보낼 수 있게 된다.

적 기지 근처의 분리된 두 정점에서 한 정점으로 가는 간선을 만들어주어
그 간선에서 E로 가는 용량을 mid로 두고 이분탐색을 해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
struct edg {
	int v, c, f, op;
	edg() {}
	edg(int a, int b, int o) {
		v = a, c = b, op = o, f = 0;
	}
};
const int S = 301, E = 302;
int arr[101], lv[303], lst[303];
char br[101][102];
bool ee[101];
vector<edg> vec[303];
bool bfs() {
	queue<int> q;
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (edg &i : vec[cur]) {
			if (lv[i.v] == -1 && i.c - i.f > 0) {
				lv[i.v] = lv[cur] + 1;
				q.push(i.v);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int flow) {
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int &k = lst[cur]; k < sz; k++) {
		edg &i = vec[cur][k];
		if (lv[i.v] == lv[cur] + 1 && i.c - i.f > 0) {
			int df = dfs(i.v, min(flow, i.c - i.f));
			if (df > 0) {
				i.f += df;
				vec[i.v][i.op].f -= df;
				return df;
			}
		}
	}
	return 0;
}
void aeg(int a, int b, int c) {
	vec[a].push_back(edg(b, c, vec[b].size()));
	vec[b].push_back(edg(a, 0, vec[a].size() - 1));
}
int main() {
	int t, n, ans, cnt;
	scanf("%d", &t);
	while (t--) {
		memset(ee, false, sizeof(ee));
		scanf("%d", &n);
		ans = 0, cnt = 0;
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		for (int i = 0; i < n; i++) scanf("%s", br[i]);
		for (int i = 0; i <= E; i++) vec[i].clear();
		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				for (int j = 0; j < n; j++)
					if (br[i][j] == 'Y' && arr[j] && !ee[j])
						ee[j] = true, cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				aeg(S, i + n, arr[i] - 1);
				aeg(i, i + n, 1);
			}
			for (int j = i + 1; j < n; j++) {
				if (br[i][j] == 'Y' && arr[i] && arr[j]) {
					aeg(j + n, i, INF);
					aeg(i + n, j, INF);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (ee[i]) {
				aeg(i, i + n * 2, INF);
				aeg(i + n, i + n * 2, INF);
				aeg(i + n * 2, E, 0);
			}
		}
		int l = 0, r = 10000, mid, tmp;
		while (l <= r) {
			mid = (l + r) / 2;
			for (int i = 0; i < n; i++) {
				if (ee[i]) {
					vec[i + n * 2].back().c = mid;
				}
			}
			tmp = 0;
			while (bfs()) {
				memset(lst, 0, sizeof(lst));
				while (true) {
					int ret = dfs(S, INF);
					if (!ret) break;
					tmp += ret;
				}
			}
			if (tmp == mid * cnt) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;

			for (int i = 0; i < 3 * n; i++) {
				for (edg &v : vec[i]) v.f = 0;
			}
			for (edg &v : vec[S]) v.f = 0;
			for (edg &e : vec[E]) e.f = 0;
		}
		printf("%d\n", ans + 1);
	}

	return 0;
}