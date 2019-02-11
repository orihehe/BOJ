/*
BOJ 16720 (https://www.acmicpc.net/problem/16720)

1, 2, 3, 4번째 줄에 0을 쭉 만들었을 때 최솟값이 답이 된다.
각 줄에 오직 한 개의 길이 존재하기 때문
*/
#include <cstdio>
#include <algorithm>
using namespace std;

char b[4];
int main() {
	int n, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n - 2; i++) {
		scanf("%s", b);
		if (b[1] == '0' || b[3] == '0') {
			cnt1++;
		}
		else if (b[2] == '0') cnt1 += 2;
		if (b[0] == '0' || b[2] == '0') {
			cnt2++;
		}
		else if (b[3] == '0') cnt2 += 2;
		if (b[0] == '0' || b[2] == '0') {
			cnt4++;
		}
		else if (b[1] == '0') cnt4 += 2;
		if (b[1] == '0' || b[3] == '0') {
			cnt3++;
		}
		else if (b[0] == '0') cnt3 += 2;
	}
	printf("%d", min({ cnt1,cnt2,cnt3,cnt4 }) + 2 + n);

	return 0;
}