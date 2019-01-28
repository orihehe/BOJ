/*
BOJ 15461 (https://www.acmicpc.net/problem/15461)

map�� ó�� �ẻ ����
���� ���̵�, �������� �����ϴ� �� �ϳ�, ������, ������ ������ �����ϴ� �� �ϳ��� �����.
display�� �ٲ�� ����
1. ���� ���� ���̵� �ִ��� ��
2. ȥ�� �ִ��̴� �Ұ� �ٲ�� ���� �ִ��̰� �������̰ų�, �ִ��� �ƴ� ��
3. ������ �ִ��� ���϶�
4. �߰��� �ִ� �Ұ� �ִ��� ���� ��
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct info {
	int day, id, chan;
	bool operator <(const info &a) const {
		return day < a.day;
	}
};
map<int, int> mp;
map<int, int> mv;
vector<info> vec;
int main() {
	int n, g, d, id, m, cnt = 0;
	char pm;
	scanf("%d %d", &n, &g);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %c%d", &d, &id, &pm, &m);
		vec.push_back({ d,id,pm == '+' ? m : -m });
	}
	sort(vec.begin(), vec.end());
	for (info &v : vec) {
		if (mp.find(v.id) == mp.end()) {  // ������
			mp[v.id] = g + v.chan;
			mv[mp[v.id]]++;
			if (mv.find(g + v.chan) == --(mv.end())) cnt++;
		}
		else if (mv.find(mp[v.id]) == --(mv.end()) // �ִ뿡 ȥ��������
			&& mv[mp[v.id]] == 1) {
			mv.erase(mv.find(mp[v.id]));
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
			if (v.chan < 0) {
				if (mv.find(mp[v.id]) == --(mv.end()) && mv[mp[v.id]] != 1) cnt++;
				else if (mv.find(mp[v.id]) != --(mv.end())) cnt++;
			}
		}
		else if (mv.find(mp[v.id]) == --(mv.end())) { // �ִ뿡 ������
			cnt++;
			mv[mp[v.id]]--;
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
		}
		else {
			mv[mp[v.id]]--;
			if (mv[mp[v.id]] == 0) mv.erase(mv.find(mp[v.id]));
			mp[v.id] += v.chan;
			mv[mp[v.id]]++;
			if (mv.find(mp[v.id]) == --(mv.end()))  cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}