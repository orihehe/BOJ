/*
���� 1671 ����� ����Ļ� (https://www.acmicpc.net/problem/1671)
���� ǮĿ�� �˰������� Ǯ����. ��Ƴ��� �� �ִ� ����� �ּڰ��� ���ϱ� ���� �ִ��� ���� ��ƸԴ� ���� ���ߴ�.
ó���� ���, ������� ���� ������ �ʰ� Ǯ���ٰ� ���� ������ �ʾ� �ٽ� �����غ���
c-f�� 0-(����) �� ������ �� ���� ������. �׷��� �ִ������� ������ �ʾҴ�.
�� �ɷ�ġ�� ���� ���� �ε����� ���� ���̸� ������ ��������. �׷��� ������ ���θ� �Ծ������.
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
		// ������ �ִ� 1���� �����Ƿ� ++,--
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