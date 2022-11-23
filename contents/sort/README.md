# 정렬

정렬 문제의 솔루션을 통해 다음과 같은 개념을 이해할 수 있기 때문에 알고리즘을 처음 배울 때 정렬예제부터 나온다.

1. Time Complexity -> worst case analysis와 amortized analysis
2. Loop invarient와 Correctness
3. Divide and Conquer

CSLR책 보면 insertion sort를 통해 loop invarient와 correctness개념을 가르쳐준다. 해당 내용은 좀 자세히 적었고 나머지는 코드 이해할 수 있을 정도로만 정리했다.

# Insertion Sort

# 카드 넣기

![cardSort](../cardSort.png)

왼쪽 손에 카드를 하나씩 넣되 숫자가 오름차순이 되도록 하자. Insertion Sort는 위 상황과 비슷하다.

# 그림 예시

A = <5, 2, 4, 6, 1, 3>이라고 할 때 아래와 같은 과정이 일어난다(예시 및 pseudocode에서, index는 0이 아니라 1부터 시작한다).

![insertionSort](../insertionSort.png)

# Pseudocode of Insertion Sort

```cpp
for j = 2 to A.length
	key = A[j]
	//Insert A[j] into sorted sequence A[1..j-1].
	i = j - 1
	while i > 0 and A[i] > key
		A[i + 1] = A[i]
		i = i - 1
	A[i + 1] = key
```

# Loop invariants and Correctness

> At the start of each iteration of the for loop of lines 1-8, the subarray A[1..j - 1] consists of the elements originally in A[1..j - 1], but in sorted order.
> 

loop invariants는 그 루프 내에서 항상 지켜지는 규칙인데 insertion sort의 경우, for loop 시작할 때, 1부터 j -1까지는 정렬된 상태라는 뜻이다.

loop invariants는 해당 알고리즘의 correctness를 증명하는 것에 쓰인다. 그래서 위의 loop invariant에 대해 아래 3개를 보여야 한다.

1. Initialization: It is true prior to the first iteration of the loop(loop의 첫 번째 iter이전에 저것이 참임을 보여라).
2. Maintenance: If it is true before an iteration of the loop, it remains true before the next iteration(현재 iteration 수행직전에서 참임을 만족할 때, 다음 iteration 수행직전에서도 참임을 보여라).
3. Termination: When the loop terminates, the invarient gives us a useful property that helps show that the algorithm is correct(루프가 끝날 때, invarient는 알고리즘이 correct하다는 것을 보여주는 데에 도움이 되는 특성을 제공함을 보여라).

1번과 2번이 참이면 이 loop invariant는 모든 iteration에 대해 참이다(수학적 귀납법). 그리고 3번은 correctness를 증명하는 데에 쓰인다.

## Insertion sort의 correctness 증명

### Initialization

We start by showing that tthe loop invariants holds before the first loop iteration, when j = 2. The subarray A[1..j - 1], therfore, consists of just the single element A[1], which is in fact the original element in A[1]. Moreover, this subarray is sorted(trivially, of course), which shows that the loop invariant holds prior to the first iteration of the loop.

이게 무슨 말이냐면, first iteration 시 j = 2인 상황이고 그 직전에 A[1…j-1]은 그냥 A[1]이므로 element가 하나밖에 없다는 거다. 하나만 있는 배열이 sorted되어있다는 것은 자명하기 때문에 참이라고 한다.

### Maintenance

Next, we tackle the second property: showing that each iteration maintains the loop invariant. Informally, the body of the for loop works by moving A[j - 1], A[j - 2], A[j - 3], and so on by one position to the right until it finds the proper position for A[j], at which point it inserts the value of A[j]. The subarray A[1..j] then consists of the elements originally in A[1..j], but in sorted order. Incrementing j for the next iteration of the for loop then preserves the loop invariant. A more formal treatment of the second property would require us to state and show a loop invariant for the while loop of lines 5-7. At this point, however, we prefer not to get bogged down in such formalism, and so we rely on our informal analysis to show that the second property holds for the outer loop.

이게 무슨 말이냐면, A[j]가 올바른 자리가 될 때까지 one by one으로 이동하기 때문에 for loop가 끝나면 A[1..j] subarray는 정렬된 상태라는 것이고 j + 1에 대해서도 마찬가지라는 뜻이다. 이를 위해서는 while loop의 loop invarient가 참임을 증명해야 하나 지금 단계에서는 참임을 가정하고 진행한다.

