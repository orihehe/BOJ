#include <cstdio>
using namespace std;

int main()
{
	int n, m, k, remain, contest;
	scanf("%d %d %d", &n, &m, &k);
	contest = n / 2 > m ? m : n / 2;
	remain = n - contest*2 + m - contest;
	if (k > remain) {
		if ((k - remain) % 3 == 0) {
			contest -= (k - remain) / 3;
		}
		else {
			contest -= (k - remain) / 3 + 1;
		}
	}
	printf("%d", contest);

	return 0;
}