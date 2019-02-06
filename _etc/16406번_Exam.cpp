/*
BOJ 16406 (https://www.acmicpc.net/problem/16406)

같은 결과를 받은 것을 최대한 맞은 답으로 친다.
다른 결과를 맞은 것으로 치면 나는 틀린게 되기 때문
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, cnt = 0, len, ans = 0;
	char A[1001], B[1001];
	scanf("%d", &n);
	scanf("%s %s", A, B);
	len = strlen(A);

	for (int i = 0; i < len; i++) {
		if (A[i] == B[i]) cnt++;
	}
	if (n > cnt) ans = len - n + cnt;
	else ans = n + len - cnt;
	printf("%d", ans);

	return 0;
}