### Termination

Finally, we examine what happens when the loop terminates. The condition causing the for loop to terminate is that j > A.length = n. Because each loop iteration increases j by 1, we must have j = n + 1 at that time. Substituting n + 1 for j in the wording of loop invariant, we have that the subarray A[1..n] consists of the elements originally in A[1..n], but in sorted order. Observing that he subarray A[1..n] is the entire array, we conclude that the entire array is sorted. Hence, the algorithm is correct.

이게 무슨 말이냐면, for loop의 종료조건이 j > n일때 이고 j는 매 iteration마다 1씩 증가하니 언젠가 n + 1이 되는 순간이 오고 종료를 한다는 것이다. 이때, j = n + 1인데 loop invariant에 의해서 A[1..n]까지가 정렬된 상태임은 참이다. A[1..n]은 entire array와 같으므로 entire array가 sort되었음을 나타낸다. 따라서 이 algorithm은 correct하다.

# Running time of insertion sort

![PseudoCode](../insertionSortPseudo.png)

위의 psuedo code의 각 행의 cost와 몇 번 반복되는지를 보여준다.

for loop의 횟수가 n인게 잠깐 이해가 안되었는데 왜 그러냐면, 2 to A.length라서 n - 1번 반복하는 것처럼 보이지만 사실 마지막 iteration 이후 j = A.length + 1일 때 한번 비교연산을 하므로 n이다.

$t_j$는 j일 때 while loop 몇 번 도는지를 의미하는 것인데 j가 2부터 n까지 변하므로 시그마를 사용한다. 따라서

$$
T(n) = c_1n + c_2(n - 1) + c_4(n - 1) + c_5\sum^{n}_{j=2}t_j + c_6\sum^n_{j=2}(t_j - 1) + c_7\sum^n_{j=2}(t_j - 1) + c_8(n - 1)
$$

## Best case: already sorted

만약, input이 이미 정렬된 상태라면 $t_j = 1$이다. 위 식에 넣으면 시간복잡도는 O(n)이 된다.

## Worst case: reverse sorted

만약, input이 역정렬된 상태라면 $t_j = j$이다.

$$
\sum^n_{j=2}j = \frac{n(n+1)}{2} - 1
$$

을 만족하므로 위 식에 대입하면 시간복잡도는 O(n^2)가 된다.

# MergeSort

# The divide-and-conquer approach

- Divide the problem into a number of subproblems that are smaller instances of the same problem
- Comquer the subproblems by solving them recursively. If the subproblem sizes are small enough, however, just solve the subprob lems in a straightforward manner.
- Combine the solutions to the subproblems into the solution for the original problem.

## Divide and conquer at Merge Sort

- Divide: divide the n-element sequence to be sorted into two subsequences of n/2 elements each.
- Conquer: Sort the two subsequences recursively using merge sort.
- Combine: Merge the two sorted subsequences to produce the sorted answer.

# Merge Sort Code

```
Merge(A, p, q, r):
	n1 = q - p + 1
	n2 = r - q
	let L[1...n1 + 1] and R[1...n2 + 1] be new arrays
	for i = 1 to n1:
		L[i] = A[p + i - 1]
	for j = 1 to n2:
		R[j] = A[q + j]
	L[n1 + 1] = inf
	R[n2 + 1] = inf
	i = 1
	j = 1
	for k = p to r:
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1
```

그림으로 보면 다음과 같다.

![mergeSort1](../mergeSort1.png)

![mergeSort2](../mergeSort2.png)

# 퀵 소트

# 퀵소트의 과정

## 분할정복

문제를 2개로 나누어 각각을 해결해서 원래의 문제를 해결하는 방식

## 논리적인 순서

1. 피벗을 정해서 피벗보다 작은 값들, 큰 값들 2개 리스트로 나누고 그 중간에 피벗이 위치하도록 조정한다.
2. 2개 리스트에 대해 1번 과정을 재귀적으로 반복한다
    1. 재귀호출 한번 당 최소한 하나(피벗)의 위치가 정해지므로 무한히 반복하지 않는다.

# 퀵소트의 구현(C 코드)

