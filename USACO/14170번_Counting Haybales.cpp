/*
BOJ 14170 (https://www.acmicpc.net/problem/14170)
a~b구간의 건초 개수를 세는데 a와 b를 따로 생각한다.
a,b 정렬 후 앞에서부터 건초 위치와 비교해나가면 O(n)
b이하의 건초 개수 - a미만의 건초 개수
*/
#include <cstdio>
#include <algorithm>
#define P pair<int,int>
using namespace std;

P Qx[100000];
P Qy[100000];
int hay[100000];
P ans[100000];
int main() {
	int n, q, l, r, sum = 0;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &hay[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &Qx[i].first, &Qy[i].first);
		Qx[i].second = Qy[i].second = i;
	}
	sort(hay, hay + n);
	sort(Qx, Qx + q);
	sort(Qy, Qy + q);

	int ntop = -1;
	for (int i = 0; i < q; i++) {
		while (ntop + 1<n && Qx[i].first > hay[ntop + 1]) {
			ntop++;
		}
		ans[Qx[i].second].first = ntop;
	}
	ntop = -1;
	for (int i = 0; i < q; i++) {
		while (ntop + 1<n && Qy[i].first >= hay[ntop + 1]) {
			ntop++;
		}
		ans[Qy[i].second].second = ntop;
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i].second - ans[i].first);
	}

	return 0;
}