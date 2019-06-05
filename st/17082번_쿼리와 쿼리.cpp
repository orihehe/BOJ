/*
BOJ 17082 - 쿼리와 쿼리
https://www.acmicpc.net/problem/17082

l과 r을 정렬 후 차례로 짝지어 주는 것이 가장 적은 구간을 포함하고 있을 수밖에 없다.
무조건 포함하는 부분을 세그로 관리
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[200001], l[200001], r[200001], tree[524289];
vector<int> vec;
priority_queue<int, vector<int>, greater<int>> pq;
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	if (s == e) {
		tree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int main() {
	int n, m, q, a, b;
	bool no = false;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < m; i++) scanf("%d", &l[i]);
	for (int i = 0; i < m; i++) scanf("%d", &r[i]);
	sort(l, l + m);
	sort(r, r + m);
	for (int i = 0; i < m; i++) {
		if (r[i] < l[i]) {
			no = true;
			break;
		}
	}
	int pp = 0;
	for (int i = 1; i <= n; i++) {
		while (pp < n && l[pp] == i) pq.push(r[pp++]);
		while (!pq.empty() && pq.top() < i) pq.pop();
		if (!pq.empty()) vec.push_back(i);
	}
	int sz = vec.size();
	for (int i = 0; i < sz; i++) {
		update(1, 0, sz - 1, i, arr[vec[i]]);
	}
	while (q--) {
		scanf("%d %d", &a, &b);
		if (no) {
			printf("1000000000\n");
			continue;
		}
		swap(arr[a], arr[b]);
		int idx = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
		if (idx < sz && vec[idx] == a) {
			update(1, 0, sz - 1, idx, arr[a]);
		}
		idx = lower_bound(vec.begin(), vec.end(), b) - vec.begin();
		if (idx < sz && vec[idx] == b) {
			update(1, 0, sz - 1, idx, arr[b]);
		}
		printf("%d\n", tree[1]);
	}

	return 0;
}