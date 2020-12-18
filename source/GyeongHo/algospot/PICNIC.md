# PICNIC

**문제**

안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다. 원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다. 그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에, 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.

각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다. 예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.

(태연,제시카) (써니,티파니) (효연,유리)
(태연,제시카) (써니,유리) (효연,티파니)
입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과 친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다. 그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 학생들의 수는 짝수입니다.

**출력**

각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.

**예제 입력**

> 3  
> 2 1  
> 0 1  
> 4 6  
> 0 1 1 2 2 3 3 0 0 2 1 3  
> 6 10  
> 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5  

**예제 출력**

> 1  
> 3  
> 4  

# 풀이

경우의 수를 구하는 문제. 재귀호출을 통한 완전탐색법을 시험해보자.
재귀 호출 문제를 풀이할 때, 두 가지를 정해야 한다.

1. subcase
2. 기저 사례

subcase의 경우, "짝을 짓지 못한 학생들을 짝짓는 방법의 수를 계산"이 되겠고
기저사례의 경우, "모든 학생들이 짝을 지었을 때"가 되겠다.

subcase 경우의 수를 얻기 위해 재귀함수 내부에 경우의 수를 담는 변수를 생성하고 기저사례를 만족했을 때마다 그 변수에 1을 더하면 된다.
기저사례를 확인하기 위해, 학생들의 수만큼의 bool을 담는 배열을 만들어 그 배열의 모든 원소가 true일 때 1을 반환하게 한다.

시간 제한이 1초이므로 $O(n^4)$까지가 최선이다.

또, 애를 먹었던 부분 중 하나인데 모든 학생들이 짝을 짓게 된 배열이 되든 짓지 못하는 배열이 되든간에 바로 직전의 시도로 돌아가서 첫 번째 친구는 그대로 두고 두 번째 친구를 다음 순서로 넘겨야 하는데
이건 재귀호출하는 부분의 바로 뒷 부분에 false로 되돌리면 다음 예시를 찾도록 넘길 수가 있다.

``` c++
#include <iostream>
using namespace std;


bool areFriends[10][10];

int count(bool* studentList, int n)
{
	int cases = 0;
	int index = -1;
	for(int i = 0; i < n; ++i) {
		if(!studentList[i]) {
			index = i;
			break;
		}
	}
	
	if(index == -1) return ++cases;
	
	for(int j = index + 1; j < n; ++j) {
		if(areFriends[index][j] && !studentList[j]) {
			studentList[index] = true;
			studentList[j] = true;
			cases += count(studentList, n);
			studentList[index] = false;
			studentList[j] = false;
		}
	}
	
	return cases;
}

int main()
{
	int C, n, m;
	cin >> C;
	
	while(C--) {
		cin >> n >> m;
		
		for(int i = 0; i < 10; ++i)
			for(int j = 0; j < 10; ++j)
				areFriends[i][j] = false;
		
		bool* studentList = new bool[n];
		for(int i = 0; i < n; ++i) studentList[i] = false;
		
		while(m--) {
			int i, j;
			cin >> i >> j;
			areFriends[i][j] = true;
			areFriends[j][i] = true;
		}
		
		cout << count(studentList, n) << endl;
		
		delete[] studentList;
	}
	
	return 0;
}
```