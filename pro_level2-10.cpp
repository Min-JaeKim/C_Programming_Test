#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(count < 0) return false;
        if(s[i] == '(') count++;
        if(s[i] == ')') count--;
    }
    if(count != 0) answer = false;
    return answer;
}

/*
ó���� stack�� ����ؼ� Ǯ� �� �����������µ�
������ ����� �Ǿ���.
���� �ٽ� ���Ӱ� Ǯ����. 
*/ 
