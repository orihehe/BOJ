/*
���� 1964 (https://www.acmicpc.net/problem/1964)
2��°���� 3n+1�� ���� ������ �þ.
ó���� O(N) ���� Ǯ����. 40ms
0ms Ǯ�̰� �־ ���������� �ٽ� Ǯ����. O(1)
*/
#include <cstdio>
#define mod 45678
using namespace std;

int main() {
	int n, sum = 5;
	scanf("%d", &n); 
	/*for (int i = 2; i <= n; i++) {
		sum = (sum + 3 * i + 1) % mod;
	}
	printf("%d", sum);*/
	n--;
	printf("%d", (5 + (3 * n*n + 11 * n) / 2) % mod);

	return 0;
}