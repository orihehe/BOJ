/*
BOJ 15465 (https://www.acmicpc.net/problem/15465)

날짜가 마구잡이로 주어지므로 날짜기준 오름차순 정렬
최고 우유를 가진 소가 바뀌었을 때 카운트, 그 상태를 stu에 저장하여 다음날짜와 비교
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct info {
	int day; // 날짜
	char na; // 소 이름 앞글자
	int chan; // 바뀐 우유 양
	bool operator <(const info &a) const {
		return day < a.day;
	}
};
info arr[101];
int stu[3], tmp[3];
int main() {
	int n, x, B = 7, E = 7, M = 7, cnt = 0;
	char name[10], dif[10];
	stu[0] = stu[1] = stu[2] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s %s", &x, name, dif);
		arr[i] = { x,name[0] };
		int len = strlen(dif), x = 1, tmp = 0;
		for (int j = len - 1; j > 0; j--) {
			tmp += x * (dif[j] - '0');
			x *= 10;
		}
		if (dif[0] == '-') {
			arr[i].chan = -tmp;
		}
		else arr[i].chan = tmp;
	}
	sort(arr, arr + n); // 날짜 차례로
	for (int i = 0; i < n; i++) {
		if (arr[i].na == 'B') {
			B += arr[i].chan;
		}
		else if (arr[i].na == 'E') {
			E += arr[i].chan;
		}
		else {
			M += arr[i].chan;
		}
		int mV = max({ B,E,M });
		memset(tmp, 0, sizeof(tmp));
		if (mV == B) tmp[0] = 1;
		if (mV == E) tmp[1] = 1;
		if (mV == M)tmp[2] = 1;
		for (int j = 0; j < 3; j++) {
			if (tmp[j] != stu[j]) {
				cnt++;
				break;
			}
		}
		memcpy(stu, tmp, sizeof(stu));
	}
	printf("%d", cnt);

	return 0;
}