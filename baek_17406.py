# Python

## baek 17406 배열 돌리기 4골드4

https://www.acmicpc.net/problem/17406



> python3 1072ms



* 문제

  > 크기가 N×M 크기인 배열 A가 있을때, 배열 A의 값은 각 행에 있는 모든 수의 합 중 최솟값을 의미한다. 배열 A가 아래와 같은 경우 1행의 합은 6, 2행의 합은 4, 3행의 합은 15이다. 따라서, 배열 A의 값은 4이다.
  >
  > ```
  >1 2 3
  > 2 1 1
  > 4 5 6
  > ```
  > 
  > 배열은 회전 연산을 수행할 수 있다. 회전 연산은 세 정수 (r, c, s)로 이루어져 있고, 가장 왼쪽 윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다는 의미이다. 배열의 칸 (r, c)는 r행 c열을 의미한다.
  > 
  > 예를 들어, 배열 A의 크기가 6×6이고, 회전 연산이 (3, 4, 2)인 경우에는 아래 그림과 같이 회전하게 된다.
  >    
  > ```
  >A[1][1]   A[1][2] → A[1][3] → A[1][4] → A[1][5] → A[1][6]
  >              ↑                                       ↓
  >A[2][1]   A[2][2]   A[2][3] → A[2][4] → A[2][5]   A[2][6]
  >              ↑         ↑                   ↓         ↓
  > A[3][1]   A[3][2]   A[3][3]   A[3][4]   A[3][5]   A[3][6]
  >              ↑         ↑                   ↓         ↓
  > A[4][1]   A[4][2]   A[4][3] ← A[4][4] ← A[4][5]   A[4][6]
  >              ↑                                       ↓
  > A[5][1]   A[5][2] ← A[5][3] ← A[5][4] ← A[5][5] ← A[5][6]
  > 
  >    A[6][1]   A[6][2]   A[6][3]   A[6][4]   A[6][5]   A[6][6]
  > ```
  >
  > 회전 연산이 두 개 이상이면, 연산을 수행한 순서에 따라 최종 배열이 다르다.
  >
  > 다음은 배열 A의 크기가 5×6이고, 회전 연산이 (3, 4, 2), (4, 2, 1)인 경우의 예시이다.
  > 
  > | `1 2 3 2 5 6 3 8 7 2 1 3 8 2 3 1 4 5 3 4 5 1 1 1 9 3 2 1 4 3` | `1 8 2 3 2 5 3 2 3 7 2 6 8 4 5 1 1 3 3 3 1 1 4 5 9 2 1 4 3 1` | `1 8 2 3 2 5 3 2 3 7 2 6 3 8 4 1 1 3 9 3 5 1 4 5 2 1 1 4 3 1` |
  > | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  > | 배열 A                                                       | (3, 4, 2) 연산 수행 후                                       | (4, 2, 1) 연산 수행 후                                       |
  > | `1 2 3 2 5 6 3 8 7 2 1 3 8 2 3 1 4 5 3 4 5 1 1 1 9 3 2 1 4 3` | `1 2 3 2 5 6 3 8 7 2 1 3 3 8 2 1 4 5 9 4 3 1 1 1 3 2 5 1 4 3` | `1 8 2 3 2 5 3 8 2 7 2 6 3 4 3 1 1 3 9 2 1 1 4 5 3 5 1 4 3 1` |
  > | 배열 A                                                       | (4, 2, 1) 연산 수행 후                                       | (3, 4, 2) 연산 수행 후                                       |
  >    
  > 배열 A에 (3, 4, 2), (4, 2, 1) 순서로 연산을 수행하면 배열 A의 값은 12, (4, 2, 1), (3, 4, 2) 순서로 연산을 수행하면 15 이다.
  >
  > 배열 A와 사용 가능한 회전 연산이 주어졌을 때, 배열 A의 값의 최솟값을 구해보자. 회전 연산은 모두 한 번씩 사용해야 하며, 순서는 임의로 정해도 된다.
  
* 입력

  > 첫째 줄에 배열 A의 크기 N, M, 회전 연산의 개수 K가 주어진다.
  >
  > 둘째 줄부터 N개의 줄에 배열 A에 들어있는 수 A[i][j]가 주어지고, 다음 K개의 줄에 회전 연산의 정보 r, c, s가 주어진다.
  >
  > ```bash
  > 5 6 2
  > 1 2 3 2 5 6
  > 3 8 7 2 1 3
  > 8 2 3 1 4 5
  > 3 4 5 1 1 1
  > 9 3 2 1 4 3
  > 3 4 2
  > 4 2 1
  > ```

