/*
BOJ 2229 (https://www.acmicpc.net/problem/10835)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 2; i <= n; i++) {
		int minV = arr[i], maxV = arr[i];
		for (int j = 1; j < i; j++) { // i는 i앞 j명과 함께 조가 된다.
			minV = min(minV, arr[i-j]), maxV = max(maxV, arr[i-j]);
			// j명 만큼과 조가 되었을 때 점수 차이 + j 이전의 최댓값
			dp[i] = max(dp[i], dp[i - j-1] + maxV - minV); 
		}
	}
	printf("%d", dp[n]);

	return 0;
}