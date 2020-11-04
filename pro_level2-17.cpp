#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<string> overlap = {words[0],};
    for(int i = 1; i < words.size(); i++){
        if(overlap[i-1][overlap[i-1].length() - 1] != words[i][0] || 
          find(overlap.begin(), overlap.end(), words[i]) != overlap.end()){
            return { i % n + 1,i / n + 1 };
        }
        else{
            overlap.push_back(words[i]);
        }
    }
    return {0,0};
}

/*
�ʹ� ��ư� ������ �� ����.
�ٸ� ������� map�� ���.
������ ��.
�׸��� ���� return ����
if((i+1) % n == 0){
                return{n, (i+1)/n};
            }
            return{((i+1)%n), (i+1)/n  + 1};
�̷��� �����ߴµ�,
������ ����� �������� �ʰ� return�ϴ� ���� ����
�����ߴ�. ����. 

map���� Ǫ�� ���

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int>h;
    h[words[0]] = 1;
    for(int i = 1; i < words.size(); i++){
        int len = words[i-1].length();
        if(h[words[i]] || words[i-1][len - 1] != words[i][0])
            return {i % n + 1, i / n + 1};
        h[words[i]] = 1;
    }
    return {0,0};
}

��¥ ��û ����.
���� ���� �ڵ� �д� �ӵ��� �������� �ִ�.  
*/ 
