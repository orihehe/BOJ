/*
백준 16679 Back to the Bones (https://www.acmicpc.net/problem/16679)
dp문제는 항상 어렵게 느껴진다. 처음에 dp를 잘못 짜서 고치고, 그래도 틀려서
어디가 틀린지 한참 찾았다. 도움을 받아 찾았는데 경우의 수 최대값을 찾는 부분에서
경우가 작아지는 순간 루프를 나왔는데 그 부분을 없애니 AC를 받았다. 
주사위 눈을 오름차순 소트후 풀어서 경우가 작아지면 잃는게 많아 더이상 늘어나지 않을거라
생각했는데, 어떻게 작아졌다 커지는 경우가 있는지 모르겠다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define P pair<int,int>
#define ll long long
using namespace std;

ll mul, dp[22][122], p, divi;
ll func(int n, int tar) {
	if (dp[n][tar] != 0) return dp[n][tar];
	if (tar == n * 6 || tar == n) return dp[n][tar] = 1;
	for (int x = 1; x <= 6; x++) {
		// tar(목표 수)-x(현재 주사위) 남은 주사위가 모두 1이 나올경우보다 크고, 
		// 남은 주사위가 모두 6이 나올 경우보다 작을 때 가능
		if (tar - x <= (n - 1) * 6 && tar - x >= n - 1) {
			dp[n][tar] += func(n - 1, tar - x);
		}
	}
	return dp[n][tar];
}

int main() {
	int t, n, k, sum, tmp, idx, ss;
	bool re[21];
	P dice[21];
	for (int i = 0; i < 6; i++) {
		dp[1][6 - i] = 1;
	}
	// dp배열 채우기, dp[n][x]는 n개 던졌을 때 x합 나올 경우의 수
	for (int i = 20; i <= 120; i++) {
		func(20, i);
	}
	for (int i = 1; i < 21; i++) {
		for (int j = i * 6; j >= i; j--) {
			dp[i][j] += dp[i][j + 1];
		}
	}
	dp[0][0];
	scanf("%d", &t);
	while (t--) {
		sum = 0; divi = 1;
		p = 0;
		memset(re, false, sizeof(re));
		memset(dice, 0, sizeof(dice));
		scanf("%d %d", &n, &k);
		mul = pow(6, n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &dice[i].first);
			sum += dice[i].first;
			dice[i].second = i;
		}
		sort(dice, dice + n + 1);
		if (sum >= k) { // 안 굴려도 됨
			printf("%lld\n", mul);
			for (int i = 0; i < n; i++) {
				printf("0 ");
			}
			printf("\n");
			continue;
		}
		tmp = sum; // 다시 던졌을 때 나올 수 있는 최대 수
		ss = k - sum; // 다시 던졌을 때 ss보단 커야함
					  // i개 다시 던짐
		for (int i = 1; i <= n; i++) {
			ss += dice[i].first;
			tmp += 6 - dice[i].first;
			divi *= 6;
			if (tmp >= k) {
				ll oc = dp[i][ss];  // ss이상 나올 경우의 수
				if (p == 0 || p < mul / divi * oc) {
					idx = i;
					p = mul / divi * oc;
				}
			}
		}
		printf("%lld\n", p);
		for (int i = 1; i <= idx; i++) {
			re[dice[i].second] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (re[i]) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}

	return 0;
}