/*
BOJ 2494 (https://www.acmicpc.net/problem/2494)

현재 수를 목표 수로 맞추는 방법은 왼쪽으로 돌리거나, 오른쪽으로 돌리거나 이다.
왼쪽으로 돌릴 땐 아래의 숫자 나사들이 모두 같이 돌아가고, 오른쪽은 혼자 돈다.

dp[숫자나사 위치][위에서 왼쪽으로 돌린 횟수]로 설정,
오른쪽 = dp[cur+1][cnt] + 오른쪽 돌린 횟수
왼쪽 = dp[cur+1][(cnt+왼쪽 돌린 횟수)%10] + 왼쪽 돌린 횟수
둘 중 작은 값을 리턴!

i번째 숫자나사를 어느쪽으로 몇번 돌렸는지 찾기위해 w배열을 만들어준다.
w.first엔 다음 숫자나사의 왼쪽으로 돌린 횟수를 저장하고,
w.second엔 현재 숫자나사가 어느쪽으로 몇번 돌아간지를 저장한다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define P pair<int,int>
using namespace std;

P w[10001][10];
int n, dp[10001][10];
char a[10001], b[10001];
int dfs(int cur, int cnt) {
	if (cur == n) return 0;
	if (dp[cur][cnt] != -1) return dp[cur][cnt];

	int an = (a[cur] - '0' + cnt) % 10; // cnt만큼 왼쪽으로 돌아간 현재 수
	int bn = b[cur] - '0';   // 목표 수

	int tmp = (an - bn + 10) % 10;  // 오른쪽으로 돌려서 목표 수

	int right = dfs(cur + 1, cnt) + tmp;
	// 왼쪽으로 10번 돌릴 시 제자리이므로 %10한 값을 넣어준다.
	int left = dfs(cur + 1, (cnt + 10 - tmp) % 10) + 10 - tmp;

	if (right < left) {
		dp[cur][cnt] = right;
		w[cur][cnt].first = cnt;
		w[cur][cnt].second = -tmp;
	}
	else {
		dp[cur][cnt] = left;
		w[cur][cnt].first = (cnt + 10 - tmp) % 10;
		w[cur][cnt].second = 10 - tmp;
	}
	return dp[cur][cnt];
}
int main() {
	scanf("%d", &n);
	scanf("%s %s", a, b);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, 0));
	int nx = 0;
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, w[i][nx].second);
		nx = w[i][nx].first;
	}

	return 0;
}