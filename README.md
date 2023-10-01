# DataStructures
Assignments

1. 스택연산.c 설명
다음 수식을, array와 linked list를 써서 수업 시간에 배운 2개의 stack을 써서, 각각 (1), (2)를 지시된 데이터구조로 설정한 후 program하시오.

A. ( 3 * ( 20 + 10 ) ) – ( 20 / 5 + ( 4 * 2 ) / 2 ) + 8
 2종의 stack을 Array로 구조를 잡아서 프로그램
B. 2 * ( 10 + 15 * 3 – 5 ) + ( ( 30 / 3 - ( 4 / 2 ) * 3 ) + 8 ) + 6, 답은 110 
2종의 stack을 Linked List로 구조를 잡아서 프로그램

2. 수건돌리기.c 설명
- 15명 (1번~15번 사람들)이 눈을 가리고 수건 돌리기를 한다. (이들은 01-Kim, 02-Lee, 03-Choi, 04-Yoon, …, 15-Park 등이다)
- 최종 3명이 남을 때까지 수건 돌리기 게임을 계속 한다.
- 게임 rule은 다음과 같다.
- 처음에 15명의 사람은 자신의 고유 숫자 순서대로 원형의 단 방향 (Single) circle를 형성하고 서 있다.
- 이때, 모두가 보는 가운데 제비 뽑아 임의의 번호를 고른다. 이는, 제일 먼저 수건을 가질 사람을 뽑는 것이다 (이 부분은 Random Number 함수로
프로그램 하면 된다).
- 그 사람의 번호 즉, 제비로 뽑힌 해당 번호를 포함해서 3번째 사람은 그 circle에서 빠진다 (예를 들어, 임의로 뽑았는데 1번-Kim이 뽑혔다고 한다면, 수건을 돌리면, 3번 사람, 03-Choi가 걸리게 되고, circle에서 빠진다. u 빠졌으니, 그 수건은 옆 사람인 04-Yoon이 전달받는다. 그리고, 04번부터동일한 과정을 계속한다. 그 다음 빠질 사람은 06번이다. 이와 같은 과정을 거쳐 점차 인원이 빠져서 원에 최종 3명 만 남을 때까지이 과정을 반복한다.)
- 이러한 과정을 계속 진행하다가, 최종 3인이 남으면, 그들의 번호와 이름을 출력하는 프로그램을 Linked List로 작성하시오.
- 수건 돌리기 circle에서 빠지는 사람이 발생할 때마다, 빠진 사람의 번호와 이름을 출력하고, 현재 남아 있는 사람들의 List도 매번 출력한다. 이러한 방법으로 마지막 3인이 남을 때까지 각 단계의 사람들(번호, 이름)를 print하시오.
-  최종 남은 행운의 3명을 답으로 출력

3. 다음 30개의 값 (7, 15, 24, 26, 42, 51, 55, 56, 59, 66, 67, 69, 8, 11, 43, 49, 48, 12, 14, 1, 3, 80, 
96, 99, 5, 6, 70, 71, 73, 75)이 키(key)로 주어졌다. 순서대로 받아들여 linked list를 형성한 후, 아래에 지시한 정렬 방식을 사용하여 장렬히고, 검색한다.
- [정렬, 4점] 30개의 수를 입력으로 받아, 이를 선택 정렬(selection sort)로 정렬 하시오.
- [검색, 4점] 수업 시간에 배운 3차시에 학습한 이진 탐색(Binary Search) 프로그램을 구현하시오.
  [검증 방법] 상기 정렬된 linked list에 다음 10개의 숫자가 존재하는지 확인한다. 검색 결과는 (1) ~ (10)의 각 항목별로 답을 하시오. 검색 결과,
  (A) 리스트에 숫자가 존재하면, True, 존재하지 않으면 False를 프린트하고, 연이어,
  (B) 해당 수가 리스트 내에 존재한다면, 그 숫자가 몇 번째 노드에 존재하는지를 프린트한다.
  만약, 리스트 내에 숫자가 없으면 “No Result in List”를 프린트하는 프로그램을 작성한다. 
  
