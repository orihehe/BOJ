/*
BOJ 10319 - 좀비 아포칼립스
https://www.acmicpc.net/problem/10319

정점에 도착하는 시간별로 정점을 분리한다. (x,t)
정점 (x, 0) -> 정점 (x, 1) -> ... -> (x, s)로의 용량 INF 간선을 모두 추가해준다.
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
	int v, c, op;
	edg() {}
	edg(int a, int b, int o) {
		v = a, c = b, op = o;
	}
};
vector<edg> vec[101003];
int S = 101001, E = 101002, lv[101003], lst[101003];
void aeg(int a, int b, int c) {
	vec[a].push_back(edg(b, c, vec[b].size()));
	vec[b].push_back(edg(a, 0, vec[a].size() - 1));
}
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (edg i : vec[cur]) {
			if (lv[i.v] == -1 && i.c > 0) {
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
		if (lv[i.v] == lv[cur] + 1 && i.c > 0) {
			int df = dfs(i.v, min(flow, i.c));
			if (df > 0) {
				i.c -= df;
				vec[i.v][i.op].c += df;
				return df;
			}
		}
	}
	return 0;
}
int main() {
	int n, m, tt, x, srt, g, s, ans, fr, ba, p, t;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d %d %d", &n, &srt, &g, &s);
		ans = 0;
		srt--;
		s++;

		aeg(S, srt * s, g);
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &x);
			x--;
			aeg(x * s + s - 1, E, INF);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s - 1; j++) {
				aeg(i*s + j, i*s + j + 1, INF);
			}
		}

		scanf("%d", &m);
		while (m--) {
			scanf("%d %d %d %d", &fr, &ba, &p, &t);
			fr--, ba--;
			for (int i = 0; i < s; i++) {
				if (i + t > s - 1) break;
				aeg(fr * s + i, ba * s + i + t, p);
			}
		}

		while (bfs()) {
			memset(lst, 0, sizeof(lst));
			while (true) {
				int ret = dfs(S, INF);
				if (!ret) break;
				ans += ret;
			}
		}
		printf("%d\n", ans);

		for (int i = 0; i < n * s; i++) {
			vec[i].clear();
		}
		vec[S].clear();
		vec[E].clear();
	}

	return 0;
}