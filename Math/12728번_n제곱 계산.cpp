/*
BOJ 12728 (https://www.acmicpc.net/problem/12728)

pair�� 3+sqrt(5)�� 2^31 ���� ������ ����� �����صд�.
�츮�� sqrt(5)�� �����ִ� ������ �� �� ����. �Ǽ��θ� ��� ǥ���� �� ���� ū ���� ���ϸ� ��Ȯ�� ���� ������ �ʱ� ����.
���� sqrt(5)�κ��� �����־�� �Ѵ�. 

(3+sqrt(5))^n + (3-sqrt(5))^n �� ���ְ� �Ǹ� sqrt(5) �κ��� ��� ������� ������ ���� �ȴ�.
(3+sqrt(5))^n�� (3-sqrt(5))^n�� ���� �κ��� �����Ƿ� 2*((3+sqrt(5))^n�� ������)
(3-sqrt(5))^n �� 0<x<1�� �����̴�. ���� -1�� ���� �� ���
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000000
using namespace std;

pll apb[32];
int main() {
	int t, n;
	scanf("%d", &t);

	apb[1] = { 3,1 };
	for (int i = 2; i < 32; i++) {
		apb[i].first = (apb[i - 1].first*apb[i - 1].first % mod
			+ apb[i - 1].second * apb[i - 1].second * 5 % mod) % mod;
		apb[i].second = 2 * apb[i - 1].first * apb[i - 1].second %mod;
	}

	for (int i = 1; i <= t; i++) {
		pll ans = { 0,0 };
		ll bin = 1;
		scanf("%d", &n);
		for (int i = 1; bin <= n; bin *= 2, i++) {
			if ((n | bin) == n) {
				if (ans.first == 0) {
					ans = apb[i];
				}
				else
					ans = { (apb[i].first * ans.first % mod
						+ apb[i].second * ans.second * 5 % mod) % mod,
						(apb[i].first * ans.second %mod
							+ apb[i].second * ans.first %mod) % mod };
			}
		}
		printf("Case #%d: %03lld\n", i, (ans.first * 2 + 999) % 1000);
	}

	return 0;
}