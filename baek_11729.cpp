#include <iostream>

using namespace std;

void hanoi(int n, int start, int middle, int end){
	if(n ==1 ) {
		cout << start <<' '<<end<<endl;
	}
	else{�� 
		hanoi(n-1,start,end,middle);
		cout<<start<<' '<<end<<endl;
		hanoi(n-1,middle,start,end);
	}
}

int main(void){
	int n;
	cin >> n;
	cout << (1<<n) -1 <<endl;
	hanoi(n,1,2,3);
	return 0;
}

//��Ϳ� ���ϴ� ���� �����ɷȴ� ����,,
//�ٹٲ��� endl�� ����ϸ� �ð� �ʰ���� �߱� ������ '\n'�� ��� 
