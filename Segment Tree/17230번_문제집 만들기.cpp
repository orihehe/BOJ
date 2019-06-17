/*
BOJ 17230 - 문제집 만들기
https://www.acmicpc.net/problem/17230

각 문제별로 그 문제를 풀기위한 최솟값~최댓값 을 구해둔다.
그리고나서 세그먼트 트리로 1번쿼리의 답을 구할 수 있다.

하지만 이는 서브태스크 3을 해결하기는 어려운데
우리는 어차피 세그먼트 트리로 구간의 최소, 최대를 구하니
문제별로 직접 연결된 문제의 최소, 최댓값만을 저장해두면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
set<int> sss[100001];
int mx[262144], mn[262144], a, b, cm, n;
void init(int idx, int s, int e) {
	if (s == e) {
		mx[idx] = *(--sss[s].end());
		mn[idx] = *sss[s].begin();
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
	mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
}
void update(int idx, int s, int e) {
	if (s > a || e < a) return;
	if (s == e) {
		if (cm == 2) sss[s].erase(b);
		else if (cm == 3) sss[s].insert(b);
		mx[idx] = *(--sss[s].end());
		mn[idx] = *sss[s].begin();
		return;
	}
	update(idx * 2, s, (s + e) / 2);
	update(idx * 2 + 1, (s + e) / 2 + 1, e);
	mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
	mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
}
pii gu(int idx, int s, int e, int l, int r) {
	if (e<l || s>r)return { n + 1,0 };
	if (l <= s && e <= r)
		return { mn[idx],mx[idx] };
	pii aa = gu(idx * 2, s, (s + e) / 2, l, r);
	pii bb = gu(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return { min(aa.first,bb.first),max(aa.second,bb.second) };
}
int main() {
	int m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) sss[i].insert(i);
	while (m--) {
		scanf("%d %d", &a, &b);
		sss[a].insert(b);
	}
	init(1, 1, n);
	while (q--) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm == 1) {
			pii tmp = gu(1, 1, n, a, b);
			if (tmp.first < a || tmp.second > b) printf("NO\n");
			else printf("YES\n");
		}
		else
			update(1, 1, n);
	}

	return 0;
}