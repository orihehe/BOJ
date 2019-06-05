/*
BOJ 1431 (https://www.acmicpc.net/problem/1431)
�������� ���ϴ� ��� ������ ����� sort
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct info {
	char st[51];
	int len, hap;
};
bool operator < (info &a, info &b) {
	if (a.len == b.len && a.hap == b.hap) {
		for (int i = 0; i < a.len; i++) {
			if (a.st[i] != b.st[i]) {
				return a.st[i] < b.st[i];
			}
		}
	}
	if (a.len == b.len) return a.hap < b.hap;
	return a.len < b.len;
}
int main() {
	char x[51];
	int n, sum, l;
	info sr[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		scanf("%s", x);
		strcpy(sr[i].st, x);
		l = strlen(x);
		sr[i].len = l; // �ø����ȣ ����
		for (int j = 0; j < l; j++) {
			if (x[j] <= '9' && x[j] >= '1') 
				sum += x[j] - '0';
		}
		sr[i].hap = sum; // hap�� �ڸ��� ��
	}
	sort(sr, sr + n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", sr[i].st);
	}

	return 0;
}