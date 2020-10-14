#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp = ""; //3���� �Ųٷ� �� �� ���ڿ��� ��� 
    char str =  ""; //stoi�� �̿��� ���ڿ�(char�� �ȵ�) 
    while(n/3 > 0){
        temp += to_string(n % 3); //3�� ���� ������ 
        n /= 3;
    }
    temp += to_string(n); //������������ temp�� ���� 
    int cnt = 1; //10������ �ٽ� �ٲ� ���� ��
    //�Ųٷδϱ� �ڿ� �迭���� 3^0 3^1 �Ͽ� ��� 
    for(int i = temp.length() -1 ; i>=0; i--){
        str = temp[i]; //stoi�� �ٷ� �ȵǱ� ������ ������ ���ڿ��� ���� 
        int check = stoi(str); //check ������ stoi�� ���ڿ� ����� 
        answer += check * cnt; //10������ ��ȯ ���� 
        cnt *= 3; //3�����ϱ� 3�� ���� �� 
    }
    
    return answer;
}

/*�̰� ����� �̷��� ���� �ɷ��� Ǯ����,,
 1. stoi�� ������ ����� ������. (�ٸ� ���ڿ��� ���ڿ� �ϳ� ��  ��Ƶ־ߵ�)
 2. for���� i--�� ���� �ʰ� i++�� �����س��Ҿ���. �翬�� �� �� ����. */ 
