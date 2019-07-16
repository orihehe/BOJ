/*
BOJ 15977 - 조화로운 행렬
https://www.acmicpc.net/problem/15977

1열 기준 정렬된 상태로 봐주면서 현재 2열 값 미만이고, 현재 3열 값 미만인 것들 중 최댓값을 찾는다.
이것을 2d세그먼트 트리로 해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int a, b, c;
} arr[200001];
vector<int> tree[524288];
vector<int> loc[524288];
info ud;
int n, m;
void init(int idx, int s, int e) {
	if (s == e) {
		loc[idx].push_back(arr[s].c);
		tree[idx].resize(2);
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	loc[idx].reserve(loc[idx * 2].size() + loc[idx * 2 + 1].size());
	for (int i : loc[idx * 2]) loc[idx].push_back(i);
	for (int i : loc[idx * 2 + 1]) loc[idx].push_back(i);
	sort(loc[idx].begin(), loc[idx].end());
	int sz = 1, lm = loc[idx].size();
	while (sz < lm) sz <<= 1;
	tree[idx].resize(sz * 2 + 1);
}
void update(int pidx, int k, int s, int e) {
	int x = 1;
	while (s != e) {
		x *= 2;
		if (k >(s + e) / 2) {
			s = (s + e) / 2 + 1;
			x++;
		}
		else e = (s + e) / 2;
	}
	tree[pidx][x] = ud.a;
	x /= 2;
	while (x) {
		tree[pidx][x] = max(tree[pidx][x * 2], tree[pidx][x * 2 + 1]);
		x /= 2;
	}
}
void up(int s, int e) {
	int x = 1;
	while (s != e) {
		x *= 2;
		if (ud.b > (s + e) / 2) {
			s = (s + e) / 2 + 1;
			x++;
		}
		else e = (s + e) / 2;
	}
	while (x) {
		int ii = lower_bound(loc[x].begin(), loc[x].end(), ud.c) - loc[x].begin();
		update(x, ii, 0, loc[x].size() - 1);
		x /= 2;
	}
}
int find(int pidx, int idx, int s, int e, int lm) {
	if (s > lm) return 0;
	if (e <= lm) return tree[pidx][idx];
	return max(find(pidx, idx * 2, s, (s + e) / 2, lm),
		find(pidx, idx * 2 + 1, (s + e) / 2 + 1, e, lm));
}
int f(int idx, int s, int e) {
	if (s > ud.b) return 0;
	if (e <= ud.b) {
		int ii = lower_bound(loc[idx].begin(), loc[idx].end(), ud.c) - loc[idx].begin();
		return find(idx, 1, 0, loc[idx].size() - 1, ii - 1);
	}
	return max(f(idx * 2, s, (s + e) / 2),
		f(idx * 2 + 1, (s + e) / 2 + 1, e));
}
int main() {
	int ans = 0;
	scanf("%d %d", &m, &n);
	if (m == 3)
		for (int i = 0; i < n; i++) scanf("%d", &arr[i].a);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i].b);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i].c);
	sort(arr, arr + n, [](info &aa, info &bb) {
		return aa.b < bb.b;
	});
	for (int i = 0; i < n; i++) arr[i].b = i;
	init(1, 0, n - 1);
	if (m == 3) {
		sort(arr, arr + n, [](info &aa, info &bb) {
			return aa.a < bb.a;
		});
	}
	for (int i = 0; i < n; i++) {
		ud = arr[i];
		int mx = f(1, 0, n - 1);
		ans = max(ans, mx + 1);
		ud.a = mx + 1;
		up(0, n - 1);
	}
	printf("%d", ans);

	return 0;
}