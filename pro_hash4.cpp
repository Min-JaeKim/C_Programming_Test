#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> listen;
    map<string, map<int, int>> num;
    for(int i = 0; i < genres.size(); i++){
        listen[genres[i]] += plays[i];
        num[genres[i]][i] = plays[i];
    }
    while(listen.size() != 0){
        string song{};
        int max{0};
        for(auto a : listen){
            if(max < a.second){
                max = a.second;
                song = a.first;
            }
        }
        for(int i = 0; i < 2; i++){
            int val = 0, idx = -1;
            for(auto a : num[song]){
                if(val < a.second){
                    val = a.second;
                    idx = a.first;
                }
            }
            if(idx == -1) break;
            answer.push_back(idx);
            num[song].erase(idx);
        }
        listen.erase(song);
    }
    return answer;
}


/*
����¥ �������.
�ؽô� ���� �� �̷� ���ΰ�,,
�� ���� ���� �ؽ� ������ ���� ���� �� ����. 
īī��ó�� ���ڿ��� �յ� ���� ������ ������ �ƴϾ��µ�,
unordered_map�ϰ� map�ϰ� �򰥷��� �ð��� ��ü�Ǿ���.
map�� �ڵ����� ������������ �ð��� ���� �� ���� �ɸ���,
unordered_map�� ������ �ȵ����� �ð��� ª�� ����
*/ 
