/*
BOJ 17026 - Mountain View
https://www.acmicpc.net/problem/17026

각 산마다 x축과 만나는 양끝 좌표를 저장해둔다.
어느 한 산의 범위에 완전히 포함된다면 그 산은 보이지않는다.
따라서 왼쪽좌표순으로, 같다면 오른쪽이 먼 순으로 정렬해준 뒤 왼쪽에서부터 스위핑
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec;
bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main() {
	int n, a, b, ans = 0, l = -1000000001, r = -1000000001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec.push_back({ a - b,a + b });
	}
	sort(vec.begin(), vec.end(), cmp);
	for (pii v : vec) {
		if (l <= v.first && v.second <= r) continue;
		r = max(r, v.second);
		ans++;
	}
	printf("%d", ans);

	return 0;
}