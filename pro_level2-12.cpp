#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, human = 0, avgtime = 0, mintime = 1, maxtime = 0;
    maxtime = *max_element(times.begin(), times.end()) * (long long) n;
    while(mintime <= maxtime){
        avgtime = (maxtime + mintime) / 2;
        for(auto t : times) human += avgtime/t;
        if(n <= human){
            answer = avgtime;
            maxtime = avgtime - 1;
        } else mintime = avgtime + 1;
        human = 0;
    }
    return answer;
}

/*
1. �̺�Ž���� ó�� �غ��Ҵ�.
2. 9��° �ٿ� n�� longlong���� �ϴ� ������
times�� ����� n�� ��� int ���̱⶧���� ���� ������ ��,
�ڸ����� ��û Ŀ���� int ���̱� ����. 
���� n�� long long���� �ٲ� ������ ����ؾ� �Ѵ�.
3. �� ���� ������ �� �������� human�� �ʱ�ȭ �ؾ� �Ѵ�.
*/ 
