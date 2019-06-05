/*
백준 14888 연산자 끼워넣기 (https://www.acmicpc.net/problem/148880)
N과M 시리즈 같은 문제이다. 재귀로 완전탐색!
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[12], op[4], n, maxN=-1000000000,minN=1000000000;
void calc(int cur, int cnt) {
	if (cnt == n) {
		maxN = max(maxN, cur);
		minN = min(minN, cur);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) calc(cur + arr[cnt], cnt+1);
			else if (i == 1) calc(cur - arr[cnt], cnt+1);
			else if (i == 2) calc(cur * arr[cnt], cnt+1);
			else if (i == 3) calc(cur / arr[cnt], cnt+1);
			op[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) scanf("%d", &op[i]);
	calc(arr[0], 1);
	printf("%d\n%d", maxN, minN);

	return 0;
}