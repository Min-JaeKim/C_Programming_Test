#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define MAX 101

using namespace std;

int arr[MAX][MAX];
int w, h;
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};
int cnt = 1000000;
int temp = 0;
queue<pair<int,int>> q;
int dist[MAX][MAX];

int main(void){
		cin >> h >> w;
		for(int i = 0; i < h; i++){
			string s;
			cin >> s;
			for(int j = 0; j < w; j++){
				arr[i][j] = s[j] - '0';
			}
		}
		q.push(make_pair(0,0));
		dist[0][0] = 1;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visited[x][y] = true;
			for(int i = 0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if( nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if(arr[nx][ny] && !visited[nx][ny]){
					q.push(make_pair(nx,ny));
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
		cout<<dist[h-1][w-1]<<'\n';
}

/* 
dfs�δ� ������ Ǯ���� �ʾƼ� ������� �ҽ��ڵ带 ���Ҵ�.
 bfs�� �ʺ� �켱 Ž���̴� bfs�� Ǯ��ߵ�
*/ 
