/*
BOJ 15007 - Easter Eggs
https://www.acmicpc.net/problem/15007

모든 빨간, 파란 점 쌍의 거리를 구해두고 정렬한다.
이분탐색으로 거리를 구해주는데, 그 거리보다 작은 두 점은 둘 다 선택될 수 없다.
따라서 최소 버택스 커버(이분매칭) 문제로 바꿀 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct info {
	double dist;
	int a, b;
	bool operator<(const info &op) const {
		return dist < op.dist;
	}
};
pii arr[251];
vector<info> vvv;
int cnt, B[251];
pii fn[1001];
bool visited[1001];
vector<int> vec[1001];
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int n, b, r, x, y;
	double ans;
	scanf("%d %d %d", &n, &b, &r);

	for (int i = 0; i < b; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int i = 0; i < r; i++) {
		scanf("%d %d", &x, &y);
		for (int j = 0; j < b; j++) {
			int xx = arr[j].first - x;
			int yy = arr[j].second - y;
			double dd = sqrt(xx*xx + yy * yy);
			vvv.push_back({ dd,j,i });
		}
	}
	sort(vvv.begin(), vvv.end());
	int sz = vvv.size();
	double l = 0, rr = 800000000, mid;
	for (int k = 0; k < 60; k++) {
		mid = (l + rr) / 2;
		int tmp = 0;
		memset(B, -1, sizeof(B));
		for (int i = 0; i < sz; i++) {
			if (vvv[i].dist >= mid) break;
			vec[vvv[i].a].push_back(vvv[i].b);
		}
		for (int i = 0; i < b; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) tmp++;
		}
		for (int i = 0; i < b; i++) {
			vec[i].clear();
		}
		if (r + b - tmp<n) {
			rr = mid;
		}
		else {
			ans = mid;
			l = mid;
		}
	}

	printf("%lf", ans);

	return 0;
}