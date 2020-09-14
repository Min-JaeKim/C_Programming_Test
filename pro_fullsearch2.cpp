�Ҽ� ������ �˰� �� ��

1. �Ű� ������ �� ���� ���� ��쿡 ���� ���� ���� �Ű� ������ �ʱ�ȭ�� �̸� �����ش�.

2. set : ���� �ߺ��� ���� �ʰ� ���ʷ� �����Ű�� ���̺귯��

3. ���͸� push_back�� �� push_bakc({~~,~~}) �Ұ�ȣ �߰�ȣ �̿�



#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

void push(vector<pair<char, bool>> piece, set<int>& p, string a = "", int cnt = 0){
    for(int j = 0; j<piece.size(); j++){
        if(!piece[j].second){
            piece[j].second = true;
            a+= piece[j].first;
            p.insert(stoi(a));
            cnt++;
        } else continue;
        if(cnt != piece.size()) push(piece,p,a,cnt);
        piece[j].second = false;
        a=a.substr(0, a.length()-1);
        cnt--;
    }
}

bool Decheck(int a){
    for(int i = 2; i<=sqrt(a); i++)
        if(a%i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<pair<char, bool>> piece;
    set<int> p;
    for(int i =0; i<numbers.length(); i++)
        piece.push_back({numbers[i],false});
    push(piece,p);
    for(auto c : p){
        if(c == 0 || c == 1) continue;
        if(Decheck(c)) answer++;
    }
    return answer;
}



