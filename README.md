# algorithm

알고리즘 연습을 위한 리포. C++을 주로 사용할 것이기 때문에 STL의 알고리즘 컨테이너에 대한 공부도 진행.

## STL 알고리즘 컨테이너

표준 템플릿 라이브러리(STL: Standard Template Library)는 C++을 위한 라이브러리로서 C++ 표준 라이브러리의 많은 부분에 영향을 끼쳤다. 이것은 알고리즘, 컨테이너, 함수자 그리고 반복자라고 불리는 네가지의 구성 요소를 제공한다.

STL에서 제공되는, 검색이나 정렬 같은 활동을 수행하는 알고리즘 대부분은 각각 반복자의 특정한 수준을 요구한다(그러므로 반복자들에 의해 인터페이스를 제공받는 어떠한 컨테이너에서도 동작할 것이다). binary_search 그리고 lower_bound 같은 검색 알고리즘은 이진 검색 알고리즘을 사용하며 정렬 알고리즘 같이(비교 연산 < 또는 명시된 커스텀 비교자 함수를 구현해야 하는) 데이터 타입을 요구한다; 이러한 비교 연산 또는 비교자 함수는 반드시 strict weak ordering을 보장해야 한다. 이것 외에도 알고리즘들은 다양한 요소들에서 힙을 만들고, 다양한 요소들의 사전 편찬상의 정렬된 순열을 생성하기 위해 제공되며, 정렬된 범위를 합병하고 정렬된 범위들의 합집합, 교집합, 여집합을 수행한다.

[위키](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%ED%85%9C%ED%94%8C%EB%A6%BF_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

* [nonmodifying algorithms](./nonmodifying algorithms/)
* [modifying algorithms](./modifying algorithms/)
* [removing algorithms](./removing algorithms/)
* [mutating algorithms](./mutating algorithms/)
* [sorting algorithms](./sorting algorithms/)
* [sorted range algorithms](./sorted range algorithms/)
* [numeric algorithms](./numeric algorithms/)

총 7가지가 있다.