#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = false;
    while(!flag){
        vector<vector<bool>> visited(m, vector<bool>(n));
        flag = true;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                string s1 = board[i-1];
                string s2 = board[i];
                if(!board[i-1][j-1]) continue;
                if(s1[j-1] == s1[j] && s1[j-1] == s2[j-1] && s1[j] == s2[j]){
                    visited[i-1][j-1] = true;
                    visited[i-1][j] = true;
                    visited[i][j-1] = true;
                    visited[i][j] = true;
                    flag = false;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) {
                    answer++;
                    for(int k = i-1; k >= 0; k--){
                        board[k + 1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
    return answer;
}
/*
1. �̹� ó���� �κ��� ��� ��������?
�� �����ؾ� �� �κ��� 1�� �ٲپ 1 ���� �ִ� �迭�� 1�ڸ��� ����.
2. ��� 2x2�� ��󳻴���?
��if��
3. ha,,,,������ �𸣰ڴµ� visited�� bool visitied[m][n]
���� �����ߴ��� ��� ������ ����.
�ϴ� �迭 ������ ������ �������� ���ƾ� �ϱ� ������
������ ���� ���� �˰ڴµ�,
�׷� �迭�� ��� �����ؾ� ���ư��°��� ���˾Ƴ´�..
��ư,, �迭 ������ �����
4. ���ͷ� ������ ��.... 
*/
