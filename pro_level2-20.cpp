#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(answer < n / 2){
        if(b % 2 == 0 && a == (b-1)) break;
        if(a % 2 == 0 && b == (a-1)) break;
        answer++;
        a = a / 2 + a%2;
        b = b / 2 + b%2;
    }
    return answer;
}

/*
���� �̹����� �̷��� ���� Ǯ������ ��
���� 35�� �ɸ���,,
������ �ٸ� ��� Ǯ�̸� ���� ���� ���� ���Ǹ� �д�.
*/ 
