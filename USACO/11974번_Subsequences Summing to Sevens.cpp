/*
BOJ 11974 (https://www.acmicpc.net/problem/11974)

부분합의 7로 나눈 나머지의 인덱스를 저장
나머지가 같은 인덱스의 가장 긴 값을 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[50001];
int idx1[7], idx2[7];
int main() {
	int n, cur;
	scanf("%d", &n);
	memset(idx1, -1, sizeof(idx1));
	memset(idx2, -1, sizeof(idx2));
	idx1[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		arr[i] += arr[i - 1];
		cur = arr[i] % 7;
		if (idx1[cur] != -1) {
			idx2[cur] = i;
		}
		else {
			idx1[cur] = i;
		}
	}
	cur = 0;
	for (int i = 0; i < 7; i++) {
		cur = max({ cur, idx2[i] - idx1[i], 0 });
	}
	printf("%d", cur);

	return 0;
}