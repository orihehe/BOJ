/*
BOJ 14453 (https://www.acmicpc.net/problem/14453)
H-1, P-2, S-3 
i��°�� �� ���� �ٲ۴ٰ� �ϸ� i������ ���� ���� ���� ���� �̱�� ���� ����,
i���Ŀ� ���� ���� ���� ���� �̱�� ���� ���ٰ� �����ϸ� �ȴ�.

*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100001];
int n, lp, lh, ls, rp, rh, rs, maxS;
int main() {
	char x;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf("%c", &x);
		if (x == 'H') {
			arr[i] = 1;
			rh++;
		}
		else if (x == 'P') {
			arr[i] = 2;
			rp++;
		}
		else if (x == 'S') {
			arr[i] = 3;
			rs++;
		}
		getchar();
	}
	lh = lp = ls = 0;
	maxS = max({ lh,lp,ls }) + max({ rh,rp,rs });
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			lh++; rh--;
		}
		else if (arr[i] == 2) {
			lp++; rp--;
		}
		else if (arr[i] == 3) {
			ls++; rs--;
		}
		maxS = max(maxS, max({ lh,lp,ls }) + max({ rh,rp,rs }));
	}
	printf("%d", maxS);

	return 0;
}