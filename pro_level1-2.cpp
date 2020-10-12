#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; //������ ��Ƶ� ����;
    for(int j = 0; j < moves.size(); j++){
        for(int i = 0; i<board.size(); i++){
            if(board[i][moves[j] -1] != 0){
                if(!s.empty() && s.top() == board[i][moves[j] -1]) {
                    board[i][moves[j] -1] = 0;
                    answer+=2;
                    s.pop();
                    break;
                    }
                    else {
                    s.push(board[i][moves[j] -1]);
                    board[i][moves[j] -1] = 0;
                        break;
                }
                }
            }
        }
    return answer;
}

/*���� �׵��� break�� �߸� �˰� �־��ٴ� �� ���� ���޾Ҵ�.
���� ���� �ȿ� break�� �ɸ� �� ���� ������ ������ �� �ƴ϶�
break�� �ɾ��� �� ������ ������.. �̰� �� ���� �˾����� ��û�̴�.. 
�Ͽ����� �ҽ��ڵ带 �ʹ� �����ϰ� ®����.
�ڵ带 ���̴� ����� ����ĥ��..*/ 
