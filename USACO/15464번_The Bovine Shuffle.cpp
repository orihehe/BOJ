/*
BOJ 15464 (https://www.acmicpc.net/problem/15464)

셔플마다 i위치의 소를 ai위치로 보낸다.
3번 셔플 한 결과가 주어져있고, 원래 상태를 구하는 문제!
셔플 전 상태로 만드려면 ai위치의 소를 i로 보내면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int loc[101];
int arr[101], tmp[101];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &loc[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	while (cnt < 3) {
		for (int i = 1; i <= n; i++) {
			tmp[i] = arr[loc[i]];
		}
		memcpy(arr, tmp, sizeof(arr));
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}