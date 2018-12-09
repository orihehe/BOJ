/*
처음에 일차원배열로 풀려다가 틀려서 질문 검색 탭을 봤다.
일차원배열로 하게되면 뒤에나올 i-1인 값(이전 곡에서 바꾼 볼륨)이 앞에서의 계산으로 값이 바뀌는 경우가 있을 수 있다.
따라서 이차원배열로 번갈아가며 i를 저장했다. 
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n, m, s, v, dp[2][1001],i,j, cnt=0;
	scanf("%d %d %d", &n, &s, &m);
	memset(dp, -1, sizeof(dp));
	dp[0][s] = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &v);
		for (j = 0; j <= m; j++) {
			//이전 곡에서 이 볼륨으로 바꿨을 때 곡을 이어갈 수 있음
			if (dp[cnt%2][j] == i-1) {
				if (j + v <= m) dp[(cnt+1) % 2][j + v] = i;
				if (j - v >= 0) dp[(cnt+1) % 2][j - v] = i;
			}
		}
		cnt++;
	}
	for (i = m; i >= 0; i--) {
		if (dp[cnt%2][i] == n) {
			printf("%d", i);
			break;
		}
	}
	if (i == -1) printf("-1");

	return 0;
}