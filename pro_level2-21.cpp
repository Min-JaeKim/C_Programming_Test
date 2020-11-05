#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    stringstream ss;
    string id, action, nick;
    vector<string> uid;
    map<string, string> info;
    for(int i = 0; i < record.size(); i++){
        ss.str(record[i]);
        ss >> action;
        if(action == "Enter"){
            ss >> id;
            ss >> nick;
            uid.push_back(id);
            info[id] = nick;
            answer.push_back("���� ���Խ��ϴ�.");
        }
        else if(action == "Leave"){
            ss >> id;
            uid.push_back(id);
            answer.push_back("���� �������ϴ�.");
        }
        else {
            ss >> id;
            ss >> nick;
            info[id] = nick;
        }
        ss.clear();
    }
    for(int i = 0; i < answer.size(); i++){
        answer[i] = info[uid[i]] + answer[i];
    }
    return answer;
}

/*
��.. ������� Ǯ�ٰ� ������ ���� �κ���
��� ó���ؾ��� �� ���� ã�ƺô���
sstream�̶�� STL�� �־���.
���� ���� ���׵� ���� �� ���Ծ��µ� ������ �˾Ƽ� 
�����̴�...

�׸��� �߿��� ���� FOR�� �������� SS�� CLEAR���ִ� ��
�߿��ϴ�.

�� �Ѱ���.
map<string1, string2> m;
��  m[string1] = string2;
�� �� ���� ����... 
*/ 