* 출력

  > 배열 A의 값의 최솟값을 출력한다.
  >
  > ```bash
  > 12
  > ```

* 제한

  >- 3 ≤ N, M ≤ 50
  >- 1 ≤ K ≤ 6
  >- 1 ≤ A[i][j] ≤ 100
  >- 1 ≤ s
  >- 1 ≤ r-s < r < r+s ≤ N
  >- 1 ≤ c-s < c < c+s ≤ M

```python
import itertools

n, m, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
oper, permuoper, result = [], [], 50 * 100
for _ in range(k):
    o, tw, th = map(int, input().split())
    oper.append([o, tw, th])

for i in list(list(itertools.permutations(oper))):
    tmp1 = [row[:] for row in arr]
    permuoper.append(i)
    for j in range(k):
        tmp2 = [row[:] for row in tmp1]
        r, c, s = permuoper[0][j]
        row, col, rowlimit, collimit = r - s - 1, c - s - 1, r + s - 1, c + s - 1
        flag = 2 * s
        while flag > 1:
            for i in range(col, collimit):
                tmp2[row][i + 1] = tmp1[row][i]
            for i in range(row, rowlimit):
                tmp2[i + 1][collimit] = tmp1[i][collimit]
            for i in range(collimit, col, -1):
                tmp2[rowlimit][i - 1] = tmp1[rowlimit][i]
            for i in range(rowlimit, row, - 1):
                tmp2[i - 1][col] = tmp1[i][col]
            flag -= 2
            col, collimit = col + 1, collimit - 1
            row, rowlimit = row + 1, rowlimit - 1
        tmp1 = [row[:] for row in tmp2]
    for i in range(len(tmp1)):
        if result > sum(tmp1[i]):
            result = sum(tmp1[i])
    permuoper = []

print(result)
```

> 불태웠다 증말,,, 배열 돌리기가 어려울 것 같아서 시도조차 망설이고 있었는데 복병은 따로 있었다. 바로바로,, 순열과 배열 복사이다..
>
> * __for i in list(list(itertools.permutations(oper))):__ 이런식으로 순열을 뽑아내야 한다. 사실 문제에 주어진대로 계산하면 되는 줄 알았는데, 알고보니 경우의 수를 따져가며 최솟값을 구하는 문제였다. ㅜㅜ
>
>   이렇게 하면 ([(3,4,3), (4,2,1)]) 이렇게 하나로 치며 리스트에 append를 하게 된다. 그걸 또 반복문을 돌려서 [ 0] [1] 이런식으로 뽑아내야 한다. 그래야 r, c, s = 3, 4, 1 과 같이 변수에 들어간다.
>
> * __copy.deepcopy()__ : deepcopy 때문에 시간초과가 났다. 따라서 deepcopy는 코테에서 지양해야할 코드다. 
>
>   -> __tmp1 = [row[:] for row in tmp2]__ 이런식으로 행을 [:] 받는 코드를 사용할 것.



* 모범답안

  ```python
  720
  
  from itertools import permutations
  
  N, M, K = map(int, input().split())
  arr = [list(map(int, input().split())) for _ in range(N)]
  total_rotations = []
  for _ in range(K):
      r, c, s = map(int, input().split())
      total_rotations.append((r - 1, c - 1, s))
  
  
  def rotate(arr, r, c, s):
      for k in range(1, s + 1):
          temp = arr[r - k + 1][c - k]
          for i in range(r - k + 2, r + k + 1):
              arr[i - 1][c - k] = arr[i][c - k]
          for j in range(c - k + 1, c + k + 1):
              arr[r + k][j - 1] = arr[r + k][j]
          for i in range(r + k - 1, r - k - 1, -1):
              arr[i + 1][c + k] = arr[i][c + k]
          for j in range(c + k - 1, c - k - 1, -1):
              arr[r - k][j + 1] = arr[r - k][j]
          arr[r - k][c - k] = temp
  
  
  def arr_value(arr):
      return min([sum(row) for row in arr])
  
  
  ret = 1e9
  for rotations in permutations(total_rotations):
      arr_ = [row[:] for row in arr]
      for r, c, s in rotations:
          rotate(arr_, r, c, s)
      ret = min(ret, arr_value(arr_))
  print(ret)
  
  ```

  > * __for rotations in permutations(total_rotations)__
  > * __for r, c, s in rotations__ 
  >
  > 아주 멋진 코드, 되도록 함수를 쓰셨는데, 나도 이제 함수를 쓰는 걸 익히는 게 중요해 보인다.

