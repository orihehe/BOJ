/*
BOJ 5398 - 틀렸습니다
https://www.acmicpc.net/problem/5398

가로, 세로 그룹끼린 간선이 없으니 이분그래프를 만들 수 있고,
한 단어를 사용함으로 다른 사용 못하는 단어가 생겨나면 그것으로 간선을 이어주고
이분매칭을 돌려 그 매칭수를 빼준다. (최소 버택스 커버)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
pair<char, int> b[1001][1001];
vector<int> vec[501];
bool visited[501];
int B[501];
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int t, n, m, r, c, len, cnt = 0;
	char st[1001];
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %s", &c, &r, st);
			len = strlen(st);
			for (int j = 0; j < len; j++) {
				if (c > 1000) break;
				b[r][c++] = { st[j],i };
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %s", &c, &r, st);
			len = strlen(st);
			for (int j = 0; j < len; j++) {
				if (r > 1000) break;
				if (b[r][c].first != 0 && b[r][c].first != st[j]) {
					vec[i].push_back(b[r][c].second);
				}
				r++;
			}
		}
		memset(B, -1, sizeof(B));
		for (int i = 0; i < m; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) cnt++;
		}
		printf("%d\n", n + m - cnt);
		memset(b, 0, sizeof(b));
		for (int i = 0; i < m; i++)
			vec[i].clear();
	}

	return 0;
}