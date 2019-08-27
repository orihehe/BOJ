/*
BOJ 17403 - 가장 높고 넓은 성
https://www.acmicpc.net/problem/17403
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int r, c, idx;
	bool operator<(const info &a) const {
		if (r == a.r) return c < a.c;
		return r < a.r;
	}
} arr[1001];
int ccw(info a, info b, info c) {
	return (a.r - c.r) * (b.c - c.c)
		- (b.r - c.r) * (a.c - c.c);
}
vector<info> sta, vec;
int ans[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].r, &arr[i].c);
		arr[i].idx = i;
	}
	int cnt = 1;
	while (true) {
		sta.clear();
		vec.clear();
		for (int i = 0; i < n; i++) {
			if (!ans[i]) vec.push_back(arr[i]);
		}
		if (vec.size() <= 2) break;
		sort(vec.begin(), vec.end());
		sort(vec.begin() + 1, vec.end(), [](info a, info b) {
			if (ccw(a, b, vec[0])) return ccw(a, b, vec[0]) > 0;
			return a < b;
		});
		sta.push_back(vec[0]);
		sta.push_back(vec[1]);
		int sz = vec.size();
		for (int i = 2; i < sz; i++) {
			while (sta.size() >= 2 && ccw(sta.back(), vec[i], sta[sta.size() - 2]) <= 0)
				sta.pop_back();
			sta.push_back(vec[i]);
		}
		if (sta.size() <= 2) break;
		for (info &a : sta) ans[a.idx] = cnt;
		cnt++;
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);

	return 0;
}