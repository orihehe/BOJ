/*
BOJ 2261 - 가장 가까운 두 점
https://www.acmicpc.net/problem/2261

https://casterian.net/archives/92 에 풀이가 잘 설명되어있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
vector<int> vec[20001]; // x좌표 기준
pii loc[100001];
int dq(int l, int r) {
	int ret = MAX;
	if (l == r) {
		// 같은 x좌표의 점들을 봐준다.
		if (vec[l].size() <= 1) return MAX;
		sort(vec[l].begin(), vec[l].end());
		for (int i = 1; i<vec[l].size(); i++) {
			int s = vec[l][i] - vec[l][i - 1];
			ret = min(ret, s*s);
		}
		return ret;
	}
	int mid = (l + r) / 2;
	ret = min(dq(l, mid), dq(mid + 1, r));
	if (ret == 0) return 0; // 같은 점 있을 경우 나감
	int ls = 0, p = mid;
	while ((p - mid)*(p - mid) < ret && p >= l) {
		for (int v : vec[p])
			loc[ls++] = { v,p };
		p--;
	}
	p = mid + 1;
	while ((p - mid)*(p - mid) < ret && p <= r) {
		for (int v : vec[p])
			loc[ls++] = { v,p };
		p++;
	}
	sort(loc, loc + ls);
	for (int i = 0; i < ls; i++) {
		for (int j = i + 1; j < ls; j++) {
			int r = loc[j].first - loc[i].first;
			if (r*r >= ret) break;
			int c = loc[i].second - loc[j].second;
			ret = min(ret, r*r + c * c);
		}
	}
	return ret;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		a += 10000;
		b += 10000;
		vec[a].push_back(b);
	}
	printf("%d", dq(0, 20000));

	return 0;
}