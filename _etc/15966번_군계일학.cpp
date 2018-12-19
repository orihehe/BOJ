/*
백준 15966 군계일학 (https://www.acmicpc.net/problem/15966)
연속한 수의 가장 긴 수열의 길이를 구하는 문제
arr[i]에 arr[i-1]+1을 저장하면 i-1의 수열의 가장 긴 길이에 추가하는 셈이다
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000001];
int main() {
	int n, len=0, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x] = arr[x - 1] + 1;
		len = max(len, arr[x]);
	}
	printf("%d", len);

	return 0;
}