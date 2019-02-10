/*
BOJ 10986 (https://www.acmicpc.net/problem/10986)

ans�迭�� 0���� �����ϴ� ��� ������ m���� ���� �������� ������ ����
�׸����� 0~n-1�� �����ϴ� �� �������� �������� 0 �� ������ ������ ī��Ʈ���ش�
���� i������ ���� ���������� �����Ͽ� ���� �ȴ�
*/
#include <cstdio>
#define ll long long
using namespace std;

ll ans[1001];
ll arr[1000001];
int main() {
	ll n, m, cnt = 0 , mm = 0;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		cnt += arr[i];
		ans[cnt%m]++;
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += ans[mm%m];
		ans[(mm + arr[i]) % m]--;
		mm += arr[i];
	}
	printf("%lld", cnt);

	return 0;
}