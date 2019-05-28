/*
BOJ 11281 - 2-SAT - 4
https://www.acmicpc.net/problem/11281

scc 과정에서 새로 부여받는 번호가 큰 순으로 위상정렬상 앞에 위치
번호가 큰 순으로 방문체크를 하여 처음 방문한 노드라면 0, 아니라면 1로 출력해준다.

이 방식이 왜 유효한지가 잘 감이 안 오는데, 
같은 scc안에 0과 1이 섞여있을 경우 안 될거라 생각된다.
x가 0(방문하지 않은 노드), y가 1(이미 방문한 노드) 이고 같은 scc 내에 존재한다면,
y->x인 간선이 하나는 있을 것이고, 이것은 x'->y'인 간선 또한 존재한다는 뜻이다.
그렇게 되면 x'의 번호가 더 크게되고, y'를 방문했는데 x'를 방문하지 않은 게 불가능하니 모순이다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[20001];
stack<int> sta, ast;
int n, num[20001], cnt, scnt;
bool ans, use[20001];
pii arr[20001];
int getOP(int a) {
	return a + (a > n ? -n : n);
}
bool cmp(pii a, pii b) {
	return a.first > b.first;
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!arr[v].first) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			arr[nx].first = scnt;
			if (arr[nx].first == arr[getOP(nx)].first) ans = true;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n; 
		vec[getOP(a)].push_back(b);
		vec[getOP(b)].push_back(a);
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!num[i]) dfs(i);
		arr[i].second = i;
	}
	sort(arr + 1, arr + 1 + 2 * n, cmp);
	for (int i = 1; i <= 2 * n; i++) {
		if (!use[getOP(arr[i].second)]) use[arr[i].second] = true;
	}

	if (ans) return !printf("0");
	printf("1\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", !use[i]);
	}

	return 0;
}