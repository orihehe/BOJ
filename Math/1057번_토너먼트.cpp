#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b,cnt=1;
	scanf("%d %d %d", &n, &a, &b);
	if (b < a) swap(a, b);
	while (a % 2 != 1 || b - 1 != a) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
	printf("%d", cnt);

	return 0;
}