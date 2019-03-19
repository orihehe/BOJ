/*
BOJ 2453 - 부서 배치
https://www.acmicpc.net/problem/2453

팀을 배치 한 후 꼭 적이 되어야 하는 팀들의 인원수 차이를 벡터에 저장한다.
모든 부서를 배치해야하니 첫번째를 먼저 배치 후 차례로 나머지를 
양팔저울(BOJ 2629) 풀듯이 배치해준다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

/* 🐣🐥 */
int p[20001], sz[20001], n;
bool use[20001], po[2][10001];
vector<int> vec;
int getr(int a) {
	if (p[a] == a) return a;
	return p[a] = getr(p[a]);
}
void merge(int a, int b) {
	a = getr(a);
	b = getr(b);
	if (a == b) return;
	sz[b] += sz[a];
	p[a] = b;
}
void f_merge(int a, int b) {
	merge(a + n, b + n);
	merge(a, b);
}
void e_merge(int a, int b) {
	merge(a + n, b);
	merge(b + n, a);
}
bool is_true() {
	for (int i = 1; i <= n; i++)
		if (getr(i) == getr(i + n)) return false;
	return true;
}
int main() {
	int m, a, b, c;
	for (int t = 0; t < 5; t++) {
		scanf("%d %d", &n, &m);
		vec.clear();
		memset(po, false, sizeof(po));
		memset(use, false, sizeof(use));
		memset(sz, 0, sizeof(sz));
		for (int i = 1; i <= 2 * n; i++) {
			p[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			sz[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &c, &a, &b);
			if (c == 1) {
				f_merge(a, b);
			}
			else {
				e_merge(a, b);
			}
		}
		if (!is_true()) {
			printf("-1\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			int tmp = getr(i), etmp = getr(i + n);
			if (use[tmp]) continue;
			vec.push_back(abs(sz[tmp] - sz[etmp]));
			use[tmp] = use[etmp] = true;
		}
		po[0][vec[0]] = true;
		for (int v = 1; v < vec.size(); v++) {
			memset(po[v % 2], false, sizeof(po[v % 2]));
			for (int i = 10000 - vec[v]; i >= 0; i--) {
				if (po[(v + 1) % 2][i])
					po[v % 2][i + vec[v]] = true;
			}
			for (int i = 0; i <= 10000; i++) {
				if (po[(v + 1) % 2][i])
					po[v % 2][abs(i - vec[v])] = true;
			}
		}
		for (int i = 0; i <= 10000; i++) {
			if (po[(vec.size() - 1) % 2][i]) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}