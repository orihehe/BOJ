/*
가장 긴 증가하는 부분 수열 문제 (백준 11053번 https://www.acmicpc.net/problem/11053) 와 비슷했다.
이미 오름차순 정렬 되어있는 아이들 외의 아이들의 위치만을 바꿀 때 최소가 된다.
따라서 가장 긴 오름차순을 찾는다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[200];
int dp[200];
int main() 
{
	int n, maxC=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		maxC = max(maxC, dp[i]);
	}
	printf("%d", n - maxC);

	return 0;
}