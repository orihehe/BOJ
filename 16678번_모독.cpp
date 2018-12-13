/*
���� 16678 �� (https://www.acmicpc.net/problem/16678)
Defile�� �ѹ��� �����ؾ� �ϹǷ� �������� �ִ� 1�� ���̰� �����h��.
��Ŀ ���� �ּҿ��� �ϹǷ� ��Ʈ �� ���̰� 0or1�� �����ϴ� ������ ����� �ȴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long arr[100001], last = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] > last) {
			last++;
			sum += arr[i] - last;
		}
	}
	printf("%lld", sum);

	return 0;
}