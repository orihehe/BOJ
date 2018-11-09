#include <cstdio>
using namespace std;

int arr[1000001];  // 0으로 초기화되어있음
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	arr[1] = 1;
	for (int i = 2; i <= n/2+1; i++) {
		if (arr[i]) continue;
		for (int j = 2; j*i <= n; j++) { // 소수인 본인 빼고
			if (arr[j*i]==0) 
				arr[j*i]=1;  // false를 true로
		}
	}
	for (int i = m; i <= n; i++) {
		if (arr[i]==0) printf("%d\n", i); // false에 소수저장되어있음
	}

	return 0;
}