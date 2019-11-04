# 트리

## Tree의 지름

임의의 점에서 가장 먼 노드(A)를 찾고 그 노드(A)에서 가장 먼 노드까지의 거리가 트리의 지름입니다.

## 이진 검색 트리

이진 검색 트리는 root node의 left subtree에는 항상 root보다 작은 값들이 위치하고 right에는 root보다 큰 값들이 위치한다.

## 이진 검색 트리의 후위 순회(Postorder Traversal)

- 후위 순회의 root는 맨 끝에 있는 값이다.
- 이진 검색 트리에서 left subtree는 다 root보다 작기 때문에 root보다 커지는 첫 지점(upper_bound)를 찾으면 left와 right를 나눌 수있다.
- 이를 바탕으로 left - right - root 순으로 재귀를 진행하면 된다.

## 이진 트리의 중위 순회(Inorder Traversal)

- 중위 순회의 결과는 트리를 중력에 의해서 다 떨겼을 때의 결과와 동일하다.
