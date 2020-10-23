#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

vector<int> arr[MAX];
int M,N;
bool visited[MAX];

void dfs(int a){
	visited[a] = true;
	for(int i = 0; i < arr[a].size(); i++){
		int next = arr[a][i];
		if(!visited[next]){
			dfs(next);
		}
	}
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int l,r;
		cin>>l>>r;
		arr[l].push_back(r);
		arr[r].push_back(l);
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}
/*
�̷��� ���� ������ �������ٴ�,,,
main�� �� ��° for���� 1���� ��������� �Ѵ�.
����ó�� 0���� �����ϸ� �ȵȴ�. �ֳĸ� arr������ 1�̱� �����̴�.
������ �Ǿ� ������ ������ ���Ϳ� push_back����� �Ѵ�.
��
*/ 
