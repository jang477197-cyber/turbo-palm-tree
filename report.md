# GCD 알고리즘 복잡도 분석

## 1) GCD 복잡도

### ● 알고리즘 설명

본 과제에서 사용한 GCD 알고리즘은 유클리드 호제법(Euclidean Algorithm)을 기반으로 한다.

두 정수 a, b에 대하여 다음 과정을 반복한다.

1. a를 b로 나눈 나머지를 구한다.
2. a ← b, b ← a % b 로 갱신한다.
3. b가 0이 될 때까지 반복한다.
4. 최종적으로 a가 최대공약수가 된다.

---

### ● 사용 코드

```c
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
```

---

### ● 시간복잡도 계산

유클리드 호제법에서 반복 횟수는 입력값에 따라 달라진다.
각 단계에서 b의 값은 이전보다 작아지며 빠르게 감소한다.

특히 최악의 경우는 입력값이 피보나치 수열 형태일 때 발생하며,
이 경우에도 반복 횟수는 입력값의 크기에 비해 크게 증가하지 않는다.

즉, 입력값이 커질수록 반복 횟수는 천천히 증가하며,
로그(log) 수준으로 증가한다고 볼 수 있다.

---

### ● Big-O 표기

위의 계산을 바탕으로 GCD 알고리즘의 시간복잡도는 다음과 같다.

→ **O(log n)**

---

### ● 제출 파일 링크

이전에 제출한 GCD 알고리즘 파일은 아래와 같다.

https://github.com/jang477197-cyber/turbo-palm-tree/blob/main/main1.c
https://github.com/jang477197-cyber/turbo-palm-tree/blob/main/my_math.c
https://github.com/jang477197-cyber/turbo-palm-tree/blob/main/my_math.h

---

### ● 결론

유클리드 호제법을 이용한 GCD 알고리즘은
입력값이 증가하더라도 반복 횟수가 로그 수준으로 증가하므로,
Big-O 표기 기준으로 **O(log n)**의 시간복잡도를 가진다.
