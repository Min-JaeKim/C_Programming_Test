#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] == 1){
                board[i][j] = min(board[i-1][j], board[i][j-1]);
                board[i][j] = min(board[i-1][j-1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer*answer;
}

/*
���簢�� ���ϴ� �� ������ ���� �ȿͼ� �ٸ� ��� Ǯ�̸�
���Ҵ�. �и� �� ���ظ� �ߴµ� 
answer = 0���� �ϴϱ� ��� ���а� ����.
�ݷʴ� �׳� 1�� �ִ� board����.
���簢�� ũ�Ⱑ 1�� ���;� �����ε�,
1�� �ϳ��� �ֱ� ������ for������ ���� �ʴ´�. 
���� answer���� 0���θ� �ָ� 0�� ������ �� �ۿ� ����.
board[0][0]���� ���� ��.

*/ 
