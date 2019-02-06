/*
BOJ 16406 (https://www.acmicpc.net/problem/16406)

���� ����� ���� ���� �ִ��� ���� ������ ģ��.
�ٸ� ����� ���� ������ ġ�� ���� Ʋ���� �Ǳ� ����
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