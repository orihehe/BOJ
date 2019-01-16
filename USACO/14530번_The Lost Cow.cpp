/*
BOJ 14530 (https://www.acmicpc.net/problem/14530)
i�� ���������ָ� i%2�� 0�϶� ������ ��������, 1�϶� ���� ��������
���� ���� ������ ��츸 ���� ��ġ���� �������� ���ְ�, �������� ������ġ�� ������ġ ���̸� �����ش�.
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ll x, y, t = 1, i = 0;
	ll dist = 0, last;
	scanf("%lld %lld", &x, &y);
	last = x;
	if (x == y) {
		printf("0");
		return 0;
	}
	while (true) {
		if (x<y && !(i % 2) && x + t >= y) {
			dist += y - last;
			break;
		}
		else if (x > y && (i % 2) && x - t <= y) {
			dist += last - y;
			break;
		}
		dist += llabs(last - (i % 2 ? x - t : x + t));
		last = (i % 2 ? x - t : x + t);
		t *= 2;
		i++;
	}

	printf("%lld", dist);

	return 0;
}