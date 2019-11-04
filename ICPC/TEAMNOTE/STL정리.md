# STL 정리

## lower_bound

- 원하는 키값이 **없으면** key값보다 큰 가장 작은 정수 값
- **있으면** 키값을 가지는 애중에 맨앞 iterator 반환
- ex) arr[6] = {1, 2, 3, 3, 4, 5} 일때, lower_bound로 3을 찾으면 arr[2]의 iterator 반환

## upper_bound

- 오름차순으로 정렬되어 있어야함
- 원하는 키 값을 초과하는 가장 첫번째 원소의 위치를 반한
- 키 값이 있으면 있을 시에는 키 값을 가지는 애들 바로 다음 iterator를 반환
