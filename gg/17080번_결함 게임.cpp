/*
BOJ 17080 - 결함 게임
https://www.acmicpc.net/problem/17080
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n;
	scanf("%d", &n);
	if (n%4==3) printf("2");
	else printf("1");

	return 0;
}