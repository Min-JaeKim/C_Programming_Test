//vector �ʱ�ȭ�� vector<int> �̸�(����, �ʱ�ȭ ��)
//for(auto>����  �� ������ ��,,, 


#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n,1); //��� 1�� �� ���� �ִٰ� 1�� �ʱ�ȭ
    for(auto l : lost) check[l-1]--;
    for(auto r : reserve) check[r-1]++;
    for(int i = 0; i < n; i++){
        if(!check[i]){
            if(check[i+1] == 2){
                check[i+1]--;
                check[i]++;
            } else if(check[i -1] ==2){
                check[i-1]--;
                check[i]++;
            }
        }
    }
    for(auto a : check)
    	if(a) answer++;
    return answer;
}

int main(void){
	solution(5,{2,4},{3});
}
