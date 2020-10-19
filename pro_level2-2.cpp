#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m;
    for(int i = 0; i<skill.length(); i++)
        m[skill[i]] = i+1;
    for(auto a : skill_trees){
        bool check = true;
        int count = 1;
        for(int i = 0; i<a.length(); i++){
            if(m[a[i]] > count){
                check = false;
                break;
            } else if(m[a[i]] == count) count++;
            else continue;
        }
        if(check) answer++;
    }
    return answer;
}
/*���̷��� �Ǵ��� �𸣰ڴ�.
�ϴ� ���� ó���� ��� Ǯ������ �����غ��ڸ�,
skill_trees���� skill �߰��� ���ڿ����� ���� ����ġ���� �Ѿ�� �߱� ������
����� ���� �ʾҴ�. ��, ���� �ؼ��� �߸��ߴ� ��.
���� �ؽ��� �̿��ϴ� Ǯ�̸� ���Ҵ�.
������ �� �� ���ظ� ������
m[skill[i]] = i�� �ƴ϶� i+1�� �ؾ��ϰ�,
count = 0�� �ƴ϶� 1�� �����ؾ� �Ѵ�.
������ �������� �𸣰ڴ�. �Ф�
*/ 
