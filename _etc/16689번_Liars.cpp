/*
BOJ 16689 (https://www.acmicpc.net/problem/16689)

i지점이 나온 횟수와 i가 같을 때 진실을 말하는 사람 수가 i가 가능하다.
따라서 입력받은 구간을 1씩 증가시켜주고, 뒤에서부터 i와 같을 때 break
*/
#include <cstdio>
using namespace std;

int arr[1001];
int main() {
	int n, a, b, maxV = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) {
			arr[j]++;
		}
	}
	for (int i = n; i >= 0; i--) {
		if (arr[i] == i) {
			maxV = i; break;
		}
	}
	printf("%d", maxV);

	return 0;
}