/*
BOJ 17075 - 유물 복원
https://www.acmicpc.net/problem/17075

플레인 스위핑으로 각 칸이 몇 번 포함되는지 세준다.
그 후 1인 칸의 합을 구해 -1인 칸을 합했을 때 나와야하는 나머지를 구하고,
냅색으로 구할 수 있는 나머지를 구해 추적하여 칠해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int num[52][52], ans[52][52];
ll sum;
pii dp[2502][2501];
vector<pii> vec;
int main() {
	int n, m, k, x;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int r = i + 1; r <= n; r++) {
				for (int c = j + 1; c <= m; c++) {
					num[i][j]++;
					num[i][c]--;
					num[r][j]--;
					num[r][c]++;
				}
			}
		}
	}
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= m; j++)
			num[i][j] += num[i][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			num[i][j] += num[i - 1][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			if (x == 1) sum += num[i][j];
			else if (x == -1) vec.push_back({ num[i][j] % k, i*m + j });
			ans[i][j] = x;
		}
	}
	sum %= k;
	sum = (k - sum) % k;
	if (sum == 0) {
		printf("1\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ans[i][j] == -1) printf("0 ");
				else printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	fill(dp[0], dp[0] + k, pii(-1, -1));
	int sz = vec.size();
	for (int j = 0; j < vec.size(); j++) {
		pii v = vec[j];
		int cc = j + 1;

		for (int i = k - 1; i >= 0; i--)
			dp[cc][i] = dp[cc - 1][i];
		for (int i = k - 1; i >= 1; i--) {
			if (dp[cc - 1][i].second != -1 && dp[cc][(v.first + i) % k].second == -1) {
				dp[cc][(v.first + i) % k].first = v.second;
				dp[cc][(v.first + i) % k].second = i;
			}
		}
		if (dp[cc][v.first].second == -1)
			dp[cc][v.first] = { v.second, k };
	}
	if (dp[sz][sum].second == -1) printf("-1");
	else {
		int mn = 0;
		for (pii i = dp[sz][sum];; i = dp[sz][i.second]) {
			ans[i.first / m][i.first % m] = 1;
			if (i.second == k) break;
		}
		printf("1\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ans[i][j] == -1) printf("0 ");
				else printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}