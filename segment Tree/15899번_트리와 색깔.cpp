/*
BOJ 15899 - 트리와 색깔
https://www.acmicpc.net/problem/15899

정점 번호를 다시 지정하여 자식 노드를 세그로 관리할 수 있도록 만든다.
그리고 쿼리를 받아 색 번호가 작은 것부터 봐주면 쉽게 구할 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
pii arr[200001], q[200001];
vector<int> vec[200001];
int tree[524289], idx[200001], ch[200001], num;
bool cmp(pii &a, pii &b) {
	return a.second < b.second;
}
void update(int idx, int s, int e, int k) {
	if (k<s || k>e) return;
	tree[idx]++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int hap(int idx, int s, int e, int l, int r) {
	if (e<l || s>r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int dfs(int cur, int p) {
	int ret = 0;
	idx[cur] = ++num;
	for (int v : vec[cur]) {
		if (p != v) ret += dfs(v, cur);
	}
	ch[cur] = ret;
	return ret + 1;
}
int main() {
	int n, m, c, a, b, ap = 0, ans = 0;
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		q[i] = { a,b };
	}
	sort(q, q + m, cmp);
	dfs(1, 1);
	for (int i = 0; i < m; i++) {
		int cur = q[i].first;
		while (arr[ap].first <= q[i].second) {
			update(1, 1, n, idx[arr[ap++].second]);
		}
		ans = (ans + hap(1, 1, n, idx[cur], idx[cur] + ch[cur])) % mod;
	}
	printf("%d", ans);

	return 0;
}