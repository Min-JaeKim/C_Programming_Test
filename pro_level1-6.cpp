#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int s_arr1[n][n];
    int s_arr2[n][n];
    for(int i = 0; i < n; i++){
        int temp1 = arr1[i];
        int temp2 = arr2[i];
        for(int j = n-1; j >= 0; j--){
            s_arr1[i][j] = temp1 % 2;
            s_arr2[i][j] = temp2 % 2;
            temp1 /= 2;
            temp2 /= 2;
        }
    }
    for(int i = 0; i<n; i++){
        string temp_ans = "";
        for(int j = 0; j<n; j++){
            if(s_arr1[i][j] + s_arr2[i][j] != 0) temp_ans += '#';
            else temp_ans += ' ';
        }
        answer.push_back(temp_ans);
    }
    
    return answer;
}

//�ٸ� ��� Ǯ�̸� ���� ��Ʈ�����ڸ� �Ἥ ���� �����ϰ� Ǭ ����� �־���. ����� ������.
/* ���� �� �������� ��ġ�� �־��� ����
���� s_arr1�� 2�� ���� string���� ���� ȿ������ ���̴� ��.
2������ �����ϰ� ���� �� �ִ� ��.
������ ����*/ 
 
