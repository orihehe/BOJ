/*
BOJ 16440 - 제이크와 케이크
https://www.acmicpc.net/problem/16440

횟수는 최대 2까지 나온다. 
n/2길이의 구간의 딸기 수가 n/4이면 자동으로 키위 수도 n/4가 된다.
앞 n/2부분에 딸기가 x개 있다면 뒤에는 n/2-x개의 딸기가 남아있고,
한 칸씩 옮기면 딸기 개수가 +1, 0, -1만큼 변하니 n/4인 구간이 있을 수밖에 없다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int n, s, k;
char st[200001];
int main() {
	int m;
	scanf("%d %s", &n, st);
	m = n / 2;
	for (int i = 0; i < m; i++) {
		if (st[i] == 's') s++;
		else k++;
	}
	if (s == k) return !printf("1\n%d", m);
	for (int i = m; i < n; i++) {
		if (st[i - m] == 's')s--;
		else k--;
		if (st[i] == 's') s++;
		else k++;
		if (s == k) return !printf("2\n%d %d", i - m + 1, i + 1);
	}

	return 0;
}