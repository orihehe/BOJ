/*
BOJ 8103 (https://www.acmicpc.net/problem/8103)

x, y에 대한 구간과 입력받은 순서를 xx구조체에 저장
i값을 어느 구간을 줄지 정하는데, i가 x1과 같을 때 pq에 넣어주고 pq의 맨위값이 i를 포함하지 않으면 pop해준다.
pq에 넣는 값은 x2값인데, i~x2범위가 가장 작은 값에 i를 넣어주면 가장 많이 i를 배치해줄 수 있기 때문이다.
x값, y값에 대해 따로 이 과정을 해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>
using namespace std;

struct xx {
	int x1, x2, idx;
	bool operator < (const xx & a) const {
		if (x1 == a.x1) return x2 < a.x2;
		return x1 < a.x1;
	}
};
int n;
xx arrX[3001], arrY[3001];
P ans[3001];
bool solve(xx *arr, int s) {
	priority_queue<P, vector<P>, greater<P>> pqX;
	int xp = 0;
	for (int i = 1; i <= n; i++) {
		while (xp < n && arr[xp].x1 == i) {
			pqX.push({ arr[xp].x2 , arr[xp].idx });
			xp++;
		}
		while (!pqX.empty() && pqX.top().first < i) pqX.pop();
		if (pqX.empty()) {
			return false;
		}
		else {
			if (s)
				ans[pqX.top().second].second = i;
			else ans[pqX.top().second].first = i;
			pqX.pop();
		}
	}
	return true;
}
int main() {
	bool suc = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &arrX[i].x1, &arrY[i].x1, &arrX[i].x2, &arrY[i].x2);
		arrX[i].idx = arrY[i].idx = i;
	}
	sort(arrX, arrX + n);
	if (!solve(arrX, 0)) printf("NIE");
	else {
		sort(arrY, arrY + n);
		if (!solve(arrY, 1)) printf("NIE");
		else {
			for (int i = 0; i < n; i++)
				printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}

	return 0;
}