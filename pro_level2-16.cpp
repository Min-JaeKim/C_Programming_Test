#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n > 0){
        if(n % 2 == 1) {
            n -= 1;
            ans++;
        }
        n /= 2;
    }

    return ans;
}
/*
1. ���ظ� ���ϰڴ� �� �Ÿ� 5�� ���õǾ��� ��,
����(1) -> �����̵�(2) - �����̵�(4) - ����(5) --> 2�� �Ǿ���.
�Ÿ� 6�� ����
����(1) - �����̵�(2) - �����̵�(4) - �����̵�(6) --> 1�� ���� �ʰ�,
����(1) -> �����̵�(2) - ����(3) - �����̵�(6) --> 2�� �ȴ�. ����?
-->  �ٺ�����. �����̵�(4) - �����̵�(8) �� �Ǿ�� �ߴµ� �߸� ����� ����

���� ª�� �����ߴٰ� �����ߴµ�
�ٸ� ������� �� ª�� �����ߴ�;;
�й��Ұ�. 
*/