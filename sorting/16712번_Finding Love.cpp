/*
백준 16712 (https://www.acmicpc.net/problem/16712)
m만큼 tmp배열에 저장 후 소트하여 v등수 자리에 줄에 서 있던 다음 사람을 넣는다.
출력할 때에는 마지막 v등수 사람이 포함되어있으므로 제외하고 출력해준다.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, v, m, s, arr[500],tmp[500];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	memcpy(tmp, arr, sizeof(int)*m);
	s = m;
	while (m < n) {
		sort(tmp, tmp + s);
		scanf("%d", &v);
		tmp[v - 1] = arr[m];
		m++;
	}
	scanf("%d", &v);
	sort(tmp, tmp + s);
	for (int i = 0; i < s; i++) {
		if (i == v - 1)continue;
		printf("%d ", tmp[i]);
	}

	return 0;
}