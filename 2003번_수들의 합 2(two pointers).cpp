/*
백준 2003 수둘의 합 2 (https://www.acmicpc.net/problem/2003)
fr은 구간의 맨앞, ba는 맨뒤 인덱스이다. 
구간합(sum)이 구하려는 값(m)보다 작다면 한 칸 뒤를 더한다.
구간합이 구하려는 값보다 크다면 앞쪽의 한 칸을 빼준다.
*/
#include <cstdio>
using namespace std;

int main() {
	int n, m, arr[10001], cnt=0, fr=0,ba=0,sum;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sum = arr[0];
	arr[n] = 30001;
	while (ba < n) {
		if (sum < m) sum += arr[++ba];
		else if (sum > m) sum -= arr[fr++];
		else {
			cnt++; 
			sum += arr[++ba];
		}
	}
	if (sum == m) cnt++;
	printf("%d", cnt);

	return 0;
}