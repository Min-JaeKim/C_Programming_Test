#include <iostream>
#include <string>

using namespace std;

string s;

int result(void){
	bool minus = false;
	int sum = 0;
	string temp = "";
	for(int i=0; i<=s.length(); i++){
		if(s[i] == '+' || s[i] == '-' || s[i] == '\0'){
			if(minus) sum-=stoi(temp);
			else sum+= stoi(temp);
			if(s[i] == '-') minus = true;
			temp = "";
			continue;
		}
		temp += s[i];
	}
	return sum;
}

int main(void){
	cin >> s;
	cout<<result()<<endl;
}

//���ڿ� �� ���� ��� �����ϳ� �ߴµ� 
//temp�� �̿��Ͽ� ��Ƶΰ� stoi�Լ��� �̿��Ͽ���. 
