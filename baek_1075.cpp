#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    int F;
    cin >> N >> F;
    N = N/100 * 100;
    
    while(1){
    if(N%F == 0) break;
    N += 1;
	}
	string n = to_string(N);
	cout<<n[n.length()-2]<<n[n.length()-1];
    return 0;

}

//���ڿ��� �����ؼ� �ڿ� ���ڸ����� 0���� �ٲٷ��� �ߴµ� 
//���ʿ� �����⸦ �̿��ϰ� 100�� ���ϸ� �� �ڸ����� 00���� �ٲ��. 
