/*
BOJ 9426 (https://www.acmicpc.net/problem/9426)

ù �߾Ӱ��� ���صΰ�, �߾Ӱ� ���� �� ������ ���Ѵ�.
map���� ���� �������� �����ϴ� ���� key, ���� ������ value�� �����ϰ�
������ �� ĭ�� �ű�� map�� ���ϰ� ���ش�.
���� ���� ������ (k+1)/2�� �̻��̶�� mid���� �ٿ����ϰ�,
���Ǽ� + mid�� ������ (k+1)/2�� �̸��̶�� mid���� Ű���� �Ѵ�.
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

int arr[250000], mid, bf;
ll sum;
map<int, int> mp;
map<int, int> ::iterator iter, tmp;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < k; i++) {
		mp[arr[i]]++;
	}
	iter = mp.begin();
	while (bf < (k + 1) / 2) {
		bf += mp[iter->first];
		mid = iter->first;
		++iter;
	}
	bf -= mp[mid];
	sum = mid;
	for (int i = k; i < n; i++) {
		mp[arr[i - k]]--;
		mp[arr[i]]++;
		tmp = mp.find(mid);

		if (arr[i - k] < mid) {
			bf--;
		}
		if (arr[i] < mid) bf++;
		if (bf >= (k + 1) / 2) {
			mid = (--tmp)->first;
			bf -= mp[mid];
		}
		else if (bf+mp[mid] < (k + 1) / 2) {
			bf += mp[mid];
			mid = (++tmp)->first;
		}
		sum += mid;
		if (mp[arr[i - k]] == 0) mp.erase(arr[i - k]);
	}
	printf("%lld", sum);

	return 0;
}