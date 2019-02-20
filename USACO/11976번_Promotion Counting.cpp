/*
BOJ 11976 (https://www.acmicpc.net/problem/11976)
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int arr[2][4], ans[3];
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	ans[2] = arr[1][3] - arr[0][3];
	ans[1] = ans[2] + arr[1][2] - arr[0][2];
	ans[0] = ans[1] + arr[1][1] - arr[0][1];
	for (int i = 0; i < 3; i++) printf("%d\n", ans[i]);

	return 0;
}