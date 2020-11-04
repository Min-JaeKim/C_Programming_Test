#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> even;
    for(int i = 0; i < s.size(); i++){
        if(even.empty()){
            even.push(s[i]);
            continue;
        }
        if(even.top() == s[i]) even.pop();
        else even.push(s[i]);
    }
    if(even.empty()) answer = 1;
    return answer;
}


/*
ó������ �Ʒ��� ���� Ǯ���µ� �ð��ʰ��� ����. 
#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> even;
    for(auto n : s) even.push_back(n);
    for(int i = 0; i < even.size(); i++){
        if(even[i] == even[i+1]){
            even.erase(even.begin() + i + 1);
            even.erase(even.begin() + i);
            i = -1;
        }
    }
    if(even.size() == 0) answer = 1;
    return answer;
}

������ �Ẹ��� �ؼ� ������� ���,, ������ ������.
�׷��� ���� �� Ǭ Ǯ�̰� �� Ǯ�̶� �Ȱ��Ҵ�. �����̴�. 
*/
