#include <string>
#include <vector>
#include <iostream>
#define min_int 6565
#define max_int 9797

using namespace std;

int check[2][max_int+1];

bool checkalpha(char s){
    bool result = false;
    if((65 <= s && s <= 90) || (97 <= s && s <= 122)) result = true;
    return result;
}

char totoupper(char s){
    if(97 <= s) s-=32;
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    double temp_result = 0, s_union = 0, s_set = 0;
    vector<string> v;
    v.push_back(str1);
    v.push_back(str2);
    for(int i =0; i < 2; i++){
        string word = v[i];
        for(int j = 1; j < (int)v[i].length(); j++){
            char s1 = word[j-1];
            char s2 = word[j];
            if(checkalpha(s1) && checkalpha(s2)){
                s1 = totoupper(s1);
                s2 = totoupper(s2);
                int num = s1 *100 + s2;
                check[i][num]++;
            }
        }
    }
    for(int i = min_int; i <= max_int; i++){
        s_union += max(check[0][i], check[1][i]);
        s_set += min(check[0][i], check[1][i]);
    }
    cout<<s_union<<' '<<s_set<<' ';
    if(s_union != 0){
        temp_result = s_set / s_union;
        answer = (int)(temp_result * 65536);
    } else answer = 65536;
    return answer;
}

/*
���ڿ� ó���� ������â���� �߳�����.
�ϴ� ���� �ߴ� ��, 
1. �� ���� ���ڰ� ���ĺ����� Ȯ���ϰ�,
2.   t_str1[i-1]�� tolower�� ���·� push_back�ϴ� ��.
3. ������ ��������  vector<vector<string>> t_str1;
 �̻��ϰ� �����ߴ� ����, ��� push_back���� ������.
4. ��� ó���� ��� �ϴٰ� �ᱹ ������.
�� ���� �� ���� ���͸� ������ ���� �� �ڰ� �Ȱ�����
�ߺ��� 1���� ���ϰ� 1����, ��ҿ��� ��� ���� �� 1�����Ͽ���.
5. ������ �߻��� ������ �����ĸ�
�ߺ����� 3�� �̻��� ��쿡�� ���ϰ��� 1�� �����Ͽ��⿡
Ǯ���� �ʾҴ�.
6. �ذ��ϱ� ���ؼ� �ᱹ �ش��� ���Ҵ�. �ش��� 
7. �ش� ���ڿ��� ������ ���� ���̴�.

8.��,,, �ڵ�� �¾Ҵµ� ��� Ʋ�ȴٰ� ���ͼ�
�䵵 ���԰� �� �ð�° ����� �־��µ�
9. ������ check �迭�� ���������� ���������� �ʾұ�
�����̴�. ���������� �ʱ�ȭ�� ���� �ʾƵ� �׻�
0���� �ʱ�ȭ �Ǿ� �ִ�. 
���� ���� ���������� ����Ϸ��� �ʱ�ȭ�� ��,,
����� �Ѵ�. 
�̷� �㹫�� �ɷ� �ð� ��� ���� �ʰ� ���ʸ�
źź�� �ؾ߰ڴ� �ФФФ� 
