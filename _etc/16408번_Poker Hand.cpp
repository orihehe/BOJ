// BOJ 16408 (https://www.acmicpc.net/problem/16408)
#include <cstdio>
#include <algorithm>
using namespace std;

int ap[27];
int main() {
	char st[3];
	int maxV = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%s", st);
		if (st[0] <= '9' && st[0] >= '0') {
			ap[st[0] - '0']++;
			maxV = max(maxV, ap[st[0] - '0']);
		}
		else {
			maxV = max(maxV, ++ap[st[0] - 'A']);
		}
	}
	printf("%d", maxV);

	return 0;
}