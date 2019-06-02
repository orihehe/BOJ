/*
BOJ 13334 - 철로
https://www.acmicpc.net/problem/13334

현재 끝점을 기준으로 끝점이 왼쪽에 있는 애들을 pq에 넣어준 뒤, d를 넘어가는 점을 빼준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
priority_queue<int, vector<int>, greater<int>> fr;
pii arr[100001];
bool cmp(pii &a, pii &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n, ap = 0, d, p = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		if (arr[i].second < arr[i].first) swap(arr[i].first, arr[i].second);
	}
	scanf("%d", &d);
	for (int i = 0; i < n; i++) {
		if (arr[i].second - arr[i].first > d) continue;
		arr[ap++] = arr[i];
	}
	sort(arr, arr + ap, cmp);
	while (p < ap) {
		int e = arr[p].second;
		while (p < ap && arr[p].second == e) {
			fr.push(arr[p].first);
			p++;
		}
		while (!fr.empty() && fr.top() < e - d) fr.pop();
		ans = max(ans, (int)fr.size());
	}
	printf("%d", ans);

	return 0;
}