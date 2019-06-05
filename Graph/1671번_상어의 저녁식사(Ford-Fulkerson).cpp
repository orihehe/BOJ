/*
백준 1671 상어의 저녁식사 (https://www.acmicpc.net/problem/1671)
포드 풀커슨 알고리즘으로 풀었다. 살아남을 수 있는 상어의 최솟값을 구하기 위해 최대한 많이 잡아먹는 값을 구했다.
처음에 상어, 먹힐상어 따로 나누지 않고 풀었다가 답이 나오지 않아 다시 생각해보니
c-f가 0-(음수) 인 것으로 갈 수가 없었다. 그래서 최대유량이 나오지 않았다.
또 능력치가 같은 상어는 인덱스가 빠른 아이만 간선을 만들어줬다. 그렇지 않으면 서로를 먹어버린다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 2000000001
using namespace std;

struct shark {
	int size, speed, know;
};
bool operator < (shark& a, shark& b) {
	return a.size < b.size || a.speed < b.speed || a.know < b.know;
}
bool operator == (shark& a, shark& b) {
	return a.size == b.size && a.speed == b.speed && a.know == b.know;
}
int visited[102];
int f[102][102], c[102][102], n, S = 0, E;
shark sh[51];
vector<int> vec[102];
bool dfs(int cur) {
	if (cur == E) return true;
	for (int &v : vec[cur]) {
		if (visited[v] != -1 || c[cur][v]-f[cur][v] <=0) continue;
		visited[v] = cur;
		if (dfs(v)) return true;
	}
	return false;
}

int main() {
	int a,b,w, total=0;
	scanf("%d", &n);
	E = 2*n + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &w);
		sh[i] = { a,b,w };
	}
	for (int i = 1; i <= n; i++) {
		vec[S].push_back(i);
		vec[i].push_back(S);
		c[S][i] = 2;
		for (int j = 1; j <= n; j++) {
			if (i == j || sh[i]<sh[j]) continue;
			if (sh[i] == sh[j] && j < i) continue;
			vec[i].push_back(j+50);
			vec[j+50].push_back(i);
			c[i][j+50] = 1;
		}
		vec[E].push_back(i+50);
		vec[i+50].push_back(E);
		c[i+50][E] = 1;
	}
	memset(visited, -1, sizeof(visited));
	while (dfs(S)) {
		// 유량은 최대 1까지 나오므로 ++,--
		for (int i = E; i != S; i = visited[i]) {
			f[visited[i]][i]++;
			f[i][visited[i]]--;
		}
		total++;
		memset(visited, -1, sizeof(visited));
	}
	printf("%d", n-total);

	return 0;
}