## chapter 13. Red black Trees
![kakaotalk_20181108_215612060](https://user-images.githubusercontent.com/41552919/48200057-562f9980-e3a1-11e8-9b5f-f42f33cbb772.jpg)

### 13.1 Properties of RBT
![kakaotalk_20181108_215617211](https://user-images.githubusercontent.com/41552919/48200096-795a4900-e3a1-11e8-839f-9831e6c0e1e2.jpg)

black-height
![kakaotalk_20181108_215618978](https://user-images.githubusercontent.com/41552919/48200277-00a7bc80-e3a2-11e8-8d3c-3443725bfbac.jpg)

```exercises```
**1-1**
![rbt1-1](https://user-images.githubusercontent.com/41552919/48240566-95e49880-e416-11e8-9efd-d29b7856d079.jpg)

**1-6**
높이가 k일때 가능한 bh(k)의 최대는 모든 노드가 검정색인 경우의 k이며, 최소인 경우는 블랙 노드와 레드 노드가 번갈아 있는 상태의 k/2이다.

### 13.2 Rotations

```exercises```
**2-1**
RIGHT-ROTATE(T, x)
LEFT-ROTEATE(T, x)
```
y = x.right
x.right = y.left
if(y.left != T.nil)
  y.left.p = x
y.p = x.p
if(x.p == T.nil)
  T.root = y
else if(x == x.p.left)
  x.p.left = y
else
  x.p.right = y
y.left = x
x.p = y
```
**2-2**
n개의 노드가 있을 때 하위 서브트리부터 루트노드까지 레드블랙트리의 규칙에 위배되는지를 검사하고 fix해야 하므로 최대 n-1번의 회전이 일어날 수 있다.

### 13.3 Insertion
![kakaotalk_20181108_215614681](https://user-images.githubusercontent.com/41552919/48200340-2d5bd400-e3a2-11e8-9758-3af58706d143.jpg)
![kakaotalk_20181108_215620422](https://user-images.githubusercontent.com/41552919/48200360-3ba9f000-e3a2-11e8-806f-f2e9a88272ae.jpg)
![kakaotalk_20181108_215610911](https://user-images.githubusercontent.com/41552919/48200460-904d6b00-e3a2-11e8-87fb-9ffb795a3224.jpg)
![kakaotalk_20181108_215615776](https://user-images.githubusercontent.com/41552919/48200685-45802300-e3a3-11e8-9927-90936b974b38.jpg)

```exercises```
**3-1**
새로 추가하는 노드의 색상을 블랙으로 지정하게 되면 black-height에 영향을 끼치므로 레드 노드를 추가하는 것보다 더 많은 수의 fix 연산을 수행해야 할 가능성이 크다.
3-2

### 13.4 Deletion
![kakaotalk_20181108_215613437](https://user-images.githubusercontent.com/41552919/48200536-cc80cb80-e3a2-11e8-99cd-383ca9fcb3de.jpg)
![kakaotalk_20181108_215608319](https://user-images.githubusercontent.com/41552919/48200634-22557380-e3a3-11e8-87d2-7c92992e0dd7.jpg)
![kakaotalk_20181108_215606685](https://user-images.githubusercontent.com/41552919/48200577-ea4e3080-e3a2-11e8-990e-af7b10c54f80.jpg)

```exercises```
4-1
4-4

https://www.youtube.com/watch?v=1IqZT54bhz8
https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
