/*
BOJ 7453 (https://www.acmicpc.net/problem/7453)
�ܼ��� ��� ��츦 ���� O(N^4)�̴�.
����ϸ� �ð��� ���ϱ� �����ϴٰ� 4���� �迭�� �ѵ� ���� 2���� �迭�� ����� �ô�.
�׸����� a�迭�� i��° ���ҿ� ���� 0�� ����� �ִ� b�迭�� ���� ������ �̺�Ž������ ã�Ҵ�. O(N^2log(N^2))
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll tmp[16000001], tt;
int main() {
	int n;
	ll arr[4][4001], cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", 
			&arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[tt++] = arr[2][i] + arr[3][j];
		}
	}
	sort(tmp, tmp+tt);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll nxt = arr[0][i] + arr[1][j];
			cnt += upper_bound(tmp, tmp + tt, -nxt)
				- lower_bound(tmp, tmp + tt, -nxt);
		}
	}
	printf("%lld", cnt);

	return 0;
}