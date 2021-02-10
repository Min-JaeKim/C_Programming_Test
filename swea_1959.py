# python

## swea d2 1959 두 개의 숫자열

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpoFaAS4DFAUq&categoryId=AV5PpoFaAS4DFAUq&categoryType=CODE&problemTitle=1959&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1



> ms



* 문제

  > N 개의 숫자로 구성된 숫자열 Ai (i=1~N) 와 M 개의 숫자로 구성된 숫자열 Bj (j=1~M) 가 있다.
  >
  > 아래는 N =3 인 Ai 와 M = 5 인 Bj 의 예이다.
  >
  > ![img](md-images/fileDownload.do)
  > Ai 나 Bj 를 자유롭게 움직여서 숫자들이 서로 마주보는 위치를 변경할 수 있다.
  >
  > 단, 더 긴 쪽의 양끝을 벗어나서는 안 된다.
  >  
  >
  > ![img](md-images/fileDownload.do)
  >
  > 
  > 서로 마주보는 숫자들을 곱한 뒤 모두 더할 때 최댓값을 구하라.
  >
  > 위 예제의 정답은 아래와 같이 30 이 된다.
  >  
  >
  > ![img](md-images/fileDownload.do)
  >
  > 
  > **[제약 사항]**
  >
  > N 과 M은 3 이상 20 이하이다.

* 입력

  > 가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
  >
  > 각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,
  >
  > 두 번째 줄에는 Ai,
  >
  > 세 번째 줄에는 Bj 가 주어진다.
  >
  > ```bash
  > 10
  > 3 5
  > 1 5 3
  > 3 6 -7 5 4
  > 7 6
  > 6 0 5 5 -1 1 6
  > -4 1 8 7 -9 3
  > ...
  > ```

* 출력

  > 출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
  >
  > (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
  >
  > ```bash
  > #1 30
  > #2 63
  > ...
  > ```



* 제출

  ```python
  157ms
  
  import sys
  sys.stdin = open('./input.txt')
  
  testCase = int(input())
  for tc in range(1,testCase+1):
      len1,len2 = map(int,input().split())
      len1 = list(map(int, input().split()))
      len2 = list(map(int, input().split()))
      max = 0
      if (len(len1) <= len(len2)):
          for i in range(len(len2)-len(len1)+1):
              sum = 0
              for j in range(len(len1)):
                  sum += len2[i+j] * len1[j]
              if sum > max:
                  max = sum
      else :
          for i in range(len(len1) - len(len2) + 1):
              sum = 0
              for j in range(len(len2)):
                  sum += len1[i + j] * len2[j]
              if sum > max:
                  max = sum
      print("#%d %d" % (tc, max))
  ```

  > 내가 시간이 엄청 많이 나왔더라.. 좀 자괴감 들었음



* 모범답안

  ```python
  123ms
  
  T = int(input())
   
  for tc in range(1, T+1):
      n, m = map(int, input().split())
      a = list(map(int, input().split()))
      b = list(map(int, input().split()))
   
      if n > m:
          n, m = m, n
          a, b = b, a
   
      result = 0
      for case in range(m-n+1):
          total = 0
          for i in range(n):
              total += a[i] * b[i+case]
          if total > result:
              result = total
   
      print('#{} {}'.format(tc, result))
  ```
  
  > 대박이다. 크기 비교를 애초에 먼저 해서 바꾼 다음 차분하게 푸셨다 대박대박..