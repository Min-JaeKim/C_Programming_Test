# python

## baek 5557 일학년 골드5

https://www.acmicpc.net/problem/5557

> python3 68ms
>
> pypy3 128ms



* 문제

  > 상근이가 1학년 때, 덧셈, 뺄셈을 매우 좋아했다. 상근이는 숫자가 줄 지어있는 것을 보기만 하면, 마지막 두 숫자 사이에 '='을 넣고, 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만들며 놀고 있다. 예를 들어, "8 3 2 4 8 7 2 4 0 8 8"에서 등식 "8+3-2-4+8-7-2-4-0+8=8"을 만들 수 있다.
  >
  > 상근이는 올바른 등식을 만들려고 한다. 상근이는 아직 학교에서 음수를 배우지 않았고, 20을 넘는 수는 모른다. 따라서, 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다. 예를 들어, "8+3+2-4-8-7+2+4+0+8=8"은 올바른 등식이지만, 8+3+2-4-8-7이 음수이기 때문에, 상근이가 만들 수 없는 등식이다.
  >
  > 숫자가 주어졌을 때, 상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오.

* 입력

  > 첫째 줄에 숫자의 개수 N이 주어진다. (3 ≤ N ≤ 100) 둘째 줄에는 0 이상 9 이하의 정수 N개가 공백으로 구분해 주어진다.
  >
  > ```python
  > 11
  > 8 3 2 4 8 7 2 4 0 8 8
  > ```
  >
  > 

* 출력

  > 첫째 줄에 상근이가 만들 수 있는 올바른 등식의 개수를 출력한다. 이 값은 263-1 이하이다.
  >
  > ```python
  > 10
  > ```



```python
'''
11
8 3 2 4 8 7 2 4 0 8 8

0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 -> 1번째 인덱스의 경우의 수 (5, 11)
0 0 0 1 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 -> 2번째 인덱스의 경우의 수 (2, 7, 9, 13)
0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0 -> 3번째 인덱스의 경우의 수 (6, 3, 11, 5, 13, 9, 17)
0 1 0 1 0 1 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0
0 0 1 0 1 0 1 0 2 0 2 0 2 0 0 0 1 0 1 0 1
1 0 1 0 2 0 3 0 3 0 4 0 2 0 3 0 1 0 2 0 1
2 0 3 0 4 0 5 0 4 0 6 0 4 0 6 0 3 0 3 0 1
4 0 6 0 8 0 10 0 8 0 12 0 8 0 12 0 6 0 6 0 2
8 0 12 0 8 0 12 0 10 0 12 0 10 0 10 0 8 0 12 0 8
'''

import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = [[0] * 21 for _ in range(n)]
dp[0][arr[0]] = 1
for i in range(1, n-1): # 경우의 수 저장하는 단계.
    for j in range(21):
        if dp[i-1][j]: 
            if j + arr[i] < 21 : dp[i][j + arr[i]] += dp[i-1][j]
            if 0 <= j - arr[i] : dp[i][j - arr[i]] += dp[i-1][j]
print(dp[n-2][arr[-1]])
```

> 어떻게 이래
>
> 이거 푼 사람 진짜 천재같다... 하..
>
> 사실 나는 이거 재귀로 계속했다. 분명 프로그래머스에서 그렇게 푼 문제가 있었던 것 같아서 그때의 방식을 고대로 사용했다.
>
> 그런데 시간초과가 났다. 그래서 질문검색을 찾아보니 메모이제이션을 사용하라고 하셨다.  그래서 엉망진창 메모이제이션을 만들었다. 반복문을 돌며 다음수로 넘어가기 전에 이미 그 수를 더하거나 뺐을 때 과거에 동일했던 결과값이 있으면 재귀로 넘어가지 않고 인덱스를 다음으로 옮기는 방식이었다.
>
> 하지만 이게 꽤 복잡한 방식이었고, 이것 때문에 헛발질을 오랜 시간 하였다. 결국 짧은 예제 입력부터 해보려고 답안을 찾아다녔는데.. 아뿔싸 이게 너무 짧아서 충격적이었다. 보자마자 충격먹었고 내 코드를 고치고자 하는 의지를 멎게 하였다. ㅠㅠ 그래서 결국 이코드를 모방했고,, 결론적으로 한층 배울 수 있는 시간이 되었다.



* 모범답안

  ```python
  
  ```

  > 
