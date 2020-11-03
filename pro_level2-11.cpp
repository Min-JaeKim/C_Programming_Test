#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    string num;
    vector<long long> v_num;
    vector<char> v_cal;
    vector<char> ex_cal;
    for(int i = 0;  i < expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '*' || expression[i] == '-'){
            v_num.push_back(stoi(num));
            num = "";
            if(find(ex_cal.begin(), ex_cal.end(),expression[i]) == ex_cal.end())
                ex_cal.push_back(expression[i]);
            v_cal.push_back(expression[i]);
        }
        else 
            num += expression[i];
    }
    v_num.push_back(stoi(num));
    sort(ex_cal.begin(), ex_cal.end());
    do{
        vector<long long> tmp_num = v_num;
        vector<char> tmp_cal = v_cal;
        for(int i = 0; i < ex_cal.size(); i++){
            for(int j = 0; j < tmp_cal.size(); j++){
                if(ex_cal[i] == tmp_cal[j]){
                    if(tmp_cal[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j+1];
                    else if(tmp_cal[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j+1];
                    else if(tmp_cal[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j+1];
	                tmp_num.erase(tmp_num.begin() + j + 1);
	                tmp_cal.erase(tmp_cal.begin() + j);
	                j--;
            	}
            }
        }
        answer = answer > abs(tmp_num[0]) ? answer : abs(tmp_num[0]);
    }while(next_permutation(ex_cal.begin(), ex_cal.end()));
    
    return answer;
}


/*
1. set���� ��� ó���ϴ� ���� �����̹Ƿ�, ���Ϳ��� find�� end�� �� ��
2. set�� ���� ������.find�� ���������� ������ ���� �ȵǴ� ��.
2-2. ���� ���ͷ� �� ���� find(v.begin, v.end, ã�� ��) == v.end() �̷�������
3. ���Ϳ��� ���� ���� ���� clear�� �ƴ϶� erase
3-3. erase�� �� ��ȣ�� ���� �ִ� �� �ƴ϶� �ε����� ���� ��.
--> dump ��
�� ������ ������ ���� v_num�� ���� �ʾұ� ����. ������ �׷��� ���� Ʋ����. ������?��
�� ������ do~while�� �ȿ� tmp_num�� tmp_cal�̶�� �ӽú��ͷ� ���� �ʾұ� �����ε�
	�� �׷��� �Ǵ����� ���ذ� ���� �ʴ´�... 
*/     
