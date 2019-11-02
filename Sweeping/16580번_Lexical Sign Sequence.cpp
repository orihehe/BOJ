/*
BOJ 16580 - Lexical Sign Sequence
https://www.acmicpc.net/problem/16580

구해야 할 것은 현재 지점을 포함하는 구간의 -1이 최대로 나올 수 있는 개수의 최솟값이다.
구간을 pq로 관리하는데 pq에 먼저 들어있는 값은 -1을 선택함에 따라 선택가능한 개수가 줄어드니
pq최솟값 - 선택한 -1 개수가 양수일 때 -1를 선택가능하도록 한다.
그러면 나중에 들어오는 구간이 그 구간 내에서는 -1을 선택하지 않았지만 선택한 것처럼 되므로
그 구간의 최대 -1개수 + 현재까지 선택한 -1개수를 값으로 넣어준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[100001], dp[100001][2];
struct info {
	int l, r, val;
	bool operator<(const info &a) const {
		return val > a.val;
	}
};
vector<info> vec;
int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i][0] += dp[i - 1][0] + (arr[i] == 1);
		dp[i][1] += dp[i - 1][1] + (arr[i] == -1);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		int pls = dp[b][0] - dp[a - 1][0];
		int mns = dp[b][1] - dp[a - 1][1];
		int z = b - a + 1 - pls - mns;
		c -= pls;
		c += mns;
		if (c > z) return !printf("Impossible");
		vec.push_back({ a,b,(z - c) / 2 });
	}
	sort(vec.begin(), vec.end(), [](info &a, info &b) {
		return a.l < b.l;
	});
	priority_queue<info> pq;
	int vp = 0, cc = 0;
	for (int i = 1; i <= n; i++) {
		while (vp < m && vec[vp].l == i) {
			vec[vp].val += cc;
			pq.push(vec[vp++]);
		}
		if (arr[i]) continue;
		while (!pq.empty() && pq.top().r < i) pq.pop();
		if (pq.empty() || pq.top().val - cc > 0) {
			arr[i] = -1;
			cc++;
		}
		else arr[i] = 1;
	}
	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);

	return 0;
}