/*
BOJ 15464 (https://www.acmicpc.net/problem/15464)

���ø��� i��ġ�� �Ҹ� ai��ġ�� ������.
3�� ���� �� ����� �־����ְ�, ���� ���¸� ���ϴ� ����!
���� �� ���·� ������� ai��ġ�� �Ҹ� i�� ������ �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int loc[101];
int arr[101], tmp[101];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &loc[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	while (cnt < 3) {
		for (int i = 1; i <= n; i++) {
			tmp[i] = arr[loc[i]];
		}
		memcpy(arr, tmp, sizeof(arr));
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}