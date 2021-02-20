# SolveProblems

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

[3.Remote Control](https://github.com/KimUJin3359/SolveProblems/blob/master/RemoteControl/RemoteControl/main.cpp)
- [문제](https://www.acmicpc.net/problem/1107)
- 임의의 숫자 버튼이 고장난 리모컨이 존재
- 고장난 버튼을 제외하고 0~9까지의 숫자와 +/- 버튼이 존재할 때, 몇 번을 눌러야 최소한의 횟수로 원하는 채널을 볼 수 있는가
- 기존 채널 번호는 100번
- 접근 방법
  - BFS
  - 0번 부터 1000000번까지 만들 수 있는 모든 수에대해 계산
  - default 값과의 차(100번으로부터 +/-만 눌렀을 때)와 위의 만들어지는 횟수를 비교하여 최종 결론 도출
- 어려웠던 점 및 해결방법은 주석으로 정리  

[4.Amusement Park](https://github.com/KimUJin3359/SolveProblems/blob/master/AmusementPark.c)
- [문제](https://www.acmicpc.net/problem/1561)
- [초안](https://github.com/KimUJin3359/SolveProblems/blob/master/AmusementPark/AmusementPark/main.cpp)
- N명의 아이들이 M종류의 1인승 놀이기구를 타려함
- 놀이기구에는 1번부터 M번까지 번호가 정해져있고, 각각의 운행 시간이 정해져 있음
- N번째 아이가 타게 될 놀이기구의 번호를 출력
- 접근 방법
  - Brute-Force
    - 처음에는 입력받은 배열을 가지고, 시간의 흐름에 따라 타게 되는 아이들을 다 검색해서 계산을 해줌
    - N명의 아이들이 있을 때, 최대 N * 30M번의 경우(1개의 놀이기구만 30분을 간격으로 운영)를 봐줘야 할 경우가 될 수 있음으로 실행시간 초과 발생
  - Brute-Force
    - 입력받은 배열을 시간에 따라(1~30분) 해당 인원의 수를 계산해서 넣어줌
    - N명의 아이들이 있어도, 최대 30 * 30M번의 경우만 봐주면 됨
    - 위 계산의 결과가, 원하는 값을 초과했을 때 그 전으로 복귀해 계산
    - 많은 경우의 수를 줄였다고 생각했으나, 실행시간 초과 발생
  - Brute-Force + Binary Search
    - 위의 경우에도, 모든 시간값을 다 봐주게 된다면 최대 60000000000번을 봐줘야 되었었음
    - 이를 binary search로 시간 단축하였음
    - 자랑아닌 자랑이지만 **시간, 공간적으로 가장 적은 방법**으로 해결
![캡처(1)](https://user-images.githubusercontent.com/50474972/108233793-77d67880-7187-11eb-98df-781bdb9f6128.JPG)

[5.Subset Sum](https://github.com/KimUJin3359/SolveProblems/blob/master/SubsetSum.c)
- [문제](https://www.acmicpc.net/problem/1806)
- 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어짐
- 연속된 수들의 부분합 중, 그 합이 주어지는 값(S) 이상 되는 것 중 가장 짧은 것의 길이를 구하는 문제
- 접근 방법
  - DP 
    - 배열의 첫 번째 값에는 입력받은 값을 저장
    - 배열의 두 번째 값에는 S보다 작은 앞의 수들과의 합을 저장
    - index를 통해 시작 점을 잡아주고, 현재 읽은 수를 이 전의 합과 합쳤을 때 S를 넘는다면 index 값을 뺴주며 길이 확인

### Coding Test 준비(라이브러리 사용)

[6.Rich Project](https://github.com/KimUJin3359/SolveProblems/blob/master/RichProject/RichProject/main.cpp)
- [문제](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE)
- 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있음
- 하루 최대 1개만큼 구입할 수 있음
- 판매는 언제든지 할 수 있음
- 원재가 벌 수 있는 최대이익 계산
- 접근 방법
  - max priority queue를 사용하여, 최대 값의 index와 value를 저장함
  - queue에서 top에 있는 원소를 확인하여, 현재 index 값보다 뒤에 있는 경우 top 원소의 index 까지 차익을 계산해 더해감

[7.Pattern Length](https://github.com/KimUJin3359/SolveProblems/blob/master/PatternLength/PatternLength/main.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE)
- 각 문자열의 길이는 30
- 마디의 최대 길이는 10일 때, 마디의 최소 길이를 출력
- 접근 방법
  - 문자열의 길이에 따른 substring을 구함
  - find 함수로 문자열 끝까지 substring을 찾아갈 때, 결과 값이 발견했던 index + length 과 같으면 계속해서 탐색하고 같지 않을 시 다음 케이스를 확인