분할과 정복 부분 두 가지로 나누어 구현한다.

## 분할

```c
void quick_sort(int* array, int start, int end)
{
	if (start >= end)
		return;
	int pivot = partition(array, start, end);
	quick_sort(array, start, pivot - 1);
	quick_sort(array, pivot + 1, end);
}
```

```java
public static void quick_sort(int[] array, int start, int end)
{
	if (start >= end)
		return;
	int pivot = partition(array, start, end);
	quick_sort(array, start, pivot - 1);
	quick_sort(array, pivot + 1, end);
}
```

## 정복

```c
int partition(int* array, int start, int end)
{
    int tmp, left = start + 1, right = end;
    int pivot = array[start];
    while(left <= right) {
        while(left <= end && array[left] <= pivot)
            ++left;
        while(right > start && array[right] >= pivot)
            --right;
        if (left <= right) {
            tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }
    }
    array[start] = array[right];
    array[right] = pivot;
    return right;
}
```

```java
public static int partition(int[] array, int start, int end)
{
	int tmp, left = start + 1, right = end;
	int pivot = array[start];
	while (left <= right) {
		while (left <= end && array[left] <= pivot)
			++left;
		while (right >= start && array[right] >= pivot)
			--right;
		if (left <= right) {
			tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
		}
	}
	array[start] = array[right];
	array[right] = pivot;
	return right;
}
```

# 퀵 소트의 구현(python3)

파이썬의 리스트 컴프리핸션을 이용하면 빠르게 구현할 수 있다.

```python
def quick_sort(array):
	if len(array) <= 1:
		return array
	pivot = array[0]
	tail = array[1:]
	left_side = [x for x in tail if x <= pivot]
	right_side = [x for x in tail if x > pivot]
	return quick_sort(left_side) + [pivot] + quick_sort(right_side)
```

메모리가 두 배나 필요하다. 그러므로 메모리가 부족한 문제라면 c 스타일로 구현해야 할 것이다.

# 퀵소트의 시간복잡도와 개선방법

## $nlog_2(n)$

위 코드를 기준으로 가장 이상적인 경우 즉, 분할한 배열의 가장 왼쪽에 있는 값이 항상 그 배열의 중간값일 경우 분할 시 피벗보다 작은 값들과 큰 값들로 나누었을 때 나누기 2씩 되므로 depth가 $log_2(n)$, 각 호출에서의 비교연산 $n$을 곱해서 $nlog_2(n)$이다. 어디까지나 이상적인 시간복잡도

## $n^2$

위 코드를 기준으로 배열이 이미 오름차순 또는 내림차순으로 정렬되어있을 경우, 피벗보다 작은 값들과 큰 값들로 분리가 안된다. 항상 피벗보다 작거나 큰 값들 만 존재하므로 나누기 2가 안되고 depth가 n, 각 호출당 연산 n이다. 즉 $n^2$

## 개선 방법

최악의 경우를 볼 때, 피벗이 분리한 배열의 가장 왼쪽에 위치하기 때문에 발생하는 일이라고 판단되므로 피벗의 위치 선정을 잘 하면 된다. 가장 이상적인 경우, 피벗의 값이 중간값이 되어야 하는데 중간값을 알아내는 것 자체가 정렬을 필요로 하는 일이기 때문에 이는 불가능하다.

우리가 취할 수 있는 가장 쉬운 방법은 피벗의 위치를 분할 시마다 랜덤하게 정하는 방법인데 이렇게 하면 Amortized Analysis로 계산했을 때 $n\lg(n)$이 나온다.

## 평균적인 시간복잡도 직관적으로

아래 그림처럼, 만약 한 쪽이 적어도 1/9 비율 이상으로 나오게 되면 $nlog_2(n)$이 된다. 보통 이미 정렬되어있는 배열이 주어지는 것 자체가 드물고 1/9 이상으로 나오게 되는 경우가 대부분이기 때문에 직관적으로 평균시간복잡도가 $nlog_2(n)$임을 알 수 있다.

![quickSortTree](../quickSortTree.png)

## 평균 시간복잡도 정확하게는?

Amortized Analysis로 랜덤 피벗의 경우로 증명할 수 있는데, 귀찮으니 기말고사 끝나고 나중에 시간나면 써보자.