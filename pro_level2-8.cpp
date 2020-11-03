#include <string>
#include <vector>

using namespace std;

char kakao[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool visited[8] = {false,};
vector<char> V;
int answer;

void DFS(int n, vector<string> data, int cnt){
    if(cnt == 8) {
        for(int i = 0; i < n; i++){
            char c1 = data[i][0];
            char c2 = data[i][2];
            char cal = data[i][3];
            int dist = data[i][4] - '0';
            dist++;
            int idx, iidx;
            idx = iidx = -1;
            for(int j = 0; j < 8; j++){
                if(V[j] == c1) idx = j;
                if(V[j] == c2) iidx = j;
                if(idx != -1 && iidx != -1) break;
            }
            if(cal == '=' && abs(idx - iidx) != dist) return;
            if(cal == '>' && abs(idx - iidx) <= dist) return;
            if(cal == '<' && abs(idx - iidx) >= dist) return;
        }
        answer++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(visited[i]) continue;
        visited[i] = true;
        V.push_back(kakao[i]);
        DFS(n, data, cnt + 1);
        V.pop_back();
        visited[i] = false;
    }
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    answer = 0;
    DFS(n, data, 0);
    return answer;
}

/*
1. ���ڿ� ó��
1-1. īī��ĳ���͵��� char�� ���� ����
1-2. ������ �ȿ� �ִ� ���� ������ ��� ó���ϴ� ��
1-3. ���ڿ� �������� '0' ���� ��.
1-4. dist�� 0�̶�� �� �ٸ� �Ÿ��� 1�� �������ߵ�.
1-5. idx�� ĳ���Ͱ� �ִ� ��ġ�� ��Ÿ���ְ�. ���밪 ��� 

2. ���������� �ַ�� �Լ����� �ʱ�ȭ ���� �ʾұ� ������
��� ���а� ������. 
*/
