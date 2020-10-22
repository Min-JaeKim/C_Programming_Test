#include <string>
#include <vector>

using namespace std;

vector<int> answer(2); //0�� 1�� üũ
vector<vector<int>> board;

void box(int x, int y, int size, int first){
    bool keep = true;
    if(size < 2){
        if(board[x][y] == 0) answer[0]++;
        else answer[1]++;
        return;
    }
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(board[i][j] != first){
                keep = false;
                break;
            }
        }
        if(!keep) break;
    }
    if(keep){
        if(board[x][y] == 0) answer[0]++;
        else answer[1]++;
        return;
    }
    box(x,y,size/2,board[x][y]);
    box(x + (size/2), y, size/2, board[x + (size/2)][y]);
    box(x, y + (size/2), size/2, board[x][y + (size/2)]);
    box(x + (size/2), y + (size/2), size/2, board[x + (size/2)][y + (size/2)]);
    
}

vector<int> solution(vector<vector<int>> arr) {
    int size = arr.size();
    board = arr;
    box(0,0,size,arr[0][0]);
    return answer;
}

/*
���� ���� ���� ���� �뷫���� Ǯ�� ���.
��� Ǯ��� �ϴ� �� ������ �� �� ��� ���۸��ϰ�, �ٷ� �ڵ� �᳻�� ����.
�׸��� arr ���� �������� board�� �����ϰ� �����Լ� ����ִ� �� ������ ȥ���� �����.
������ ���� Ǫ�� �ɷ��� �淯�߰ڴ�.
*/ 
