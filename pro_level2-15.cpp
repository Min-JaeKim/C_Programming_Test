#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num){
    for(int i = 2; i < num / 2; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int m = j + 1; m < nums.size(); m++){
                if(isPrime(nums[i] + nums[j] + nums[m])) answer++;
            }
        }
    }
    return answer;
}



#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int num){
    for(int i = 2; i < num / 2; i++){
        if(num % i == 0) return false;
    }
    return true;
}


/*
int solution(vector<int> nums) {
    int answer = -1;
    int temp = 0;
    vector<int> dec;

    do{
        for(int i = 0; i < 3; i++){
            temp += nums[i];
        }
        if(isPrime(temp)) {
            if(find(dec.begin(), dec.end(), temp) == dec.end())
                dec.push_back(temp);
        }
        temp = 0;
    }while(next_permutation(nums.begin(), nums.end()));
    answer = dec.size();
    return answer;
}
1. �Ҽ��� ��� ����ؾ� �� �� �����ߴ�.
�� �� ���� ���� ���� ���� ���ݱ��� ���������� ���� ���� ���θ� Ȯ���ϱ� ���� for���� ������.
�� isPrime���� �����ߴµ� ������ �� �����̴�.
2. �������� ����Ͽ����� �������� �ð��ʰ��� ����.
��� ����� 3�� for�� �� �� ���� ����ī�� ���ƴ�.
3. �� ���� ������ ���� �ߺ��� ���ٴ� ���ѻ����̴�.
���������� ���� ���� find, end�� �߾�� ������, 
��3�� for������ �ϸ� ���ص� ��. 
*/
