/*
BOJ 11970 - Fence Painting
https://www.acmicpc.net/problem/11970
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[101];
int main() {
	int a, b, c, d, cnt = 0;;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for (int i = a; i < b; i++) arr[i] = 1;
	for (int i = c; i < d; i++) arr[i] = 1;
	for (int i = 0; i <= 100; i++)if (arr[i])cnt++;
	printf("%d", cnt);

	return 0;
}