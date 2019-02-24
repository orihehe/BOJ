/*
BOJ 13160 (https://www.acmicpc.net/problem/13160)

같은 지점이 모든 구간에 있으면 클리크가 된다.
정렬 후 구간을 순서대로 넣고, 포함 안 되는 구간은 빼주고
pq의 사이즈의 max값을 저장, 한번 더 pq로 탐색하여 정점을 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct info {
	int l, r, idx;
	bool operator < (const info &a) const {
		return l < a.l;
	}
};
info arr[300001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> ans;
int main() {
	int n, x, mV = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].l, &arr[i].r);
		arr[i].idx = i + 1;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		pq.push({ arr[i].r, arr[i].idx });
		while (pq.top().first < arr[i].l) pq.pop();
		mV = max(mV, (int)pq.size());
	}
	while (!pq.empty()) pq.pop();
	for (int i = 0; i < n;i++) {
		pq.push({ arr[i].r, arr[i].idx });
		while (pq.top().first < arr[i].l) pq.pop();
		if (mV == pq.size()) {
			while (!pq.empty()) {
				ans.push_back(pq.top().second);
				pq.pop();
			}
			break;
		}
	}
	printf("%d\n", mV);
	for (int v : ans) printf("%d ", v);

	return 0;
}