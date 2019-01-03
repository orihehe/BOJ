/*
BOJ 1421 (https://www.acmicpc.net/problem/1421)
����Ž������ ��� ���� i�� �ڸ� �� �ִ밡 �������� ã�Ҵ�.
������ ���� �� ������ i���̷� �߶��� �� ������ �ƴ϶�� �� ������ i��쿡 ���� �ʾƾ� �Ѵ�.
���� �ѹ� �ڸ� �� i���� �� ���� ������ ���(����%i==0)�� ����ؾ��Ѵ�.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n;
	ll maxM = 0, cut, nc, c, w, tree[1000], tmp;
	scanf("%d %lld %lld", &n, &c, &w);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
	}
	for (ll i = 1; i <= 10000; i++) {
		cut = 0; nc = 0; tmp = 0;
		for (int j = 0; j < n; j++) {
			if (tree[j] % i == 0) nc = 1;
			else nc = 0;
			cut = tree[j] / i;
			if (cut*i*w > c * (cut - nc)) {
				tmp += cut * i*w - c * (cut - nc);
			}
		}
		maxM = max(maxM, tmp);
	}
	printf("%lld", maxM);

	return 0;
}