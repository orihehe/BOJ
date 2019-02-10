/*
BOJ 12864 (https://www.acmicpc.net/problem/12864)

å�� �񳻸��������� �����ؾ��ϹǷ� i���� å�� i���� ��ȣ�� ���� �Ϳ���
���� ���� ū ���� �����Ѵ�. ���ĵ� ���� ���� ū ���� ã���� �Űܾ� �� ���� �۾����Ƿ�
*/
#include <cstdio>
#include <algorithm>
#define pdi pair<double,int>
using namespace std;

pdi book[5001];
int dp[5001];
int main() {
	int n, sum = 0, maxV = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &book[i].first);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &book[i].second);
		sum += book[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (book[j].first <= book[i].first) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += book[i].second;
		maxV = max(maxV, dp[i]);
	}
	printf("%d", sum - maxV);

	return 0;
}