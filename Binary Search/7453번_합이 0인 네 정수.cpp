/*
BOJ 7453 (https://www.acmicpc.net/problem/7453)
단순히 모든 경우를 보면 O(N^4)이다.
어떻게하면 시간을 줄일까 생각하다가 4개의 배열을 둘둘 합쳐 2개의 배열로 만들어 봤다.
그리고나서 a배열의 i번째 원소에 대해 0을 만들수 있는 b배열의 원소 개수를 이분탐색으로 찾았다. O(N^2log(N^2))
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll tmp[16000001], tt;
int main() {
	int n;
	ll arr[4][4001], cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", 
			&arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[tt++] = arr[2][i] + arr[3][j];
		}
	}
	sort(tmp, tmp+tt);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll nxt = arr[0][i] + arr[1][j];
			cnt += upper_bound(tmp, tmp + tt, -nxt)
				- lower_bound(tmp, tmp + tt, -nxt);
		}
	}
	printf("%lld", cnt);

	return 0;
}