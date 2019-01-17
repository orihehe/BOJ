/*
BOJ 2629 (https://www.acmicpc.net/problem/2629)

���� �� �ִ� ���� ��, ���� ������ ���Ը� �� �� �ִ�.
���� �߸� ������� �� ���� �� �ִ� ���Կ� ���� �߸� ���ϰų� ���ش�.
�߸� ������ ���� �̹� ���� ū ���� �迭�� ����ǹǷ� ���� ���Ժ��� ���� ���ѰͿ� �� ���ϰԵȴ�.
���� ���� ���� ū ������ ��������, �� ���� ���� ������ �ö󰣴�.
���� ��� �̹� ���� ���� ��������� ���� ���� ���� ���ڸ��̹Ƿ� ��� ����.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int chu[31];
bool can[40001];
int main() {
	int n, t, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &chu[i]);
	}
	can[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 15000 - chu[i]; j >= 0; j--) {
			if (can[j]) {
				can[j + chu[i]] = true;
			}
		}
		for (int j = 0; j <= 15000; j++) {
			if (can[j]) {
				can[abs(j - chu[i])] = true;
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf(can[x] ? "Y " : "N ");
	}

	return 0;
}