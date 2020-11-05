#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char totoupper(char c){
    if(97 <= c && c <= 122) c-=32;
    return c;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    for(int i = 0; i < cities.size(); i++){
        if(cacheSize == 0)
            return 5*cities.size();
        for(int j = 0; j < cities[i].size(); j++)
            if(97 <= cities[i][j] && cities[i][j] <= 122) 
                cities[i][j] = totoupper(cities[i][j]);
        if(find(v.begin(), v.end(), cities[i]) == v.end()){
            answer+= 5;
            if(v.size() == cacheSize){
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
            else v.push_back(cities[i]);
        }
        else {
            answer++;
            for(int j = 0; j < v.size(); j++){
                if(v[j] == cities[i]){
                    v.erase(v.begin() + j);
                    v.push_back(cities[i]);
                }
            }
        }
    }
    return answer;
}

/*
ó���� deque�ε� Ǯ��ٰ� ���� ���ɿ��� �������
���ϴ� ���� Ȯ���ϰ� vector�� ���ƴ� ���� ��..
īī�� ���� Ǭ �̷��� ó������ ���� �Ⱥ��� �����. 
������ �� § �ڵ尡 �ƴ϶�� �����߱� ������ 
�ٸ� ��� Ǯ�̸� ���Ҵµ� iterator�� Ǭ Ǯ�̰� �־���.
���� iterator�� ���ذ� �� ���� �ʾƼ� �� Ǯ�̿� 
�����ϱ�� �Ͽ���..
*/ 
