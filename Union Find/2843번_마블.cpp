/*
BOJ 2843 - 마블
https://www.acmicpc.net/problem/2843

쿼리를 모두 저장해두고 끊겨진 애들 외의 것들을 merge해준다.
쿼리를 뒤에서 부터 실행해주면서 끊는 쿼리가 나오면 이어준다.
CIKLUS는 현재 정점이 가르키는 방향을 find했을 때 본인이 나오면 무한히 이동하니
p[cur]에 MAX값을저장한다.
*/
#include <cstdio>
#include <vector>
#define pii pair<int,int>
#define MAX 300001
using namespace std;

/* 🐣🐥 */
int p[300001];
int dir[300001], ans[300001];
bool use[300001];
vector<pii> vec;
int find(int a) {
	if (p[a] == MAX) return MAX;
	if (a == p[a])return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	p[a] = b;
}
int main() {
	int n, q, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dir[i]);
		p[i] = i;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		if (a == 2) {
			use[b] = true;
		}
		vec.push_back({ a,b });
	}
	for (int i = 1; i <= n; i++) {
		if (!use[i] && dir[i] != 0) {
			if (find(dir[i]) == i) p[i] = MAX;
			else merge(i, dir[i]);
		}
	}
	for (int i = q - 1; i >= 0; i--) {
		int cur = vec[i].second;
		if (vec[i].first == 1) {
			if (find(cur) != MAX) ans[i] = find(cur);
			else ans[i] = -1;
		}
		else{
			if (find(dir[cur]) == cur) p[cur] = MAX;
			else merge(cur, dir[cur]);
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i] == -1) printf("CIKLUS\n");
		else if (ans[i] != 0) printf("%d\n", ans[i]);
	}

	return 0;
}