#include <iostream>

using namespace std;

int factorial(int n){
	if(n < 1) return 1;
	return factorial(n-1) * n;
} 

int main(){
	int answer = 0;
	int n;
	cin >> n;
	answer = factorial(n);
	cout<<answer<<endl;
}

//factorial 0�� 0���� �˰� Ʋ�� ������ �𸣰� �־��µ� 0�� ���� 1�̶�� �Ѵ�.. 
