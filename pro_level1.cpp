#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if( i == j ) continue;
            else s.insert(numbers[i] + numbers[j]);
        }
    }
    for(auto a:s) answer.push_back(a);
    return answer;
}

//python���� �ڵ��׽�Ʈ �� �ٲ�� �ϳ� ����� ������ �����ߴ�..
//�̹� �Ϲݱ⿡�� ���� ���ϸ� python���� �ٲ�߰ڴ�. 
