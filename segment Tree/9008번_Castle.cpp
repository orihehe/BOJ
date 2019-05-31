/*
BOJ 9008 - Castle
https://www.acmicpc.net/problem/9008

같은 r에서 인접한 두 점끼리 잇고, c에서도 동일하게
같은 r, c에 점 개수는 짝수개여야 한다.
교차판별은 세그트리로 스위핑, 모두 이어져 있는 지는 유니온 파인드로 판별했다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct info {
	int x1, x2, y;
	bool operator<(const info &a) const {
		if (x1 == a.x1) return x2 < a.x2;
		return x1 < a.x1;
	}
};
pii arr[10001];
vector<info> row, col;
vector<pii> vr[10001], vc[10001];
int rr[10001], cc[10001], tree[32768], p[10001], n;
priority_queue<pii, vector<pii>, greater<pii>> pq;
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	tree[idx] += val;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
}
int hap(int idx, int s, int e, int l, int r) {
	if (e<l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
bool isValid() {
	int cnt = 0;
	for (int i = 0; i < n; i++) if (find(i) == i) cnt++;
	if (cnt >= 2) return false;
	return true;
}
int main() {
	int t, idx, ps, rp, cp;
	bool ans;
	scanf("%d", &t);
	while (t--) {
		ans = true;
		row.clear(), col.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &cc[i], &rr[i]);
			arr[i] = { rr[i],cc[i] };
			p[i] = i;
		}
		if (n % 2) {
			printf("NO\n");
			continue;
		}
		sort(rr, rr + n);
		sort(cc, cc + n);
		for (int i = 0; i < n; i++) {
			idx = lower_bound(rr, rr + n, arr[i].first) - rr;
			ps = lower_bound(cc, cc + n, arr[i].second) - cc;

			vr[idx].push_back({ ps, i });
			vc[ps].push_back({ idx, i });
		}
		for (int i = 0; i < n; i++) {
			if (vr[i].size() % 2 || vc[i].size() % 2) {
				ans = false;
				break;
			}
			sort(vr[i].begin(), vr[i].end());
			sort(vc[i].begin(), vc[i].end());
			int sz = vr[i].size();
			for (int j = 0; j < sz; j += 2) {
				row.push_back({ vr[i][j].first,vr[i][j + 1].first,i });
				merge(vr[i][j].second, vr[i][j + 1].second);
			}

			sz = vc[i].size();
			for (int j = 0; j < sz; j += 2) {
				col.push_back({ vc[i][j].first,vc[i][j + 1].first,i });
				merge(vc[i][j].second, vc[i][j + 1].second);
			}
			vr[i].clear(), vc[i].clear();
		}
		if (!ans || !isValid()) {
			printf("NO\n");
			continue;
		}
		sort(row.begin(), row.end());
		rp = cp = 0;
		int rc = n / 2;
		for (int i = 0; i < n; i++) { // r좌표
			while (!pq.empty() && pq.top().first < i) {
				pii cur = pq.top();
				pq.pop();
				update(1, 1, n, cur.second, -1);
			}
			while (rp < rc && row[rp].x1 == i) {
				pq.push({ row[rp].x2, row[rp].y });
				update(1, 1, n, row[rp].y, 1);
				rp++;
			}
			while (cp < rc && col[cp].y == i) {
				if (col[cp].x1 + 1 <= col[cp].x2 - 1 &&
					hap(1, 1, n, col[cp].x1 + 1, col[cp].x2 - 1)) ans = false;
				cp++;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}

	return 0;
}