#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int bfs(int i, int j){
	queue<pair<int, int>> q;
	bool visit[100001] = {false};
	q.push(make_pair(i, 0));
	visit[i] = true;
	while(!q.empty()){
		int num = q.front().first;
		int idx = q.front().second;
		q.pop();
		if(j == num){
			return idx;
		}
		if(num + 1 < MAX && !visit[num+1]){
			q.push(make_pair(num+1, idx+1));
			visit[num+1] = true;
		}
		if(num - 1>= 0 && !visit[num-1]){
			q.push(make_pair(num-1, idx+1));
			visit[num-1] = true;
		}
		if(num*2 < MAX && !visit[num*2]){
			q.push(make_pair(num*2, idx+1));
			visit[num*2] = true;
		}
	}
}

int main(void){
	int i, j;
	cin >> i >> j;
	cout<<bfs(i,j)<<' ';
}

/*
�ʱ�ȭ�� ���� ������ ���  ��Ÿ�� ������ ���.
������ ��.

�ٸ� ������� �̷� Ǯ�̸� ��� �ϴ��� �ñ��ϴ�.
���� ���� ���� �־��ٴ� ���� ���� bfs��������.

*/ 
