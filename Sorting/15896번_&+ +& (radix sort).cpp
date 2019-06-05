/*
BOJ 15896 - &+ +&
https://www.acmicpc.net/problem/15896

1번째 값은 각 원소의 켜진 비트를 체크하여 
a배열에서 i비트가 켜진 원소 수 * b배열에서 i비트가 켜진 원소 수 * i 의 합을 구하면 된다.

2번째 값은 기수정렬을 하며 i비트를 보는 중엔 뒤의 비트들 기준으로 정렬된 상태를 만든다.
그 후 현재 비트가 0,0 or 1,1이라면 작은 값끼리, 0,1 or 1,0이라면 큰 값끼리 봐주어
현재 비트가 0이 되는지 체크 해준다.

그런데 꼭 이렇게 안해도 된다...( ._.)..
기수정렬을 안 하고 그냥 쫙 봐주면서 최솟값, 최댓값을 가지고 가면 된다.
*/
#include <cstdio>
#include <vector>
#define mod 1999
using namespace std;

/* 🐣🐥 */
int a[1000000], b[1000000], ans1, ans2;
vector<int> aa[30][2], bb[30][2];
int main() {
	int n, ap, bp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);

	for (int i = 0, tt; i <= 29; i++) {
		tt = 1 << i;
		ap = bp = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] & tt) aa[i][1].push_back(a[j]);
			else aa[i][0].push_back(a[j]);
			if (b[j] & tt) bb[i][1].push_back(b[j]);
			else bb[i][0].push_back(b[j]);
		}
		for (int j = 0; j < 2; j++)
			for (int v : aa[i][j]) 
				a[ap++] = v;

		for (int j = 0; j < 2; j++)
			for (int v : bb[i][j]) 
				b[bp++] = v;

		ans1 = (ans1 + tt % mod * aa[i][1].size() % mod * bb[i][1].size() % mod) % mod;
	}
	for (int i = 0, tt; i <= 29; i++) {
		tt = 1 << i;
		if (!aa[i][0].empty() && !bb[i][0].empty() && !((aa[i][0][0] + bb[i][0][0]) & tt)) continue;
		if (!aa[i][1].empty() && !bb[i][0].empty() && !((aa[i][1].back() + bb[i][0].back()) & tt)) continue;
		if (!aa[i][0].empty() && !bb[i][1].empty() && !((aa[i][0].back() + bb[i][1].back()) & tt)) continue;
		if (!aa[i][1].empty() && !bb[i][1].empty() && !((aa[i][1][0] + bb[i][1][0]) & tt)) continue;

		ans2 += tt;
	}
	printf("%d %d", ans1, ans2);

	return 0;
}