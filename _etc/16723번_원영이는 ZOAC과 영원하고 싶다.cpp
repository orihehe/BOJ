/*
BOJ 16723 (https://www.acmicpc.net/problem/16723)
ū ������ ���ش�.
�� ���� �������� ���� * �� �� ���ϰ�, ������ ���༭ ���� ���� ��ġ�� �� ���ش�
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int n, x = pow(2, 30), cnt = 0;
	ll sum = 0;
	scanf("%d", &n);
	n *= 2;
	while (x >= 2) {
		sum += (n / x - cnt)*x;
		cnt += n / x - cnt;
		x /= 2;
	}
	printf("%lld", sum);

	return 0;
}