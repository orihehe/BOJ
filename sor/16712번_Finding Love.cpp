/*
���� 16712 (https://www.acmicpc.net/problem/16712)
m��ŭ tmp�迭�� ���� �� ��Ʈ�Ͽ� v��� �ڸ��� �ٿ� �� �ִ� ���� ����� �ִ´�.
����� ������ ������ v��� ����� ���ԵǾ������Ƿ� �����ϰ� ������ش�.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, v, m, s, arr[500],tmp[500];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	memcpy(tmp, arr, sizeof(int)*m);
	s = m;
	while (m < n) {
		sort(tmp, tmp + s);
		scanf("%d", &v);
		tmp[v - 1] = arr[m];
		m++;
	}
	scanf("%d", &v);
	sort(tmp, tmp + s);
	for (int i = 0; i < s; i++) {
		if (i == v - 1)continue;
		printf("%d ", tmp[i]);
	}

	return 0;
}