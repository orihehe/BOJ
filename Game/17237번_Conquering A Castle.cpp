/*
BOJ 17237 - Conquering A Castle
https://www.acmicpc.net/problem/17237

각 길의 d=1인 위치에 군사 한 명씩 있어야 A가 이길 수 있다.
현재 위치의 병사중 최대 반이 살아 1m전진
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[21];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x]++;
	}
	for (int i = 20; i >= 1; i--)
		arr[i - 1] += arr[i] / 2;
	printf("%c", arr[0] ? 'A' : 'B');

	return 0;
}