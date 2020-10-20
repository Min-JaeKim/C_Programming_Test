#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 25

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N;
bool check[MAX][MAX]; //�湮 ǥ�� 	
int arr[MAX][MAX];
int home_count;

void dfs(int x, int y){
	home_count++;
	check[x][y] = true;
	for(int i = 0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if(arr[nx][ny] == 1 && check[nx][ny] == false)
			dfs(nx, ny);
	}
}


int main(void){
	cin >> N;
	vector<int> v;
	for(int i = 0; i<N; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < N; j++)	arr[i][j] = temp[j] - '0';
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j<N; j++){
			if(arr[i][j] == 1 && check[i][j] == false){
				home_count = 0;
				dfs(i, j);
				v.push_back(home_count);
			}
		}
	}
	sort(v.begin(), v.end());
	cout<<v.size()<<'\n';
	for(auto a : v) cout<< a << '\n';
}
/*
���� ���� ��ϵ� 
���ڿ� ��� �����ϴ��� �� ��
�� ���� ���� ��

��� �ȵǴ� ������ 
���� ���������� bool check�� �̹� �����س��µ� main�Լ���
�� �����ϸ鼭 false�� �ʱⰪ�� �����ϰ� �Ǿ� ������� �ʾҴ�.
������ ��Ȯ�� �ľ����� ���ߴµ� ���������� �� �� �����ؾ��� 
������ �� ����.

�׷��� ���� �ڵ带 ���� ������ �ʰ� ������ ����ߴ� ����
dfs ������ �� ���� Ǯ��ƾ� �� �� ����. 

ps. � ��ĥ ����ϴٰ� Ǯ�⸦ ������ �����ε�(dx, dy�� �������� ���ؼ�)
����þ ���������� �� �˰� Ǯ�� �Ǿ���  ���� �ФФФ� ����þ ���� �ʹ�. 
*/ 

