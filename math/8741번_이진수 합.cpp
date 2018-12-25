/*
백준 8741 (https://www.acmicpc.net/problem/8741)
1은 n개 0은 n-1개인 규칙은 발견했으나 왜 이렇게 되는 지는 몰라 검색해봤다.
원리 -> http://dev-min.tistory.com/6
*/
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) printf("1");
	for (int i = 0; i < n - 1; i++) printf("0");

	return 0;
}