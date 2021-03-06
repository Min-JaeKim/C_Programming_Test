# Python

## baek 9012

https://www.acmicpc.net/problem/9012



> 128ms



* 문제

  > 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 
  >
  > 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 

* 입력

  > 입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 
  >
  > ```python
  > 6
  > (())())
  > (((()())()
  > (()())((()))
  > ((()()(()))(((())))()
  > ()()()()(()()())()
  > (()((())()(
  > ```
  >

* 출력

  > 출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 
  >
  > ```python
  > NO
  > NO
  > YES
  > NO
  > YES
  > NO
  > ```



```python
t = int(input())
count = 0

for _ in range(t):
    paren = input()
    count = 0
    for i in range(len(paren)):
        if paren[i] == '(':
            count += 1
        elif paren[i] == ')':
            count -= 1
        if count < 0:
            break
    if count == 0 :
        print('YES')
    else:
        print('NO')
```

> 자료구조 문제. 하지만 그 어떤 자료구조도 사용하지 않았다. 왜인지 계속 중간에 count<0을 한다음 no를 출력하고 break하려고 했던 것 때문에 헤맸다. 차라리 저기서 단순하게 break만 하고 나중에 yes와 함께출력문을 작성해 주면 금방 쉽게 끝날 문제였다.



* 모범답안

  ```python
  a = int(input())
  for i in range(a):
      b = input()
      s = list(b)
      sum = 0
      for i in s:
          if i == '(':
              sum += 1
          elif i == ')':
              sum -= 1
          if sum < 0:
              print('NO')
              break
      if sum > 0:
          print('NO')
      elif sum == 0:
          print('YES')
  ```

  > 이사람은 내가 계속 틀렸던 코드를 짰던 것처럼 바로 no를 출력해줬다.  한 가지 다른 점은 break를 걸고 나중에 출력하는 것을 sum이 0보다 클 때만 no를 출력하는 것으로 코드를 짜서, 나중에 0보다 작을때는 아예 출력을 안하게 해놓았다. 천재같다!