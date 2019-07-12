/*
BOJ 13432 - 좋은 부분 문자열
https://www.acmicpc.net/problem/13432

LCP값이 큰 것부터 유니온 파인드로 관리.
그 값에서 가장 작은 인덱스와 가장 큰 인덱스의 차이가 문자열 길이 이상이라면
좋은 부분 문자열로 처리해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
char st[100001];
int n, pos[100001], lcp[100001], sa[100001], tmp[100001], cnt[100001];
int p[100001], mx[100001], mn[100001], ii[100001];
bool use[100001];
priority_queue<pii> pq;
vector<int> vec;
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (a > b)swap(a, b);
	p[b] = a;
	mx[a] = max(mx[a], mx[b]);
	mn[a] = min(mn[a], mn[b]);
	ii[a] = ii[b];
}
void LCP() {
	for (int i = 0; i < n; i++) pos[i]--;
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (!pos[i]) continue;
		for (int j = sa[pos[i] - 1]; st[i + k] == st[j + k]; k++);
		lcp[pos[i]] = k;
	}
}
void SA() {
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = st[i];
	}
	int d = 1, z = 0;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cnt[pos[min(i + d, n)]]++;
		for (int i = 1; i <= max(n, 128); i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) tmp[--cnt[pos[min(i + d, n)]]] = i;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cnt[pos[i]]++;
		for (int i = 1; i <= max(n, 128); i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--cnt[pos[tmp[i]]]] = tmp[i];

		if (z == n) break;
		z = 1, tmp[sa[0]] = 1;
		for (int i = 1; i < n; i++) {
			if (pos[sa[i]] != pos[sa[i - 1]] || pos[sa[i] + d] != pos[sa[i - 1] + d]) z++;
			tmp[sa[i]] = z;
		}
		memcpy(pos, tmp, sizeof(pos));
		d *= 2;
	}
	LCP();
}
int main() {
	ll ans = 0;
	scanf("%s", st);
	n = strlen(st);
	SA();
	for (int i = 0; i < n; i++) {
		p[i] = i, ii[i] = i;
		if (lcp[i])
			pq.push({ lcp[i],i });
		mx[i] = mn[i] = sa[i];
	}
	while (!pq.empty()) {
		pii cur = pq.top();
		vec.clear();
		while (!pq.empty() && pq.top().first == cur.first) {
			vec.push_back(pq.top().second);
			pq.pop();
		}
		int sz = vec.size();
		for (int v : vec) {
			merge(v, v - 1);
		}
		for (int v : vec) {
			int nx = find(v), gap, ar;
			if (!use[nx]) {
				use[nx] = true;
				gap = mx[nx] - mn[nx];
				ar = max({ lcp[nx] ,lcp[ii[nx] + 1] });
				if (gap > ar) {
					ans += min(gap, cur.first) - ar;
				}
			}
		}
		for (int v : vec) use[find(v)] = false;
	}
	printf("%lld", ans);

	return 0;
}