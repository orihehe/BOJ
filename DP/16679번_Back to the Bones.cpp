/*
���� 16679 Back to the Bones (https://www.acmicpc.net/problem/16679)
dp������ �׻� ��ư� ��������. ó���� dp�� �߸� ¥�� ��ġ��, �׷��� Ʋ����
��� Ʋ���� ���� ã�Ҵ�. ������ �޾� ã�Ҵµ� ����� �� �ִ밪�� ã�� �κп���
��찡 �۾����� ���� ������ ���Դµ� �� �κ��� ���ִ� AC�� �޾Ҵ�. 
�ֻ��� ���� �������� ��Ʈ�� Ǯ� ��찡 �۾����� �Ҵ°� ���� ���̻� �þ�� �����Ŷ�
�����ߴµ�, ��� �۾����� Ŀ���� ��찡 �ִ��� �𸣰ڴ�.
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
		// tar(��ǥ ��)-x(���� �ֻ���) ���� �ֻ����� ��� 1�� ���ð�캸�� ũ��, 
		// ���� �ֻ����� ��� 6�� ���� ��캸�� ���� �� ����
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
	// dp�迭 ä���, dp[n][x]�� n�� ������ �� x�� ���� ����� ��
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
		if (sum >= k) { // �� ������ ��
			printf("%lld\n", mul);
			for (int i = 0; i < n; i++) {
				printf("0 ");
			}
			printf("\n");
			continue;
		}
		tmp = sum; // �ٽ� ������ �� ���� �� �ִ� �ִ� ��
		ss = k - sum; // �ٽ� ������ �� ss���� Ŀ����
					  // i�� �ٽ� ����
		for (int i = 1; i <= n; i++) {
			ss += dice[i].first;
			tmp += 6 - dice[i].first;
			divi *= 6;
			if (tmp >= k) {
				ll oc = dp[i][ss];  // ss�̻� ���� ����� ��
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