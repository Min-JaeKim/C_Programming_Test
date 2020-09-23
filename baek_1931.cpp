#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//cmp�Լ����� ������ ���µ�, �� ������ �𸣰ڴ� �̤� typedef�� �������ִ� ������ ���� �ʾҴ�. 
typedef pair<int,int> P;
vector<P> v;
//���� ������ �� �˾Ƶ� ��. 

bool cmp (P a, P b){
	if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
	int answer = 1;
	int n;
	cin >> n;
	//vector<pair<int,int>> v(n);
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		v.push_back(make_pair(l,r));
	}
	sort(v.begin(),v.end(),cmp);
	int temp = v[0].second;
	for(int i = 1; i<n; i++){
		if(temp <= v[i].first){
			answer++;
			temp = v[i].second;
		}
	}
	cout<<answer<<endl;
}

/*
		
		for(auto a : v){
		if(temp <= a.first){
			answer++;
			temp = a.second;
		}
	} // ���� ���� �ߴ� �ڵ��ε� �̰� Ʋ�������� �����̳ĸ�
	ù��° �迭���� ���� ����ع���. 
	������ζ�� �� ��° ������ ����ؾ���
	�ݷʴ�
	(4 / 1 1 / 1 3 / 4 5 / 6 9)
	���� 4�� ���;� ������, ���ڵ�� 5�� ������ ��. 
		
*/
