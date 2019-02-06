/*
BOJ 16689 (https://www.acmicpc.net/problem/16689)

i������ ���� Ƚ���� i�� ���� �� ������ ���ϴ� ��� ���� i�� �����ϴ�.
���� �Է¹��� ������ 1�� ���������ְ�, �ڿ������� i�� ���� �� break
*/
#include <cstdio>
using namespace std;

int arr[1001];
int main() {
	int n, a, b, maxV = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) {
			arr[j]++;
		}
	}
	for (int i = n; i >= 0; i--) {
		if (arr[i] == i) {
			maxV = i; break;
		}
	}
	printf("%d", maxV);

	return 0;
}