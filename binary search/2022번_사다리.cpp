/*
BOJ 2022 (https://www.acmicpc.net/problem/2022)
그림에 있는 ? 를 이분탐색으로 구할 값으로 정한다. - (mid)
? 값이 있게 되면 두 삼각형의 남은 한 변(lh)을 구할 수 있고
주어진 c의 비율과 lh의 비율은 삼각형의 빗변에서 c높이의 지점에서 밑변에 수직으로 선을 그었을 때 
나오는 작은 삼각형의 밑변과 원래 삼각형의 밑변의 비율과 같다는 점을 이용하여 작은 삼각형의 밑변을 구한다.
다른 삼각형 또한 같은 방식으로 밑변을 구하고, 그 변들의 합(tmp)과 ?의 값을 비교한다.
만약 tmp의 값이 mid의 값보다 크다면 두 사다리의 교점의 높이가 c보다 작다는 뜻이므로 r=mid로 mid값을 줄여야 한다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double x, y, c, lh, rh, l, r, mid;
	scanf("%lf %lf %lf", &x, &y, &c);
	l = 0, r = max(x, y);
	for (int i = 0; i<100; i++) {
		mid = (l + r) / 2;
		lh = sqrt(x * x - mid * mid);
		rh = sqrt(y * y - mid * mid);
		double tmp = mid * c / lh + mid * c / rh;
		if (mid > tmp) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%.3lf", mid);

	return 0;
}