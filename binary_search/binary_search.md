Stop learning useless algorithms, go and learn how to use binary search


--
--
二分搜索的前提在于单调性，关键在于循环不变量。   
比如，将由n个元素组成的数组`A`排序后，其具有单调递增（递减）的特性。此时应用二分搜索来寻找第一个大于等于`tar`的下标`i`，将不变量从两端不断向内循环，直到边界条件。

```
n 5
A 1 3 5 8 9
tar 6
```
通过暴力做法，我们可以发现下标`i`及其右侧的数都满足`A[i] >= tar` 而其左侧的数都满足`A[i] < tar`，可以表示为
```
A 1 3 5 8 9
  F F F T T
T = A[i] >= tar, F = !(A[i] < tar)
```
那么初始化
```
l = 0, r = n - 1
A 1 3 5 8 9
  F F F T T
  l       r
```
不断计算`mid = (l + r) / 2`， 判断`mid`属于F或是T，将其分配给`l`或是`r`，然后不断循环，直到`r < l`，表示我们已经对整个区间完成了搜索。
```
A 1 3 5 8 9
  F F F T T
      r l
```
--
--
二分搜索有三种写法，效果相同，可随意选择。   
Q1 寻找单调区间内第一个满足条件的目标，即上文所述`FFFTTT`的情况。
```
int tar = 5;
vector<int> nums{1, 3, 7, 9};
int n = nums.size();
```
闭区间

```
int l = 0, r = n - 1, ans = n;
auto check = [&](int mid) { return nums[mid] >= tar; };
while (l <=r ) {
    // l + (r - l) / 2 to prevent overflow
    int mid = l + (r - l) / 2;
    if (check(mid)) {
        // 当前数大于目标，移动右边界
        r = mid - 1;
        ans = mid;
    }
    else {
        l = mid + 1;
    }
}
return ans;

```
左闭右开
```
// mid满足条件，nums[mid] >= tar, r = mid, nums[r] >= tar
// mid不满足条件，nums[mid] < tar, l = mid + 1, nums[l - 1] < tar
// 边界条件l == r
// -> 当前值 = cur = l -> 满足条件
// -> 左边的值 = cur - 1 = l - 1 -> 不满足条件
// 开区间取 n
int l = 0, r = n;
auto check = [&](int mid) { return nums[mid] >= tar; };
while(l < r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
}
// always l
return l

```
开区间   
`略`

C++STL提供了函数std::lower_bound, 来寻找第一个不在tar之前的iterator
即 `comp = bool(*iter < value)`为`false`
```
auto it = std::lower_bound(nums.begin(), nums.end(), tar);
int i = it - nums.begin();
```

寻找符合条件的最小的最大值，是该问题的变形。

--
--

Q2 寻找单调区间内最后一个满足条件的目标，即上`TTTFFF`的情况。
```
int tar = 5;
vector<int> nums{1, 3, 7, 9};
int n = nums.size();
```
闭区间

```
int l = 0, r = n - 1, ans = l - 1;
auto check = [&](int mid) { return nums[mid] >= tar; };
while (l <=r ) {
    // l + (r - l) / 2 to prevent overflow
    int mid = l + (r - l) / 2;
    if (check(mid)) {
        l = mid + 1;
        ans = mid;
    }
    else {
        r = mid - 1;
    }
}
return ans;

```
左闭右开
```
// mid满足条件，nums[mid] >= tar, l = mid, nums[l] >= tar
// mid不满足条件，nums[mid] < tar, r = mid - 1, nums[r + 1] < tar
// 边界条件l == r
// -> 当前值 = cur = l -> 满足条件
// -> 右边的值 = cur + 1 = l + 1 -> 不满足条件
int l = 0, r = n - 1;
auto check = [&](int mid) { return nums[mid] >= tar; };
while(l < r) {
    // +1 防止死循环
    int mid = l + (r - l + 1) / 2;
    if (check(mid)) l = mid;
    else r = mid - 1;
}
// always l
return l

```
开区间   
`略`

C++ STL提供了函数std::upper_bound, 来寻找第一个在tar之后的iterator
即`bool(value < *iter)`为`true`
```
auto it = std::upper_bound(nums.begin(), nums.end(), tar);
int i = it - nums.begin();
```

寻找符合条件的最大的最小值，是该问题的变形。
