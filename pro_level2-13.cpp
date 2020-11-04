#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> monster;
        for(int i = 0; i < nums.size(); i++){
            if(monster.size() >= nums.size() / 2) break;
            if(find(monster.begin(), monster.end(), nums[i]) == monster.end())
                monster.push_back(nums[i]);
        }
    answer = monster.size();
    return answer;
}

/*
���� Ǯ�� �� Ǯ���ٰ� �����ߴµ� �ٸ� ���Ǯ�� ����
���� ���� �־��ٰ� ������ �Ͽ���.

#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> hash;
    for(auto num : nums){
        hash[num] += 1;
    }
    return min(hash.size(), nums.size() / 2);
}

����,,
unordered_map�� map���� �� ���� Ž���� �ϰ�,
�ð� ���⵵�� O(1)�̶�� ��.
�׳� map�� �ð����⵵ O(log n) 
*/ 
