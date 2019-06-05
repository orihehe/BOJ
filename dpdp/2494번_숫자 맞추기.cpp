/*
BOJ 2494 (https://www.acmicpc.net/problem/2494)

���� ���� ��ǥ ���� ���ߴ� ����� �������� �����ų�, ���������� �����ų� �̴�.
�������� ���� �� �Ʒ��� ���� ������� ��� ���� ���ư���, �������� ȥ�� ����.

dp[���ڳ��� ��ġ][������ �������� ���� Ƚ��]�� ����,
������ = dp[cur+1][cnt] + ������ ���� Ƚ��
���� = dp[cur+1][(cnt+���� ���� Ƚ��)%10] + ���� ���� Ƚ��
�� �� ���� ���� ����!

i��° ���ڳ��縦 ��������� ��� ���ȴ��� ã������ w�迭�� ������ش�.
w.first�� ���� ���ڳ����� �������� ���� Ƚ���� �����ϰ�,
w.second�� ���� ���ڳ��簡 ��������� ��� ���ư����� �����Ѵ�.
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

	int an = (a[cur] - '0' + cnt) % 10; // cnt��ŭ �������� ���ư� ���� ��
	int bn = b[cur] - '0';   // ��ǥ ��

	int tmp = (an - bn + 10) % 10;  // ���������� ������ ��ǥ ��

	int right = dfs(cur + 1, cnt) + tmp;
	// �������� 10�� ���� �� ���ڸ��̹Ƿ� %10�� ���� �־��ش�.
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