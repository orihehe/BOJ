/*
BOJ 12864 (https://www.acmicpc.net/problem/12864)

책을 비내림차순으로 정렬해야하므로 i이전 책이 i이하 번호를 가진 것에서
가장 값이 큰 것을 저장한다. 정렬된 합이 가장 큰 값을 찾으면 옮겨야 할 값이 작아지므로
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