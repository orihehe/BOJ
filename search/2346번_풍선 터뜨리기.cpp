/*
다 검사를 해서 풀어 시간이 좀 나왔다.
0ms풀이가 있던데 나중에 다시 풀어봐야겠다.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, arr[1000], pp = 0, index = 0, x, cnt;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i<n; i++) {
		printf("%d ", index + 1);
		if (i == n - 1) break;
		x = arr[index];
		arr[index] = 0;
		cnt = 0;
		if (x < 0) {
			while (cnt < abs(x)) {
				--index;
				if (index < 0) index += n;
				if (arr[index] != 0) cnt++;
			}
		}
		else {
			while (cnt < abs(x)) {
				(++index) %= n;
				if (arr[index] != 0) cnt++;
			}
		}
	}

	return 0;
}