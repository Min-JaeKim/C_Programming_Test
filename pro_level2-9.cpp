#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    vector<pair<int, vector<int>>> v;
    int num = 0;
    for(int i = 1; i < s.length() - 1; i++){
        if( s[i] == '{') continue;
        else if (s[i] == '}'){
            temp.push_back(num);
            v.push_back(make_pair(temp.size(), temp));
            temp.clear();
            num = 0;
        }
        else if (s[i] == ','){
            if(s[i - 1] == '}') continue;
            temp.push_back(num);
            num = 0;
        }
        else {
            num *= 10;
            num += s[i] - '0';
        }
    }
    set<int> set_temp;
    sort(v.begin(), v.end());
    for(pair<int, vector<int>> vt : v){
        for(int num : vt.second){
            if(set_temp.find(num) == set_temp.end()){
                set_temp.insert(num);
                answer.push_back(num);
            }
        }
    }
    return answer;
}


/*
��� Ǯ��� �ϴ��� �𸣰ڴ�.
������ �� ���ڵ��� ���ͷ� �־��� �� �ƴ϶� S��� ���ڿ��� �ٰ��� ����ֱ� ����.

-> s���ڿ��� �ϳ��� ���鼭 ������ ��쿡�� 
���Ϳ� �ְ� ���ڰ� �ƴ� ��쿡�� � ���ڿ������� ����
ó���ϴ� ������ �������.

set_temp�� ���ϰ�
answer�� set���� ����  ó���Ϸ��� �ߴ���
��ȯ�� �ȵǴ� �� ����.
�׸��� set�� push_back�� �ƴ϶�
insert�� ��������� ��. 
*/
