/*
���� 2003 ������ �� 2 (https://www.acmicpc.net/problem/2003)
fr�� ������ �Ǿ�, ba�� �ǵ� �ε����̴�. 
������(sum)�� ���Ϸ��� ��(m)���� �۴ٸ� �� ĭ �ڸ� ���Ѵ�.
�������� ���Ϸ��� ������ ũ�ٸ� ������ �� ĭ�� ���ش�.
*/
#include <cstdio>
using namespace std;

int main() {
	int n, m, arr[10001], cnt=0, fr=0,ba=0,sum;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sum = arr[0];
	arr[n] = 30001;
	while (ba < n) {
		if (sum < m) sum += arr[++ba];
		else if (sum > m) sum -= arr[fr++];
		else {
			cnt++; 
			sum += arr[++ba];
		}
	}
	if (sum == m) cnt++;
	printf("%d", cnt);

	return 0;
}