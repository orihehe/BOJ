/*
BOJ 3683 - 고양이와 개
https://www.acmicpc.net/problem/3683

고양이를 좋아하는 사람, 개를 좋아하는 사람으로 나누어 이분 그래프를 만들 수 있다.
간선은 내가 좋아하는것을 싫어하거나, 내가 싫어하는 것을 좋아하는 사람끼리 이어준다.
그리고나서 이분매칭!
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[500], cat, dog;
int B[500];
bool visited[500];
int love[500], hate[500];
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
	int t, c, d, v, a, b, ans;
	char x, y;
	scanf("%d", &t);
	while (t--) {
		memset(B, -1, sizeof(B));
		cat.clear(), dog.clear();
		ans = 0;
		scanf("%d %d %d", &c, &d, &v);
		for (int i = 0; i < v; i++) {
			scanf(" %c%d %c%d", &x, &a, &y, &b);
			love[i] = a;
			hate[i] = b;
			vec[i].clear();
			if (x == 'C') {
				cat.push_back(i);
			}
			else dog.push_back(i);
		}
		for (int i : cat) {
			for (int j : dog) {
				if (hate[i] == love[j]) vec[i].push_back(j);
				else if (love[i] == hate[j]) vec[i].push_back(j);
			}
		}
		for (int i : cat) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ans++;
		}
		printf("%d\n", v - ans);
	}

	return 0;
}