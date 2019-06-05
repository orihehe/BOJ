/*
BOJ 2515 (https://www.acmicpc.net/problem/2515)

dp배열에 (현재 그림 + s차이 이후의 최댓값)과 현재 그림이후의 최대값 중 큰 값을 저장한다.
s차이 이후 첫번째 값을 찾기 위해 lower_bound를 사용했고, 같은 높이가 있으면 큰 값을 찾기 위해
그림의 높이로 정렬, 높이가 같다면 가격이 비싼것이 앞에 오도록 정렬했다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct pic {
	int h, v;
};
bool operator <(pic a, pic b) {
	if (a.h == b.h) return a.v > b.v;
	return a.h < b.h;
}
pic arr[300001];
int dp[300001];
int n, s;
int dfs(int cur) {
	if (cur >= n) return 0;
	if (dp[cur] != -1) return dp[cur];

	pic tmp1 = { arr[cur].h + s , 1001 };
	int ys = lower_bound(arr, arr + n, tmp1) - arr;
	return dp[cur] = max(dfs(ys) + arr[cur].v, dfs(cur + 1));
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].h, &arr[i].v);
	}
	sort(arr, arr + n);
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(0));

	return 0;
}