/*
BOJ 17202 - 핸드폰 번호 궁합
https://www.acmicpc.net/problem/17202
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[16], tmp[16], pp = 15;
int main() {
	char a[9], b[9];
	scanf("%s %s", a, b);
	for (int i = 0; i < 8; i++) {
		arr[i * 2] = a[i] - '0';
		arr[i * 2 + 1] = b[i] - '0';
	}
	while (pp >= 2) {
		for (int i = 0; i < pp; i++) {
			tmp[i] = (arr[i] + arr[i + 1]) % 10;
		}
		pp--;
		memcpy(arr, tmp, sizeof(arr));
	}
	printf("%d%d", arr[0], arr[1]);

	return 0;
}