# Recurrences

> 자신을 정의할 때 자기 자신을 재참조하는 방법을 의미
> 

# Solving recurrences

Merge sort를 통해 divide and conquer 알고리즘의 시간 복잡도가 재귀로 나타남을 배웠다. 어떻게 하면 재귀를 풀 수 있을까?

1. Substitution method
2. Recursion Tree method
3. Master Theorem

# Substitution method

두 단계를 거친다.

1. Guess the form of the solution
2. Use mathematical induction to find the constants and show that the solution works

가령, 

$$
T(n) = 2T(\left \lfloor n / 2 \right \rfloor) + n
$$

일 때, $T(n) = O(n\lg n)$라고 가정하는게 1단계이고 2단계는 상수를 결정한 후 가정이 맞음을 보여야 한다. 상수를 적당히 잡으면 $T(n) \le cn\lg n$이 되고 대입하면

$$
T(\left \lfloor n / 2 \right \rfloor) \le c\left \lfloor n / 2 \right \rfloor\lg (\left \lfloor n / 2 \right \rfloor)
$$

인데 이 부등호를 첫 번째 식에 대입하면,

$$
T(n) \le 2(c\left \lfloor n / 2 \right \rfloor\lg(\left \lfloor n / 2 \right \rfloor)) + n
$$

이다. 이걸 잘 정리해서 $T(n) \le cn\lg n$임을 보여주면 된다. 쭉 정리하면

$$
T(n) \le 2(c\left \lfloor n / 2 \right \rfloor\lg(\left \lfloor n / 2 \right \rfloor)) + n \\ \le cn\lg(n/2) + n \\ = cn\lg n - cn\lg 2 + n \\ = cn\lg n - cn + n \\ \le cn\lg n, c\ge 1
$$

으로 $c \ge 1$일때, $T(n) = O(n\lg n)$이다. 원래 $T(1) = 1$이라고 boundary condition을 정해주어야 하는데(위 공식상에서 $T(1) \le 0$임). 그냥 생략한다.

## Substitution method로 알 수 없는 것

보통 시간복잡도를 구하라고 하면, lower bound를 의미한다. 위 방식은 Lower bound를 알 수 없다. $O(n)$임을 가정하고 풀었을 때 참이라고 해서 그것이 lower bound인 것은 아니다.

# Recursion Tree method

![recursionTree](../recursionTree.png)

각 층을 다 더하면 되는데, 맨 마지막 층은 다 더해도 n이 안되기 때문에 생략한다.

# Master theorem

다음과 같은 상황에서만 적용할 수 있다.

$$
T(n) = aT(n/b) + f(n)
$$

세 가지 경우로 나뉘는데

1. $f(n)$이 $n^{\log_ba}$보다 작을 때: $T(n) = \Theta (n^{\log_ba})$
2. $f(n)$이 $n^{\log_ba}$와 동일할 때: $T(n) = \Theta (n^{\log_ba}\lg n)$
3. $f(n)$이 $n^{\log_ba}$보다 클 때: $T(n) = \Theta (f(n))$

이다.

# 유형1: 분할정복에 사용되는 경우

분할정복도 따로 단원을 빼서 정리할 것이기 때문에 간단하게만 설명하자. 분할정복은 Divide와 Conquer로 나뉘는데 Divide과정에서 재귀함수를 사용한다.

[1629번: 곱셈](https://www.acmicpc.net/problem/1629)

A를 B번 곱하는 것이 거듭제곱의 계산법이기는 한데 변수의 최댓값이 int의 최대값처럼 보이고 시간제한도 0.5초라서 O(N)으로는 안된다. 둘 씩 나눠서 들어가게 되면 O(logN)이 되니까

$$
a^b = a^{b/2} * a^{b/2} * a^{b \text{ mod } 2}
$$

이걸 이용해 보자. 그리고 주의할 점,

$$
(a * b) \text{ mod } c = ((a \text{ mod } c) * (b \text{ mod } c)) \text{ mod } c
$$

모듈러 연산 법칙인데 각각에 대해서 모듈러하고 곱한 뒤에 다시 모듈러 해줘야 한다.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long recursion(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    long long half = recursion(a, b / 2, c) % c;
    long long result = half * half % c;
    if (b & 1)
        return result * a % c;
    else
        return result;
}

long long forLoop(long long a, long long b, long long c) {
    long long result = 1;
    while (b) {
        if (b & 1)
            result = result * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return result;
}

int main() {
    cin >> a >> b >> c;
    cout << recursion(a, b, c);
    //cout << forLoop(a, b, c);
    return 0;
}
```

[1074번: Z](https://www.acmicpc.net/problem/1074)

입력의 범위가 n = 15일때 최대인데 int 배열로 만들 경우 4GB이상이 필요하기 때문에 배열을 직접 만들면서 구하면 안된다. 구역을 나누어서 index값만가지고 몇 번째인지를 구해야 하는데, 영역을 4분할했을 때 어느 영역에 속하는지만 알면 그 앞에 몇 개의 영역이 있는지로 횟수를 판단할 수가 있다. 이번 문제의 경우에 재귀보다는 forLoop로 구현하는게 더 직관적이라서 forLoop로 만들었는데 사람에 따라 재귀가 더 편할 수는 있다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int forLoop(int i, int j)
{
    int result = 0;
    n = 1 << (n - 1);
    for (int k = n; k > 0; k >>= 1) {
        if (i < k && j < k)
            continue;
        else if (i >= k && j < k)
            result += k * k * 2;
        else if (i < k && j >= k)
            result += k * k;
        else
            result += k * k * 3;
        i %= k;
        j %= k;
    }
    return result;
}

int recursion(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (r < half && c < half)
        return recursion(n - 1, r, c);
    else if (r < half && c >= half)
        return half * half + recursion(n - 1, r, c - half);
    else if (r >= half && c < half)
        return half * half * 2 + recursion(n - 1, r - half, c);
    else
        return half * half * 3 + recursion(n - 1, r - half, c - half);
}

int main()
{
    cin >> n >> r >> c;

    cout << forLoop(r, c);
    //cout << recursion(n, r, c);
}
```

# 유형2: 그냥 재귀

[11729번: 하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)

아래의 예시는 예전에 풀었던 거라서 횟수를 구하는 거랑 이동하는 거랑 다른 함수로 구분했는데, 이렇게 안하고 이동하는 함수 하나에서 횟수구하는 것 까지 포함시켜도 된다. 만약 지금 푼다면 dp로 횟수구하는 부분을 빼고 재귀함수 내에서 number == 1일 때 바로 출력하는게 아니라 string 변수 하나에 누적시키고 횟수까지 센 다음에 한꺼번에 출력 할 것 같다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[21];

void hanoi(int position, int target, int number)
{
    if (number == 1) {
        cout << position << ' ' << target << '\n';
        return;
    }
    int next = 6 - position - target;
    hanoi(position, next, number - 1);
    hanoi(position, target, 1);
    hanoi(next, target, number - 1);
    return;
}

int main()
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 21; ++i)
        dp[i] = dp[i - 1] * 2 + 1;

    cout << dp[n] << '\n';
    hanoi(1, 3, n);
    return 0;
}
```