/*
���� 2470 (https://www.acmicpc.net/problem/2470)
�������� ���� �� l:���ʳ� �ε���, r:������ �ε����� �ʱ�ȭ �� 
tmp = arr[l]+arr[r]�� ������ ���� ���� �� ���� ����Ѵ�.
���� tmp�� ������� ������ �پ�� ����� l++���̴�. �� ���� ���� ã�ƾ� ������ �۾����� ����
�ݴ�� tmp�� ������ r--�� �Ͽ� �� ū ���� ã�´�.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100000];
int main() {
	int l, r, n, mix=2000000001, mA, mB;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	l = 0; r = n - 1;
	while (l != r) {
		int tmp = arr[l] + arr[r];
		if (abs(tmp) < mix) {
			mix = abs(tmp); 
			mA = arr[l], mB = arr[r];
		}
		if (tmp < 0) {
			l++;
		}
		else {
			r--;
		}
	}
	printf("%d %d", mA, mB);

	return 0;
}