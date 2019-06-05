/*
BOJ 2957 (https://www.acmicpc.net/problem/2957)

���� ��尡 ���Ե� ��ġ��
1. ���� ���Ե� ���� �� ������ ū ���� �� ���� ���� ���� ����
2. ���� ���Ե� ���� �� ������ ���� ���� �� ���� ū ���� ������
�� �� �ϳ��ε�, ���� ���� �� ū ��� �ؿ� ���ԵǾ�� �Ѵ�.

1���� 2���� �̾����ְ� ���� ���� �� ����,
1��� ���̰� �� �۴ٸ� 1����� �ڽ����� ������ �ص� �� ��ġ�� 2��尡 ����.
�ݴ��� ��쵵 ��������
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

map<int, int> mp;
map<int, int> ::iterator iter;
int main() {
	int n, x;
	ll cur = 0;
	scanf("%d", &n);
	scanf("%d", &x);
	n--;
	mp[x] = 0;
	printf("0\n");
	while (n--) {
		scanf("%d", &x);
		iter = mp.lower_bound(x);
		if (iter == mp.end()) { // ���� �� ŭ
			mp[x] = (--iter)->second + 1;
		}
		else if (iter == mp.begin()) { // ���� �� ����
			mp[x] = iter->second + 1;
		}
		else {
			mp[x] = (iter--)->second;
			mp[x] = max(mp[x], iter->second) + 1;
		}
		cur += mp[x];
		printf("%lld\n", cur);
	}

	return 0;
}