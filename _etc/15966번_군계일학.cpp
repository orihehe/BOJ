/*
���� 15966 �������� (https://www.acmicpc.net/problem/15966)
������ ���� ���� �� ������ ���̸� ���ϴ� ����
arr[i]�� arr[i-1]+1�� �����ϸ� i-1�� ������ ���� �� ���̿� �߰��ϴ� ���̴�
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000001];
int main() {
	int n, len=0, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x] = arr[x - 1] + 1;
		len = max(len, arr[x]);
	}
	printf("%d", len);

	return 0;
}