#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int Q[1001], l[1001], r[1001], ans[1001], cnt[1001];
ll res;
vector<pii> mid;
int main() {
	int n, x0, a, b, q, cur;
	scanf("%d %d %d %d %d", &n, &x0, &a, &b, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &Q[i]);
		r[i] = mod - 1;
	}
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		mid.clear();
		for (int i = 0; i < q; i++) {
			if (l[i] <= r[i]) {
				mid.push_back({ (l[i] + r[i]) / 2,i });
			}
		}
		if (mid.size() == 0) break;
		sort(mid.begin(), mid.end());
		cur = x0;
		int idx = upper_bound(mid.begin(), mid.end(), pii(cur, q)) - mid.begin();
		cnt[idx]++;
		for (int j = 1; j < n; j++) {
			cur = (1LL * cur*a + b) % mod;
			idx = upper_bound(mid.begin(), mid.end(), pii(cur, q)) - mid.begin();
			cnt[idx]++;
		}
		for (int i = 1; i < q; i++) cnt[i] += cnt[i - 1];
		int sz = mid.size();
		for (int i = 0; i < sz; i++) {
			if (cnt[i] > Q[mid[i].second]) {
				r[mid[i].second] = mid[i].first - 1;
			}
			else {
				l[mid[i].second] = mid[i].first + 1;
				ans[mid[i].second] = mid[i].first;
			}
		}
	}
	for (int i = 0; i < q; i++) res += ans[i];
	printf("%lld", res);

	return 0;
}