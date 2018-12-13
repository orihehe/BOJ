/*
���� 16680 �ȼ���� (https://www.acmicpc.net/problem/16680)
ó���� �׳� �ȼ������ ã�� ������ n�� ������� - TLE
9�θ� �̷���� 9�� ������ ¦���� ��, ���� ��� 99999999�� 100000000999999989�� ������ �ȼ��������.
�̷� ��츸 �� ���� �� ���� n�� 100000011�� ���ϰ� �����ߴ�. ����� 240ms�� AC������
0ms�� �е� �ڵ带 ���� n������ n*n�� �����ָ� ã�� �� �ô�. �� �̷��� �ϸ� �Ǵ���..�𸣰ڴ�..��
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll sbin(ll x) {
	ll sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main() {
	int t;
	ll n, tmp;
	scanf("%d", &t);
	while (t--) {
		tmp = 0;
		scanf("%lld", &n);
		tmp = n * 100000011;
		while (true) {
			if (sbin(tmp) % 2 == 1) break;
			tmp += n;
		}
		printf("%lld\n", tmp);
	}

	return 0;
}