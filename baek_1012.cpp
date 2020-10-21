#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAX 50

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[MAX][MAX] = {0};
int l,m,n;
int arr[MAX][MAX] = {0}; 

void dfs(int y, int x){
	for(int i = 0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= l || ny >= m) continue;
		if(arr[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx]++;
			dfs(ny,nx);
	}
}
}

int main(void){
	int N,a,b;
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> l >> m >> n;
		
		int ans = 0;
		memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
		for(int j = 0; j < n; j++){
			cin >> a >> b;
			arr[b][a] = 1;
		}
		for(int k = 0; k < m; k++)
			for(int h = 0; h < l; h++)
				if(arr[k][h] && !visited[k][h]){
					visited[k][h]++;
					ans++;
					dfs(k,h);
				}
			cout<<ans<<'\n';
			}
	}
	
/*
�� ���� �𸣰ڴµ� memset�� ���� ������  ���ؿ��� ��� Ʋ�ȴٰ� �ߴ�.
memset�� ���ص� ����ϱ� �ϴµ� ������ �𸣰ڴ�.
�׸��� x�� y�� ��ǥ�� �ٸ��� �ؼ� ����ؾ� �Ѵ�. ����?
�� �̰� �ʹ� �򰥸���
*/
 
