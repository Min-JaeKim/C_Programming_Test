#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,double>& a, pair<int,double>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> fail;
    float people = stages.size();
    sort(stages.begin(), stages.end());
    for(int i = 1; i <= N; i++){
        int count = 0;
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] == i){
                count++;
            }
        }
        if(count == 0) fail.push_back(make_pair(i,0));
        else fail.push_back(make_pair(i,count/people));
        people -= count;
    }
    sort(fail.begin(), fail.end(), compare);
    for(auto a : fail) answer.push_back(a.first);
    return answer;
}

/*
ó���� �� ��ż� �������� �� ��� ���� ���� ����
�ٸ� ����� �� ����ߴ�...
���� �� �ð��� ���� �� ���� �� ������ �� �ȵǾ
�׳� �ð� ���̴� �� ���� �Ф�
*/ 
