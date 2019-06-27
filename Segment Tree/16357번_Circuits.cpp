/*
BOJ 16357 - Circuits
https://www.acmicpc.net/problem/16357

직사각형의 높이 선분만 봐준다.
각 선분구간을 세그먼트트리에 레이지로 업데이트 해두고,
시작지점과 끝지점에서만 값의 변화가 있으므로 그 점들만 봐주면서
선분이 현재 범위에 없다면 -1로 구간 업데이트
거기서 최댓값 + 현재 윗선분이 지나는 사각형 개수의 최댓값을 찾아준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec;
pii arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;
int n, tree[524288], lazy[524288];
void update(int idx, int s, int e, int l, int r, int val) {
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		lazy[idx] += val;
		return;
	}
	update(idx * 2, s, (e + s) / 2, l, r, val);
	update(idx * 2 + 1, (e + s) / 2 + 1, e, l, r, val);
	tree[idx] = max(tree[idx * 2] + lazy[idx * 2], 
		tree[idx * 2 + 1] + lazy[idx * 2 + 1]);
}
int main() {
	int a, b, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%*d %d %*d %d", &a, &b);
		arr[i] = { b,a };
		vec.push_back(a);
		vec.push_back(b);
	}
	sort(arr, arr + n);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int sz = vec.size(), ap = 0;
	for (int i = 0; i < n; i++) {
		int ii = lower_bound(vec.begin(), vec.end(), arr[i].first) - vec.begin();
		int jj = lower_bound(vec.begin(), vec.end(), arr[i].second) - vec.begin();
		update(1, 0, sz - 1, ii, jj, 1);
	}
	for (int i = 0; i < sz; i++) {
		while (arr[ap].first == vec[i]) {
			pq.push(arr[ap].second);
			int ii = lower_bound(vec.begin(), vec.end(), arr[ap].first) - vec.begin();
			int jj = lower_bound(vec.begin(), vec.end(), arr[ap].second) - vec.begin();
			update(1, 0, sz - 1, ii, jj, -1);
			ap++;
		}
		while (pq.top() < vec[i]) {
			pq.pop();
		}
		if (!pq.empty()) {
			ans = max(ans, (int)pq.size() + tree[1]);
		}
	}
	printf("%d", ans);

	return 0;
}