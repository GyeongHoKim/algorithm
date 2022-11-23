# Direct Address Table

![DirectAddress](../DirectAddress.png)

당신이 생각하는 그것. 설명할 필요가 없다. 일반적으로 U가 충분히 작아야만 쓸 수 있다.

# Hashing & Chaining

# 해싱 함수

direct address는 공간상 할 수 없기 때문에 해싱함수로 결과를 제한 → 충돌 발생(k2와 k5)

![hashCollision](../hashCollision.png)

저장 슬롯 m보다 U가 크기 때문에 어쩔 수 없이 collision이 발생할 수 밖에 없음

# Load Factor

average number of elements stored in a chain

$$
\alpha = n / m
$$

# Collision resolution by chaining

너도 알고 나도 아는 그 체이닝

![chaining](../chaining.png)

insertion과 deletion(doubly linked일 때)은 O(1)이고 서칭은 O(n)이다.

[Why deletion of elements of hash table using doubly-linked list is O(1)?](https://stackoverflow.com/questions/8105889/why-deletion-of-elements-of-hash-table-using-doubly-linked-list-is-o1)

# Simple Uniform Hashing

Any given element is equally likely to hash into any of the m slots

## Theorem 1

> In a hash table in which collisions are resolved by chaining, an unsuccessful search takes average-case time $\Theta (1 + \alpha )$, under the assumption of simple uniform hashing
> 

## Proof

Expected time to search unsuccessfully for a key k is the expected time to search to the end of list $T[h(k)]$, which has expected length $E[n_{h(k)}] = \alpha$. Thus, the expected number of elements examined in an unsuccessful search is $\alpha$, and the total time required is $\Theta (1 + \alpha )$.

## Theorem 2

> In a hash table in which collisions are resolved by chaining, a successful search takes average-case time $\Theta ( 1 + \alpha )$, under the assumption of simple uniform hashing.
> 

## Proof

솔직히 뭔말인지 모르겠는데 그냥 외우자

$$
E[\frac{1}{n}\sum^n_{i = 1}(1 + \sum^n_{j = i + 1}X_{ij})] = \frac{1}{n}\sum^n_{i = 1}(1 + \sum^n_{j = i + 1}E[X_{ij}]) \\ = \frac{1}{n}\sum^n_{i = 1}(1 + \sum^n_{j = i + 1}\frac{1}{m}) \\ = 1 + \frac{1}{nm}\sum^n_{i = 1}(n - i) \\ = 1 + \frac{1}{nm}(\sum^n_{i = 1}n - \sum^n_{i = 1}i) \\ = 1 + \frac{1}{nm}(n^2 - \frac{n(n + 1)}{2}) \\ = 1 + \frac{n - 1}{2m} \\ = 1 + \frac{\alpha}{2} - \frac{\alpha}{2n}
$$

$$
\Theta ( 1 + 1 + \frac{\alpha}{2} - \frac{\alpha}{2n}) = \Theta ( 1 + \alpha )
$$

무느알?

# Good Hash Functions

# What makes a good hash function?

- each key is equally likely to hash to any of the m slots
- each key is independently of where any other key has hashed to.

minimize the chance that such variants hash to the same slot.

# The division method

map a key k into one of m slots by taking the remainder of k divided by m

$$
h(k) = k \%m
$$

m을 2의 거듭제곱수에서 멀리 떨어져 있는 prime number로 잡는 것이 좋다.

# The multiplication method

1. 0 < A < 1인 A 상수를 key에 곱해서 fractional part만 추출한다.
2. 이 값을 m과 곱하고 floor한다.

$$
h(k) = \left \lfloor m(kA \% 1) \right \rfloor
$$

이 방법을 사용하면 m의 값에 크게 영향을 받지 않아서 division method에서 처럼 좋은 m을 찾으려 할 필요가 없다.

# Universal hashing

key에 의존하는 random function인데 수업시간에 안다룸

# Open Addressing

all elements are stored in the hash table itself

- Linear Probing
- Quadratic Probing
- Double Hashing

과 같은 방법이 있다.