/*
���� 14174 (https://www.acmicpc.net/problem/14174)
���� ������ �ܾ �� ���ĺ� ���� ����, �� ū ���� �� �迭�� �����ش�.
�׷��� �Ǹ� ��� ������ ������ ������ų �� �ִ�.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[26], tmpA[26], tmpB[26];
int main() {
	int n, alen, blen;
	char a[11], b[11];
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", a, b);
		alen = strlen(a);
		blen = strlen(b);
		memset(tmpA, 0, sizeof(tmpA));
		memset(tmpB, 0, sizeof(tmpB));
		for (int i = 0; i < alen; i++) tmpA[a[i] - 'a']++;
		for (int i = 0; i < blen; i++) tmpB[b[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			arr[i] += max(tmpA[i], tmpB[i]);
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}