## chapter 15. Dynamic Programming
![kakaotalk_20181115_141419334](https://user-images.githubusercontent.com/41552919/48531758-e493a600-e8e0-11e8-8813-ebbed1cdf43c.jpg)
![kakaotalk_20181115_141421081](https://user-images.githubusercontent.com/41552919/48531762-e65d6980-e8e0-11e8-93d9-dfb22351aa96.jpg)

### 15.1 Rod cutting
```exercises```
**1-4**
```
MEMOIZED-CUT-ROD(p,n) { 
  r[0...n]을 새로운 배열이라 한다.
    for(i = 0; i<n; i++){
      r[i] = -1;
    }
  return MEMOIZED-CUT-ROD-AUX(p, n, r)
}

MEMOIZDE-CUT-ROD-AUX(p, n, r){
  if(r[n]>=0) return r[n];
  if(r==0) q=0;
  else{
    q = -1;
    for (i = 0; i<n; i++){
    q = max(q, p[i]+MEMOIZDE-CUT-ROD-AUX(p, n-1, r));
    }
  }
  r[n]=q;
  return q;
}
```

### 15.2 Matrix-chain multiplication
```exercises```
**2-1**
```
주어진 행렬차원 -> 5*10, 10*3, 3*12, 12*5, 5*50, 50*6
위의 6개의 행렬체인을 <M1, M2, M3, M4, M5, M6>이라 하자.
(n개의 행렬에 대한 곱셈을 모두 괄호로 묶으려면 n-1개의 괄호쌍이 필요하므로 필요한 괄호의 수는 5개임.)

행렬의 곱은 차원이 (p*q)*(q*r)인 형태에서만 성립하므로 M1 M2 M3 M4 M5 M6를 묶을 수 있는 방법은 두가지
  1) (M1 M2) (M3 M4) (M5 M6)
    =>(5*10*3)+(3*12*5)+(5*50*6)=1830
  2) M1 (M2 M3) (M4 M5) M6
    => (10*3*12)+(12*5*50) = 3360
  이므로 2는 최적해가 아님
  
   위의 곱의 결과로 계산된 행렬을 각각 A1(5*3) A2(3*5) A3(5*6)라 할 때
   1) ((A1 A2) A3)
     =>(5*3*5)+(5*5*6)=225
   2) (A1 (A2 A3))
     =>(3*5*6)+(5*3*6)=180
   이므로 1은 최적해가 아님
 
따라서 주어진 행렬차원에서 최적의 괄호묶기는 ((M1 M2) ((M3 M4) (M5 M6)))이다.(총 2010회 스칼라 곱 연산)
```

### 15.3 Elements of dynamic programming
```exercises```
**3-1**
```
모든 가능한 괄호 묶기의 경우의 수를 조사하는 것이 더 비효율적이다.
1개의 행렬을 묶는 경우 가능한 경우의 수는 한 가지이며, n>=2일때 가능한 서로 다른 방법의 수는 2^n에 비례한다...
(식 15.6참조)
모든 경우의 수를 나열해 조사하는 경우 각 경우마다 (n-1)개의 괄호쌍에 대한 스칼라 곱 횟수를 연산해야 하므로
이 경우 시간복잡도가 n*2^n이 되게 된다.

반면 RECURSIVE-MATRIX-CHAIN의 경우 중복연산이 많긴 하나 시간복잡도는 2^(n-1)이므로 위의 경우보다 나음을 알 수 있다.
```


### 15.4 Longest common subsequence
```exercises```
**1-1**

### 15.5 Optimal binary search trees
```exercises```
**1-1**
