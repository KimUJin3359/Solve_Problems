# SolveProblems

### 코딩테스트 준비를 위한 알고리즘 문제 해결
- 업데이트 : 21.03.04(세부 로직 별 분류)
#### 코딩테스트가 목적이니 각 프로그램의 완성도보다는 주어진 시간 내에, 주어진 메모리를 가지고 통과하는데 초점을 둠
- 예시 : 스택, 힙에 잡히지 않는 전역변수를 주로 사용 

### 목차
- [알고리즘](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
- [완전탐색](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#%EC%99%84%EC%A0%84%ED%83%90%EC%83%89)
- [DFS 및 Back Tracking](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#dfs-%EB%B0%8F-back-tracking)
- [DP](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#dp)

---

### [알고리즘](https://github.com/KimUJin3359/Solve_Problems/tree/master/ALGORITHM)

[1. Amusement Park](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AmusementPark.c)
- [문제](https://www.acmicpc.net/problem/1561)
- [초안](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AmusementPark_First.cpp)
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

[2. Count Group(SW Expert Academy : 창용 마을 무리의 개수)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/CountGroup.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWngfZVa9XwDFAQU&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- 두 사람이 서로 아는 관계이거나 몇 사람을 거쳐서 알 수 있는 관계일 경우 같은 무리라고 함
- 몇 개의 무리가 존재하는지 계산하는 프로그램
- 접근 방법
  - Disjoint-set 사용

[3. Rich Project](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/RichProject.cpp)
- [문제](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE)
- 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있음
- 하루 최대 1개만큼 구입할 수 있음
- 판매는 언제든지 할 수 있음
- 원재가 벌 수 있는 최대이익 계산
- 접근 방법
  - max priority queue를 사용하여, 최대 값의 index와 value를 저장함
  - queue에서 top에 있는 원소를 확인하여, 현재 index 값보다 뒤에 있는 경우 top 원소의 index 까지 차익을 계산해 더해감

[4. Rolling Dice(Baekjoon : 주사위 굴리기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/RollingDice.cpp)
- [문제](https://www.acmicpc.net/problem/14499)
- 주사위를 굴림
- 동, 서, 남, 북 방향에 따라 주사위도 회전함
- 주사위를 옮길 때, 해당 지도의 값이 0이면 주사위 바닥면의 값이 지도의 값에 복사
- 주사위를 옮길 때, 해당 지도의 값이 0이 아니면 지도의 값이 주사위의 바닥면에 복사되고, 지도의 값은 0이 됨
- 주사위는 지도의 바깥으로 나갈 수 없음
- 접근 방법
  - 알고리즘 : 동, 서, 남, 북으로 이동할 때 해당 주사위가 바뀌는 규칙을 찾아 해당 값을 setting
  - 주사위과 동, 서, 남, 북으로 움직일 수 있기 때문에 배열을 사용해서 앞뒤를 한칸씩 밀어주는 것보다, deque를 사용한 push_front, push_back을 사용

---

### [완전탐색](https://github.com/KimUJin3359/Solve_Problems/tree/master/BRUTE_FORCE)

[1. Get Honey(SW Expert Academy : 벌꿀채취)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/GetHoney.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5V4A46AdIDFAWu&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3&&&&&&)
- 꿀을 채취할 수 있는 벌통의 수가 주어짐
- 두 명의 일꾼이 존재/ 각각의 일꾼은 가로로 연속되도록 주어진 수의 벌통만큼 벌통을 선택(겹치면 안됨)
- 일꾼이 채취할 수 있는 최대 꿀의 양이 주어짐
- 각 채취한 벌통의 제곱의 합이 최대가 되는 경우
- 접근 방법
  - 각 값을 제곱한 결과값을 저장
  - 새로운 배열을 만들어 비트 연산자를 활용해 만들 수 있는 최대 값을 계산
  - Brute-Force를 통해 겹치지 않는 두 개의 값 중 최대 값을 선택

[2. Middle Average](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/GetMiddleAverage.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq)
- 10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 프로그램
- 첫째 자리에서 반올림
- 접근 방법
  - 입력받으면서 최대, 최소값 찾기
  - 그를 제외한 나머지들의 합을 구해서 %연산을 활용하여 반올림

[3. Kill Flies](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/KillFlies.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&)
- 접근 방법
  - 각 범위의 사각형 만큼 합을 구해 최대값을 구함(brute force)
- 알게된 점
  - 동적할당은 정적할당보다 시간이 더 많이 걸림
  - 그렇기 때문에, 코딩 테스트에서는 동적할당보다 정적할당이 유용

[4. Pattern Length](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/PatternLength.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE)
- 각 문자열의 길이는 30
- 마디의 최대 길이는 10일 때, 마디의 최소 길이를 출력
- 접근 방법
  - 문자열의 길이에 따른 substring을 구함
  - find 함수로 문자열 끝까지 substring을 찾아갈 때, 결과 값이 발견했던 index + length 과 같으면 계속해서 탐색하고 같지 않을 시 다음 케이스를 확인

[5. Read Column](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/ReadColumn.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVWgkP6sQ0DFAUO)
- 다섯개의 단어가 주어짐
- 단어의 길이는 서로 다를 수 있음
- 이를 세로로 읽었을 때 나오는 문자열을 구하는 문제
- 접근 방법
  - 읽은 값이 0일 때를 제외하고, 문자열에 이어 붙임

[6. Subset Sum](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/SubsetSum.c)
- [문제](https://www.acmicpc.net/problem/1806)
- 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어짐
- 연속된 수들의 부분합 중, 그 합이 주어지는 값(S) 이상 되는 것 중 가장 짧은 것의 길이를 구하는 문제
- 접근 방법
  - DP 
  - 배열의 첫 번째 값에는 입력받은 값을 저장
  - 배열의 두 번째 값에는 S보다 작은 앞의 수들과의 합을 저장
  - index를 통해 시작 점을 잡아주고, 현재 읽은 수를 이 전의 합과 합쳤을 때 S를 넘는다면 index 값을 뺴주며 길이 확인

[7. Vertificate Sudoku](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/VertificateSudoku.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq)
- 접근 방법
  - 행, 열, 사각형을 기준으로 각 원소가 정확히 1~9까지 중복되지 않고 존재하는지 확인(brute force)

[8. Where To Insert](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/WhereToInsert.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq)
- 접근 방법
  - 행, 열에 따라 문자가 들어갈 수 있는 길이를 구하여, 원하는 값과 같을 시 결과값을 더하기 1(brute force)

[9. Home Security Service(SW Expert Academy : 홈 방범 서비스)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/HomeSecurityService.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5V61LqAf8DFAWu&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=++3+)
- N * N 크기의 도시가 존재
- 마름모 모양의 영역에만 홈방범 서비스를 제공
- 보안회사에서 손해를 보지 않으면서 최대한 많은 집에 홈방범 서비스를 제공하려할 때, 제공받는 가구의 수
- 접근
  - Brute Force
  - 맵을 다채우는 마름모의 크기 (3 / 2) * N 부터 2의 크기까지 모두 확인
  - 1의 크기는 기본적으로 모든 마을에서 만족함(홍방범 서비스의 비용 1, 가구 지불비용 최소 1)

[10. Launch Time(SW Expert Academy : 점심 식사시간)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/LaunchTime.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5-BEE6AK0DFAVl&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=3)
- 두 개의 계단이 존재
- 최대 3명의 학생만이 계단을 이용할 수 있고, 한명이 다 쓰고난 후 다음 사람이 쓸 수 있음
- 모든 사람이 다 내려갈 수 있는 최소 시간 구하기
- 접근
  - Brute Force
  - 각 사람들이 계단1, 계단2로 이동하는 모든 경우의 수를 계산
  - 실행시간을 단축시키기 위해 bit 연산자 사용
  - priority queue를 사용해 각 계단에 도착하는 최소 시간의 사람을 구해서 그 사람들 부터 내려보냄

---

### [DFS 및 Back Tracking](https://github.com/KimUJin3359/Solve_Problems/tree/master/DFS%26BACKTRACKING)

[1. Cooking(SW Expert Academy : 요리사)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/Cooking.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWIeUtVakTMDFAVH&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3)
- N개의 식재료가 주어짐
- 식재료들을 N / 2개씩 나누어 두개의 요리를 함
- A음식과 B음식의 맛의 차이가 최소가 되도록 재료를 배분하는 문제
- 접근 방법
  - DFS : 순열

[2. Make Number(SW Expert Academy : 숫자 만들기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/MakeNumber.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWIeRZV6kBUDFAVH&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- n개의 숫자와 n - 1개의 연산자를 입력받아 만들 수 있는 maximum, minimum의 차를 출력하는 문제
- 연산자의 우선 순위는 고려하지 않음
- 접근 방법
  - Back tracking
  - 깊이 우선탐색을 하지만 이전에 결과를 도출했던 연산자를 또 사용하지 않음
  - (n - 1)개의 연산자 중 중복되는 연산자가 다수 존재/ 중복 배제

[3. Remote Control](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/RemoteControl.cpp)
- [문제](https://www.acmicpc.net/problem/1107)
- 임의의 숫자 버튼이 고장난 리모컨이 존재
- 고장난 버튼을 제외하고 0~9까지의 숫자와 +/- 버튼이 존재할 때, 몇 번을 눌러야 최소한의 횟수로 원하는 채널을 볼 수 있는가
- 기존 채널 번호는 100번
- 접근 방법
  - BFS
  - 0번 부터 1000000번까지 만들 수 있는 모든 수에대해 계산
  - default 값과의 차(100번으로부터 +/-만 눌렀을 때)와 위의 만들어지는 횟수를 비교하여 최종 결론 도출
- 어려웠던 점 및 해결방법은 주석으로 정리  

[4.Square Room](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/SquareRoom.cpp)
- N^2개의 방이 존재
- 각 방에는 1이상 N^2 이하의 수가 적혀 있음
- 상하좌우에 있는 다른 방으로 이동할 수 있음(방 존재/ 이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 정확히 1 더 커야 이동 가능)
- 처음 어떤 수가 적힌 방에 있어야 가장 많은 개수의 방을 이동할 수 있는지 구하는 프로그램
- 접근 방식
  - BFS

[5. Swimming Pool(SW Expert Academy : 수영장)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/SwimmingPool.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PpFQaAQMDFAUq&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- 일간, 월간, 3월간, 연간 이용권이 존재할 때 최소 비용으로 수영장을 이용할 떄의 요금을 구하는 문제
- 접근 방법
  - Back tracking
  - 일간 이용권(개장 일 수 * 일간 이용권 가격), 월간 이용권을 비교하여 월간 이용권의 가격이 더 비싼 경우 해당 case를 확인하지 않음

[6. Work Division](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/WorkDivision.cpp)
- N명의 직원과 N개의 일이 존재
- 직원들의 번호가 1부터 N까지 매겨져 있고, 해야할 일에도 번호가 1부터 N까지 매겨져 있을 때, i번 직원이 j의 일을 성공할 확률이 Pi,j
- 주어진 일이 모두 성공할 확률의 최댓값을 구하는 프로그램
- 접근 방식
  - DFS : 기본적으로 모든 가능 경우의 수를 순열을 사용해 전부 다 봐줘야 하는 문제
  - Back tracking : 현재 구한 확률 값이 구해진 결과값보다 작을 때 더이상 보지 않음(확률의 최대값 1, 다른 수가 곱해진다 해서 현재 가진결과값 보다 커질 수 없음)
  - greedy
    - 최악의 경우 tree상에 결과값(BFS)이 끝으로 갈수록 커진다면 모든 경우를 다 봐줘야 될 수 있음
    - 이를 대비하여, 처음 경우에 확률 중 큰 값 만을 찾아서 곱해 만든 결과값을 기준점으로 지정

[7. Mountain Route(SW Expert Academy : 등산로 조성)]()
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PoOKKAPIDFAUq&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=++3+)
- 높은 곳(가장 높은 봉우리에서 시작)부터 낮은 곳을 길을 만들 때 최대 길이
- 입력받은 K의 높이만큼 딱 한번 길을 깎을 수 있음
- 접근 방식
  - DFS : 기본적으로 모든 경우의 수를 다 봐줘야 되는 문제

---

### [DP](https://github.com/KimUJin3359/Solve_Problems/tree/master/DP)

[1. Catch Runner(SW Expert Academy : 탈주범 검거)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/CatchRunner.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PpLlKAQ4DFAUq&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3)
- 탈주범의 출발 지점이 주어짐, 출발 시간이 1
- 1시간 마다 연결된 경로로 이동 가능
- 파이프의 모양에 따라 이동이 가능할 수도, 불가능할 수도 있음
- 주어진 시간 후 탈주범이 있을 수 있는 모든 공간의 수를 구하는 문제
- 접근 방법
  - 각 지점으로 이동할 수 있는지를 체크
  - DP : 각 지점에 도착할 수 있는 최소 시간을 입력
  - 최소 시간이 주어진 시간보다 작거나 같은 경우를 셈

[2. Pascal Triangle](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/PascalTriangle.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P0-h6Ak4DFAUq)
- 크기가 N인 파스칼 삼각형 만들기
  - 첫 번째 줄은 항상 1
  - 두 번째 줄부터 각 숫자들은 자신의 왼쪽과 오른쪽 위의 숫자의 합으로 구성
- 접근 방법
  - 1 ~ 10의 결과값을 만들어둔다
  - 입력 받는 값에 따라, 출력
  - 개선 방안
    - 문제를 풀면서 채워놓고, 값이 존재하지 않을 때만 추가적으로 더 해를 구하기(DP)

[3. Leave(백준 : 퇴사)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/Leave.cpp)
- [문제](https://www.acmicpc.net/problem/14501)
- 접근 방법
  - DP
  - 첫째 날부터 일을 했을 경우의 결과 값을 일이 끝나는 날에 적음
  - 당일에 도착했을 때, 전날의 값과 현재의 값을 비교하여 더 큰 값으로 DP 배열을 세팅해감
  - N째 날에 도착했을 때의 값이 maximum이 됨

[4. Integer Triangle(백준 : 정수 삼각형)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/IntegerTriangle.cpp)
- [문제](https://www.acmicpc.net/problem/1932)
- 맨 위층부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 선택된 수의 합이 최대가 되는 경로를 구하는 문제
- 접근 방법
  - DP
  - 맨마지막의 윗층부터, 꼭대기층까지 Bottom-up 방식으로 선택가능한 숫자들 중 가장 큰 숫자를 자기 자신에게 더해감

[5. Subset Sum4(백준 : 구간 합 구하기 4)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/SubsetSum4.cpp)
- [문제](https://www.acmicpc.net/problem/11659)
- 수 N개가 주어졌을 때, i번째부터 j번째 수까지 합을 구하는 문제
- 접근 방법
  - DP
  - 숫자를 입력받으면서 그 전까지의 합 + 입력받은 숫자로 배열 초기화
  - j번째 - (i - 1)번째 값이 i번째부터 j번째 수 까지의 합이 됨

[6. Subset Sum5(백준 : 구간 합 구하기 5)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/SubsetSum5.cpp)
- [문제](https://www.acmicpc.net/problem/11660)
- N * N개의 수가 주어졌을 때, (x1, y1)부터 (x2, y2)까지의 합을 구하는 문제
- 접근 방법
  - DP
  - 숫자를 입력받으면서 행 기준으로 그 전까지의 합 + 입력받은 숫자로 배열 초기화
  - 그 후 열 기준으로 위 index 값 + 현재 index 값으로 초기화
    - 사각형의 합이 표에 채워짐
  - (x2, y2) 사각형 - (x1, y2) 사각형 - (x2, y1) 사각형 + (x1, y1) 사각형

[7. Climb Stairs(백준 : 계단 오르기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/ClimbStairs.cpp)
- [문제](https://www.acmicpc.net/problem/2579)
- 계단은 한 번에 한 계단 or 두 계단씩 오를 수 있음
- 연속된 세 개의 계단을 모두 밟으면 안됨
- 마지막 도착 계단은 반드시 밟아야 됨
- 맨 마지막 계단을 밟을 때의 최대 점수를 구하는 문제
- 접근 방법
  - DP(점화식)
  - 현재 밟는 계단의 최대 값을 구할 때
    1) 현재 밟고있는 계단의 두개 전 계단 까지의 최대값 + 현재 계단의 값
    2) 현재 밟고있는 계단의 세개 전 계단 까지의 최대값 + 현재 계단 한개 전 계단의 값 + 현재 계단의 값 

[8. Get Biggest Square(백준 : 가장 큰 정사각형)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/GetBiggestSquare.cpp)
- [문제](https://www.acmicpc.net/problem/1915)
- n * m의 0, 1로된 배열이 존재
- 이 배열에서 1로 구성된 가장 큰 정사각형의 크기를 구하는 문제
- 접근 방식
  - DP(점화식)
  - 왼쪽, 위쪽, 대각선 위쪽 중 만들어지는 사각형의 값이 가장 작은 경우 + 1
  ```
  0010
  1110
  1100
  1111
  - (3, 2)의 상황에서 대각선 위는 두 칸의 정사각형, 왼쪽은 두 칸의 정사각형을 가지고 있지만
  - 위쪽에서 0칸을 가지고 있기 때문에 최대 1의 정사각형밖에 만들지 못함
  ```
