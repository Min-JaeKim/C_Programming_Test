#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int index = 0;
    int righthand = 12, lefthand = 10;
    for (auto a : numbers) if (a == 0) a = 11;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) numbers[i] = 11;
        if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            righthand = numbers[i];
        }
        else if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            lefthand = numbers[i];
        }
        else {
            if ((abs(numbers[i] - lefthand) / 3 + abs(numbers[i] - lefthand) % 3)
                < (abs(numbers[i] - righthand) / 3 + abs(numbers[i] - righthand) % 3)) {
                answer += "L";
                lefthand = numbers[i];
            }
            else if ((abs(numbers[i] - lefthand) / 3 + abs(numbers[i] - lefthand) % 3)
                > (abs(numbers[i] - righthand) / 3 + abs(numbers[i] - righthand) % 3)) {
                answer += "R";
                righthand = numbers[i];
            }
            else {
                if (hand == "right") {
                    answer += "R";
                    righthand = numbers[i];
                }
                else {
                    answer += "L";
                    lefthand = numbers[i];
                }
            }

        }
    }

    return answer;
}

/* �̰� ����� Ǫ�� �� �׷��� ���� �ŷĤ�����,
�켱 �߰��� �ִ� ���ڵ� �Ÿ��� ����ϴ� ��
(��ȭ��ȣ ���� - �޼�(������) ���紩���� �ִ� ����) / 3 
+
(��ȭ��ȣ ���� - �޼�(������) ���紩���� �ִ� ����) % 3
��� �� ������,, ��� ���� ������ ���ϴ� �͵� õ������ �ɷ��ε�,,
abs�� <cmath>��� STL�� �ʿ��ϴ�.
������ ���ϴ� �Լ���.
�׷� ��*/ 
