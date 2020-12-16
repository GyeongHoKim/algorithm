# algorithm

알고리즘 연습을 위한 리포.

## C++ STL 알고리즘 컨테이너

표준 템플릿 라이브러리(STL: Standard Template Library)는 C++을 위한 라이브러리로서 C++ 표준 라이브러리의 많은 부분에 영향을 끼쳤다. 이것은 알고리즘, 컨테이너, 함수자 그리고 반복자라고 불리는 네가지의 구성 요소를 제공한다.

STL에서 제공되는, 검색이나 정렬 같은 활동을 수행하는 알고리즘 대부분은 각각 반복자의 특정한 수준을 요구한다(그러므로 반복자들에 의해 인터페이스를 제공받는 어떠한 컨테이너에서도 동작할 것이다). binary_search 그리고 lower_bound 같은 검색 알고리즘은 이진 검색 알고리즘을 사용하며 정렬 알고리즘 같이(비교 연산 < 또는 명시된 커스텀 비교자 함수를 구현해야 하는) 데이터 타입을 요구한다; 이러한 비교 연산 또는 비교자 함수는 반드시 strict weak ordering을 보장해야 한다. 이것 외에도 알고리즘들은 다양한 요소들에서 힙을 만들고, 다양한 요소들의 사전 편찬상의 정렬된 순열을 생성하기 위해 제공되며, 정렬된 범위를 합병하고 정렬된 범위들의 합집합, 교집합, 여집합을 수행한다.

[위키](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%ED%85%9C%ED%94%8C%EB%A6%BF_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

* [nonmodifying algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/nonmodifyingAlgorithms)
* [modifying algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/modifyingAlgorithms/)
* [removing algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/removingAlgorithms/)
* [mutating algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/mutatingAlgorithms/)
* [sorting algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/sortingAlgorithms/)
* [sorted range algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/sortedRangeAlgorithms/)
* [numeric algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/constents/numericAlgorithms/)

총 7가지가 있다.

## Algospot

알고리즘 공부를 종만북으로 하기 때문에 알고스팟을 이용하기로 한다.
[알고스팟](https://algospot.com)에 대한 나의 풀이는 [여기](https://github.com/GyeongHoKim/algorithm/tree/main/algospot/)

## BaekJoon

컴퓨터공학 전공하는 애들이 [이 사이트](https://www.acmicpc.net/step)를 애용하는 것 같다. 그럼 나도 [여기](https://github.com/GyeongHoKim/algorithm/tree/main/boj/)에 백준저지를 올려보자.

## 스터디 진행

온라인 스터디를 진행해 보자. 군대 특성상 컴퓨터를 충분히 쓸 수 있는 토요일과 일요일에 문제를 푼다고 할 때, 일주일에 2개씩 푼다고 하자.

1. 매주 최소 2개씩 문제 풀이 마크다운 작성 후 업로드(개인별 로컬에서 작업 후 main branch에 merge)
	* 문제풀이 양식 추후 업데이트
	* [커밋 메시지 컨벤션](https://github.com/GyeongHoKim/algorithm/wiki/Message-Convention)
	* 너무 쉬운 문제일 경우 마크다운 작성하지말고 그냥 소스 업로드
2. 매주 일요일마다 코드리뷰 진행, slack 또는 issue & pull request 이용

## Git 저장소 이용하는 방법

- 저장소 : https://https://github.com/GyeongHoKim/algorithm

### 폴더 설명

- contents: 공동폴더. 알고리즘 관련 이론을 정리해서 업로드하는 폴더
- docs: 공동폴더. 이론 이외의 문서를 업로드하는 폴더
- source: 개인 폴더. 필요한 개인폴더를 생성하고 알고리즘 풀이를 업로드하는 폴더

<br>

### GitBash 명령어 사용 방법

- [원격저장소의 브랜치를 생성하는 방법](https://github.com/TheCopiens/algorithm-study/blob/master/docs/github/howToCreate_branch.md#%EC%9B%90%EA%B2%A9%EC%A0%80%EC%9E%A5%EC%86%8C%EC%9D%98-%EB%B8%8C%EB%9E%9C%EC%B9%98%EB%A5%BC-%EC%83%9D%EC%84%B1%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95)
- [원격저장소의 브랜치를 로컬로 가져오는 방법](https://github.com/TheCopiens/algorithm-study/blob/master/docs/github/bring_remote_branch.md)
- [fork한 저장소 최신으로 동기화하는 방법](https://github.com/TheCopiens/algorithm-study/blob/master/docs/github/update_forkedRepo_from_originRepo.md#fork-%ED%95%9C-repository-%EC%B5%9C%EC%8B%A0%EC%9C%BC%EB%A1%9C-%EB%8F%99%EA%B8%B0%ED%99%94-%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95)

#### 원격저장소 로컬에 가져오기

<code> git clone https://https://github.com/GyeongHoKim/algorithm.git </code>

#### 로컬에서 개인 브랜치 생성하기

local workspace에 'ohhako'라는 이름으로 브랜치 생성<br>
<code> git branch ohhako </code>

#### 로컬에서 브랜치 작업후 원격저장소에 반영하기

로컬 브랜치가 있는 폴더에서 개인작업을 마친 후 공동 저장소에 반영한다.

1. <code> **git checkout ohhako** </code> - main에서 ohhako 브랜치로 전환
2. workspace에서 작업
3. <code> **git commit -m "message"**</code>
4. <code> **git push origin ohhako** </code> - 원격저장소 ohhako 브랜치에 반영
5. <code> **git checkout main** </code> - 브랜치 전환
6. <code> **git pull** </code> - 원격저장소 main의 최신 정보를 로컬에 업데이트 시키기
7. <code> **git merge ohhako** </code> - main에 ohhako 브랜치 작업 반영
8. <code> **git push origin main** </code> - 원격저장소 main에 반영

## <br><br>

### 이 글은 아래 사이트를 참고해 작성되었습니다.

https://github.com/TheCopiens/algorithm-study