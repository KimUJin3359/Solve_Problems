# SolveProblems

Study on 210205

#### 관련 문제

[1.Square Room](https://github.com/KimUJin3359/SolveProblems/blob/master/SquareRoom/SquareRoom/%EC%86%8C%EC%8A%A4.cpp)
- N^2개의 방이 존재
- 각 방에는 1이상 N^2 이하의 수가 적혀 있음
- 상하좌우에 있는 다른 방으로 이동할 수 있음(방 존재/ 이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 정확히 1 더 커야 이동 가능)
- 처음 어떤 수가 적힌 방에 있어야 가장 많은 개수의 방을 이동할 수 있는지 구하는 프로그램
- 접근 방식
  - BFS

[2.Work Division](https://github.com/KimUJin3359/SolveProblems/blob/master/WorkDivision/WorkDivision/main.cpp)
- N명의 직원과 N개의 일이 존재
- 직원들의 번호가 1부터 N까지 매겨져 있고, 해야할 일에도 번호가 1부터 N까지 매겨져 있을 때, i번 직원이 j의 일을 성공할 확률이 Pi,j
- 주어진 일이 모두 성공할 확률의 최댓값을 구하는 프로그램
- 접근 방식
  - greedy & DFS & Back tracking
    - DFS : 기본적으로 모든 가능 경우의 수를 순열을 사용해 전부 다 봐줘야 하는 문제
    - Back tracking : 현재 구한 확률 값이 구해진 결과값보다 작을 때 더이상 보지 않음(확률의 최대값 1, 다른 수가 곱해진다 해서 현재 가진결과값 보다 커질 수 없음)
    - greedy
      - 최악의 경우 tree상에 결과값(BFS)이 끝으로 갈수록 커진다면 모든 경우를 다 봐줘야 될 수 있음
      - 이를 대비하여, 처음 경우에 확률 중 큰 값 만을 찾아서 곱해 만든 결과값을 기준점으로 지정
