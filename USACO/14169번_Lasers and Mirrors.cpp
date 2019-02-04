/*
X좌표, Y좌표 기준 set을 만들어준다.
레이저는 상하좌우로 뻗어나가니 현재 위치와 x나 y좌표가 같은 울타리를 모두 큐에 넣어주고,
이미 넣은 좌표는 set에서 삭제해준다.
*/
#include <cstdio>
#include <queue>
#include <set>
#define pii pair<int,int>
using namespace std;

set<pii> mpX;
set<pii> mpY;
set<pii>::iterator iter;
queue<pii> q;
int main() {
	int n, x1, y1, x2, y2, s = 1, cnt = 0;
	bool suc = false;
	scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
	q.push({ x1,y1 });
	while (n--) {
		scanf("%d %d", &x1, &y1);
		mpX.insert({ x1, y1 });
		mpY.insert({ y1, x1 });
	}
	while (!q.empty()) {
		if (s == 0) {
			cnt++;
			s = q.size();
		}
		pii nx = q.front(); q.pop();
		if (nx.first == x2 || nx.second == y2) {
			suc = true;
			break;
		}
		for (iter = mpX.lower_bound({ nx.first,0 }); 
			iter!=mpX.end() && iter->first == nx.first;) {
			q.push(*iter);
			mpY.erase({ iter->second,iter->first });
			mpX.erase(iter++);
		}
		for (iter = mpY.lower_bound({ nx.second,0 });
			iter != mpY.end() && iter->first == nx.second;) {
			q.push({ iter->second, iter->first });
			mpX.erase({ iter->second,iter->first });
			mpY.erase(iter++);
		}
		s--;
	}
	printf("%d", suc ? cnt : -1);

	return 0;
}