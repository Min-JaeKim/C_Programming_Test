//���� ����Ǯ�̸� �𸣰� ��Ÿ�� ������ ��� ����.
//1. cin�� ���� ��
//2. main(void)�� return~; ������ �� 


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, k, answer = 0;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(),v.end(),greater<int>());
	for(int i = 0; i<n; i++){
		while(v[i] <= k){
			answer++;
			k-=v[i];
		}
	}
	cout<<answer<<endl;
}
