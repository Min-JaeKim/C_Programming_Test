#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int n,m,start;
int A[MAX][MAX]; // ������ ������ ������ �ִ��� Ȯ���ϴ� 2�� �迭 
int visit[MAX]; //�湮�� ���� Ȯ���ϴ� �迭 

void dfs(int x){ //���� �켱 Ž�� 
	cout<<x<<' '; //���� ��� 
	visit[x] = true; //�湮 Ȯ���� true�� 
	for(int i = 1; i<=n; i++){ //�� ��° �������� ����Ǿ� �ִ� �� Ȯ�� 
		if(visit[i] == 1 || A[x][i] == 0) continue; // �̹� �湮�߰ų�, ������ �ȵǾ� ������ ������ 
		dfs(i); //����Լ��� dfsǥ�� 
	}
}

void bfs(int v){ //�ʺ� �켱 Ž�� 
	queue<int> q; //�ʺ� �켱Ž���� queue�� �̿� 
	q.push(v); //�Ű������� q�� �ְ� 
	visit[v] = false; //�湮�� ���� false�� ǥ�� 
	while(!q.empty()){ //q�� ���������� 
		int x = q.front(); //q �� �� ���� x�� 
		q.pop(); 
		cout<<x<<' '; //q �� �� �� ��� 
		for(int i = 1; i<=n; i++){ // �ι�° ������ for�� 
			if(visit[i] == 0 || A[x][i] == 0) continue; // �湮�߰ų�, ���� �ȵǾ� ������ ������ 
				q.push(i); //�湮�� �ȵǾ� �ְ� ���� �Ǿ� ������ q�� ���� 
				visit[i] = false; //�湮 ó�� 
		}
	}
}

int main(){
	cin >> n >> m >> start;
	for(int i = 0 ;i < m; i++){
		int l, r;
		cin >> l>>r; 
        A[l][r] = A[r][l] = 1; // [1][2]�� ��������� ���� [2][1]�� ���� ����

	}
	dfs(start);
	cout<<endl;
	bfs(start);
}



/*
1. if(visit[i] == 1 || A[x][i] == 0) continue;
���⸦ visit[�Ű�����] �� �ؼ� Ʋ�ȴ�.
2. bfs while���� if������ �ߴ��� 1�� �⎵�ƴ�.
 */
