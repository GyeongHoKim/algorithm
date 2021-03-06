# algorithm

알고리즘 연습을 위한 리포.

## C++ STL 알고리즘 컨테이너

알고리즘 컨테이너 말고 다른 자료구조들에 대한 컨테이너 설명은 [여기](https://gyeonghokim.github.io/categories/#stl) 참고

표준 템플릿 라이브러리(STL: Standard Template Library)는 C++을 위한 라이브러리로서 C++ 표준 라이브러리의 많은 부분에 영향을 끼쳤다. 이것은 알고리즘, 컨테이너, 함수자 그리고 반복자라고 불리는 네가지의 구성 요소를 제공한다.

STL에서 제공되는, 검색이나 정렬 같은 활동을 수행하는 알고리즘 대부분은 각각 반복자의 특정한 수준을 요구한다(그러므로 반복자들에 의해 인터페이스를 제공받는 어떠한 컨테이너에서도 동작할 것이다). binary_search 그리고 lower_bound 같은 검색 알고리즘은 이진 검색 알고리즘을 사용하며 정렬 알고리즘 같이(비교 연산 < 또는 명시된 커스텀 비교자 함수를 구현해야 하는) 데이터 타입을 요구한다; 이러한 비교 연산 또는 비교자 함수는 반드시 strict weak ordering을 보장해야 한다. 이것 외에도 알고리즘들은 다양한 요소들에서 힙을 만들고, 다양한 요소들의 사전 편찬상의 정렬된 순열을 생성하기 위해 제공되며, 정렬된 범위를 합병하고 정렬된 범위들의 합집합, 교집합, 여집합을 수행한다.

[위키](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%ED%85%9C%ED%94%8C%EB%A6%BF_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

* [nonmodifying algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/nonmodifyingAlgorithms)
* [modifying algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/modifyingAlgorithms/)
* [removing algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/removingAlgorithms/)
* [mutating algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/mutatingAlgorithms/)
* [sorting algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/sortingAlgorithms/)
* [sorted range algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/sortedRangeAlgorithms/)
* [numeric algorithms](https://github.com/GyeongHoKim/algorithm/tree/main/contents/numericAlgorithms/)

총 7가지가 있다.

# 스터디 진행

온라인 스터디를 진행해 보자. 군대 특성상 컴퓨터를 충분히 쓸 수 있는 토요일과 일요일에 문제를 푼다고 할 때, 일주일에 2개씩 푼다고 하자.
본 스터디의 [Slack Channel](https://join.slack.com/t/302global/shared_invite/zt-k8k7z3o2-95OKOfBe8j1R8jpwAkbprw)

1. 매주 일요일에 주제를 정하고 그에 맞는 문제 3가지를 뽑아 다음주 토요일까지 푼다
	* [문제풀이 양식](https://github.com/GyeongHoKim/algorithm/blob/main/source/GyeongHo/algospot/PICNIC.md)
	* [커밋 메시지 컨벤션](https://github.com/GyeongHoKim/algorithm/wiki/Message-Convention)
	* 발표를 진행하는 3가지 문제에 대해서만 마크다운으로 풀이 작성, 웬만하면 다 작성하는 것이 좋으나 귀찮으면 하지마셈
2. 매주 일요일마다 코드리뷰 진행, slack 또는 issue & pull request 이용

## Git 저장소 이용하는 방식 신송(Git 워크플로)

- 저장소 : https://https://github.com/GyeongHoKim/algorithm
- 본 스터디의 구성원이 git에 익숙치 않으므로 [중앙집중식 워크플로](https://gyeonghokim.github.io/git/workflow/)를 사용
	* clone, add, commit, push, pull 명령어만 익히면 됨
- 만약, 자신이 git에 익숙하거나 자신의 repo로 만들어 관리하고 싶다면 fork 후 branch 생성하여 관리해도 됨. pull-request 처리는 매주 일요일에 하겠음
	* git workflow와 fork, pull-request 등의 개념을 익혀야 함, [progit 2장](https://git-scm.com/book/ko/v2/Git%EC%9D%98-%EA%B8%B0%EC%B4%88-Git-%EC%A0%80%EC%9E%A5%EC%86%8C-%EB%A7%8C%EB%93%A4%EA%B8%B0)


### 폴더 설명

- contents: 공동폴더. 알고리즘 관련 이론을 정리해서 업로드하는 폴더
- docs: 공동폴더. 이론 이외의 문서를 업로드하는 폴더
- source: 개인 폴더. 필요한 개인폴더를 생성하고 알고리즘 풀이를 업로드하는 폴더

<br>

### 본 스터디에서의 Git 이용 방식 신송

4번을 읽을 때 참고.
![git](https://raw.githubusercontent.com/GyeongHoKim/algorithm/main/docs/img/git.png)

### 1번 (선택사항)원격저장소를 fork

[본 사이트](https://https://github.com/GyeongHoKim/algorithm) 우측 상단의 Fork 버튼 클릭(명령어 없음)

### 2번 원격저장소를 로컬로 가져오기

사지방 프린터 출력용 PC 옆자리의 Ubuntu WSL(git 초기설정이 내걸로 돼있어서 사용자 추가 후 사용해야 함)
또는 [구름IDE](https://goorm.io), [GitPod](https://gitpod.io) 등의 웹 IDE 이용

``` shell
$git clone https://github.com/GyeongHoKim/algorithm.git
```

### 3번 (선택사항)로컬에서 개인 브랜치 생성

``` shell
$git branch GyeongHo
```

로컬 워크스페이스에 경호라는 이름으로 브랜치 생성
clone이후 디폴트로 main 브랜치. 브랜치를 변경하려면

``` shell
$git checkout GyeongHo
```

### 4번 로컬에서 파일 생성 등의 작업 후 원격저장소(remote repo)에 반영

위의 그림 참조

``` shell
$git pull origin main
```

하여 remote repo와 local repo 동기화(pull 명령어는 fetch와 merge를 합쳐놓은 명령어이므로 현재 branch가 무엇인지 꼭 확인해야 함)
알고리즘 문제에 대한 풀이를 작성, 가령 **백준** 사이트의 **7777**번 문제 풀이를 **7777.md** 파일에 담음.

``` shell
$git add 7777.md //staging area에 추가
```

``` shell
$git commit -m "ADD BOJ 7777"
```

혹은 `$git commit` 후 나타나는 문서 편집기에 "ADD BOJ 7777"과 Content(가령 "BP solution")를 적고 local repo에 커밋(커밋 메시지는 [commit message convention](https://github.com/GyeongHoKim/algorithm/wiki/Message-Convention)참고)

`$git push origin main` 혹은 (선택사항)`git push origin GyeongHo`하여 remote repo에 업로드

### 5번 (선택사항)4번문항 도중 파일을 고치고 싶으면

add 후 갑자기 파일을 고치고 싶을 때: `$git reset HEAD 7777.md` (staging area에서 내려감)  
commit 후 갑자기 파일을 고치고 싶을 때: `$git commit --amend` (바로 직전의 commit에 합쳐서 같은 commit으로 취급)  
롤백 상황이 벌어졌다 : Integration-Manager(병장 김경호)에게 문의 후 revert  
	
### 6번 (선택사항)fork한 remote repo를 main remote repo에 반영(pull-request)

자신의 원격저장소 github 사이트에서 pull-request 버튼 클릭
매주 일요일에 pull-request 확인 후 Integration-Manager이 승인
생각해보니까, 다들 master권한을 가지고 있어서 이게 의미가 없네. 자기가 pull-request하고 자기가 승인을 할 수가 있어
