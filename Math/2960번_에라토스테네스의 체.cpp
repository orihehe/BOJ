#include <cstdio>
using namespace std;

bool sosu[1001];
int main() {
	int n, k, cnt=0, num=-1;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j+=i) {
			if (!sosu[j]) {
				cnt++;
				sosu[j] = true;
			}
			if (cnt == k) {
				num = j;
				break;
			}
		}
		if (num != -1) break;
	}
	printf("%d", num);

	return 0;
}