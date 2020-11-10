#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a;
	cin >> a;
	vector<pair<int, int>> v;
	for(int i = 0; i < a; i++){
		int l,m;
		cin >>l >>m;
		v.push_back(make_pair(l,m));
	}
	sort(v.begin(), v.end());
	int dp[101]= {};
	dp[0] = 1;
	for(int i = 1; i < a; i++){
		int m = 0;
		for(int j = 0; j < i; j++){
			if(v[j].second < v[i].second){
				m = max(m, dp[j]);
			}
		}
		dp[i] = m + 1;
	}
	int m = 0;
	for(int i; i < a; i++){
		m = max(m, dp[i]);
	}
	cout<<a-m<<endl;
}


/*
dp�� �ʹ� ��ƴ�,,, �ٸ� ��� Ǯ�̸� ���� ó���� ���ظ� ���ߴ�.
������ �߿��� ������ �� �� �������� �ִ�r��  ���� ����ϸ�
������� �������� ���´�. ��

*/ 

