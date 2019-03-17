/*
BOJ 1790 (https://www.acmicpc.net/problem/1790)

k��° �ڸ� ���ڰ� ��� ���� ����ִ��� �� ���� ã�´�.
*/
#include <cstdio>
#define ll long long
using namespace std;

int main() {
	ll x = 9, n, k, s = 1, sum = 0, tmp = 1, op = 0;
	char ori[10];
	scanf("%lld %lld", &n, &k);
	while (sum + x*s < k) {
		sum += x * s;
		x *= 10; // �ڸ����� ���� ����
		s++;  // �ڸ���
	}
	k -= sum; // s�ڸ��� ������ ���� ���� ���� ����

	for (int i = 2; i <= s; i++) 
		tmp *= 10;
	tmp += (k-1) / s; // �� ������ ���°�
	if (tmp > n) printf("-1");
	else {
		ll mn = 100000000;
		while (mn > tmp) mn /= 10;
		while (mn > 0) {
			ori[op++] = tmp / mn + '0';
			tmp %= mn;
			mn /= 10;
		}
		printf("%c", ori[(k - 1) % s]);
	}

	return 0;
}