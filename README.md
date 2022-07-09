# largest_perfect_set
## Description
Given integer array, find a largest subset size such that for each element in the subset satisfies a condition which `s[i] * s[i] = s[i+1]` for all 1&lt;=i&lt;=n.

## Input
- `1 <= n <= 2*10^5`, n = size of list
- `2 <= arr[i] <= 10^6`, arr = input array and 0 <= i <= n-1
- return -1 if there is none. subset size must be larger than 1.

## Example
`input_arr = [9,3,2,4,16]`
result should be 3, which is `[2,4,16]`

## How to solve
1. sort input array<br>
2. create a hashmap where you save the information of all subsets. key: first element of the subset, value: length of the subset<br>
3. return the largest length of subset.

```cpp
sort(v);
for (_v = v.begin() to v.end())                       // iterate each element of input
    for (_m = m.begin() to m.end())                   // iterate each element of map
        if (_v == next_element(_m.first, _m.second))  // if current value of input == expected value of subset(=_m.first^(1 << _m.second))
        {
          // update subset value
          _m.second ++;
          break;
        }
    if (no_change_to_map) _m.insert(_v, 1);           // if not found in map, insert it into map
return max_len(_m);
```

## References
- https://www.geeksforgeeks.org/largest-sub-set-possible-for-an-array-satisfying-the-given-condition/
- https://cplusplus.com/reference/map/map/

## Compiler
C++98
