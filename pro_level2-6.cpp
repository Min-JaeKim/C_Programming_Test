#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int count = 1;
    vector<int> v;
    for(int i = 1; i <= s.length() / 2; i++){
        string result = "";
        for(int j = 0; j < s.length(); j += i){
            if(i + j > s.length() || s.substr(j,i) != s.substr(i+j,i)){
                if(count != 1) result += to_string(count);
                result += s.substr(j,i);
                count = 1;
            }
            else count++;
        }
        v.push_back(result.length());
    }
    if(s.length() == 1) answer = 1;
    else answer = *min_element(v.begin(), v.end());
    return answer;
}

/*
1. ���ٹ���� ������.
1-1. ó������ ������ ���鼭 ���ڿ� ������ ���ݱ���
���鼭 ��ġ�� ���ĺ��� �ִ��� ���� 
 */
