## 알고리즘 풀이 시 유용한 함수 모응

- [배열에서 특정 값들 사이 범위(count_by_range)](#countbyrange)
- [문자열에서 찾는 값들을 특정 값으로 변환(replace_string_all)](#replacestringall)
- [가장 긴 증가하는 부분 수열(LIS)](#LIS)

### count_by_range

```c++
int count_by_range(vector<string>& v, string left_value, string right_value) {
   vector<string>::iterator right_idx = upper_bound(v.begin(), v.end(), right_value);
   vector<string>::iterator left_idx = lower_bound(v.begin(), v.end(), left_value);
   return right_idx - left_idx;
}
```

### replace_string_all

```c++
string replace_all(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos) {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}
```

### LIS

```c++
vector<int> LIS(vector<int> dp, vector<int> arr)
    for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
    return dp;
```
