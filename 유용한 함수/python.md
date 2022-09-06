## 알고리즘 풀이 시 유용한 함수 모응

- [배열에서 특정 값들 사이 범위(count_by_range)](#countbyrange)
- [가장 긴 증가하는 부분 수열(LIS)](#LIS)

### count_by_range

```python
from bisect import bisect_left, bisect_right

def count_by_range(arr, left, right):
    left_idx = bisect_left(arr, left)
    right_idx = bisect_right(arr, right)
    return right_idx - left_idx
```

### LIS

```python
def LIS(arr, N):
    dp = [1] * N
    for i in range(1, N):
        for j in range(i):
            if arr[j] < arr[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)
```
