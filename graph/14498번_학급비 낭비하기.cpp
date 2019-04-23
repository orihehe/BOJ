/*
BOJ 14498 - 학급비 낭비하기
https://www.acmicpc.net/problem/14498

고양이와 개(BOJ 3683)과 같은 문제
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[512], cat, dog;
int B[512];
bool visited[512];
int love[512], hate[512];
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
	int c, d, v, b, ans = 0, x, y;
	memset(B, -1, sizeof(B));
	scanf("%d %d %d", &c, &d, &v);
	for (int i = 0; i < v; i++) {
		scanf("%d %d %d", &x, &y, &b);
		if (b) {
			cat.push_back(i);
			love[i] = x;
			hate[i] = y;
		}
		else {
			dog.push_back(i);
			love[i] = y;
			hate[i] = x;
		}
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
	printf("%d", ans);

	return 0;
}