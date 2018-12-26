/*
백준 2470 (https://www.acmicpc.net/problem/2470)
오름차순 정렬 후 l:왼쪽끝 인덱스, r:오른끝 인덱스로 초기화 후 
tmp = arr[l]+arr[r]의 절댓값이 가장 작은 두 수를 출력한다.
만약 tmp가 음수라면 절댓값이 줄어들 방법은 l++뿐이다. 덜 작은 수를 찾아야 절댓값이 작아지기 때문
반대로 tmp가 양수라면 r--을 하여 덜 큰 수를 찾는다.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100000];
int main() {
	int l, r, n, mix=2000000001, mA, mB;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	l = 0; r = n - 1;
	while (l != r) {
		int tmp = arr[l] + arr[r];
		if (abs(tmp) < mix) {
			mix = abs(tmp); 
			mA = arr[l], mB = arr[r];
		}
		if (tmp < 0) {
			l++;
		}
		else {
			r--;
		}
	}
	printf("%d %d", mA, mB);

	return 0;
}