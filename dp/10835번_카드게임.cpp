/*
BOJ 10835 (https://www.acmicpc.net/problem/10835)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[2000], b[2000], dp[2000][2000], n;
int go(int aa,int bb) {
	if (aa == n || bb == n) return 0;
	if (dp[aa][bb] != -1) {
		return dp[aa][bb];
	}
	int maxV = 0;
	maxV = max(maxV, go(aa + 1, bb)); // ���� ī�带 ������ ��
	maxV = max(maxV, go(aa + 1, bb + 1)); // ����, ������ ī�带 ������ �� 
	if (a[aa] > b[bb]) { // �������� ���ʺ��� ���� ���
		maxV = max(maxV, go(aa, bb + 1) + b[bb]); // ������ ī�带 ������ ���� ȹ��
	}
	// ���� ��� �� �ִ� ����
	return dp[aa][bb] = maxV;
}
int main() {
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0));

	return 0;
}