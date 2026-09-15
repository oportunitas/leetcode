# [1470. Shuffle the Array][link] (Easy)

[link]: https://leetcode.com/problems/shuffle-the-array/
Given the array `nums` consisting of `2n` elements in the form `[x₁,x₂,...,xₙ,y₁,y₂,...,yₙ]`.

Return the array in the form `[x₁,y₁,x₂,y₂,...,xₙ,yₙ]`.

**Example 1:**

```
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x₁=2, x₂=5, x₃=1, y₁=3, y₂=4, y₃=7 then the answer is [2,3,5,4,1,7].
```

**Example 2:**

```
Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
```

**Example 3:**

```
Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
```

**Constraints:**

- `1 <= n <= 500`
- `nums.length == 2n`
- `1 <= nums[i] <= 10^3`
