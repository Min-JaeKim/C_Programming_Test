#include <string>
 
using namespace std;
 
int solution(string name) {
    int answer = 0, i = 0;
    string temp(name.length(), 'A');
    while (true) {
        temp[i] = name[i]; 
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        if (temp == name)    break; // 빠뜨리지 말것 제일 중요 
        for (int move = 1; move < name.length(); move++) {
            if (name[(i + move) % name.length()] != temp[(i + move) % name.length()]) {
                i = (i + move) % name.length();
                answer += move;
                break;
            }
            else if (name[(i + name.length() - move) % name.length()] 
                != temp[(i + name.length() - move) % name.length()]) {
                i = (i + name.length() - move) % name.length();
                answer += move;
                break;
            }
        }
    }
    return answer;
}

//이 문제는 솔직히 ,, 너무 어렵다.(그래서 구글링했다)
// 외우거나 포기하거나 둘 중 하나인듯. 
