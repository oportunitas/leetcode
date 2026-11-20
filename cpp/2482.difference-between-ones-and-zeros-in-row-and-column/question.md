# [2482. Difference Between Ones and Zeros in Row and Column][link] (Medium)

[link]: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

You are given a **0-indexed** `m x n` binary matrix `grid`.

A **0-indexed** `m x n` difference matrix `diff` is created with the following procedure:

- Let the number of ones in the `iᵗʰ` row be `onesRowᵢ`.
- Let the number of ones in the `jᵗʰ` column be `onesColⱼ`.
- Let the number of zeros in the `iᵗʰ` row be `zerosRowᵢ`.
- Let the number of zeros in the `jᵗʰ` column be `zerosColⱼ`.
- `diff[i][j] = onesRowᵢ + onesColⱼ - zerosRowᵢ - zerosColⱼ`

Return the difference matrix  `diff`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/11/06/image-20221106171729-5.png)

```
Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow₀ + onesCol₀ - zerosRow₀ - zerosCol₀ = 2 + 1 - 1 - 2 = 0
- diff[0][1] = onesRow₀ + onesCol₁ - zerosRow₀ - zerosCol₁ = 2 + 1 - 1 - 2 = 0
- diff[0][2] = onesRow₀ + onesCol₂ - zerosRow₀ - zerosCol₂ = 2 + 3 - 1 - 0 = 4
- diff[1][0] = onesRow₁ + onesCol₀ - zerosRow₁ - zerosCol₀ = 2 + 1 - 1 - 2 = 0
- diff[1][1] = onesRow₁ + onesCol₁ - zerosRow₁ - zerosCol₁ = 2 + 1 - 1 - 2 = 0
- diff[1][2] = onesRow₁ + onesCol₂ - zerosRow₁ - zerosCol₂ = 2 + 3 - 1 - 0 = 4
- diff[2][0] = onesRow₂ + onesCol₀ - zerosRow₂ - zerosCol₀ = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow₂ + onesCol₁ - zerosRow₂ - zerosCol₁ = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow₂ + onesCol₂ - zerosRow₂ - zerosCol₂ = 1 + 3 - 2 - 0 = 2
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/11/06/image-20221106171747-6.png)

```
Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow₀ + onesCol₀ - zerosRow₀ - zerosCol₀ = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow₀ + onesCol₁ - zerosRow₀ - zerosCol₁ = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow₀ + onesCol₂ - zerosRow₀ - zerosCol₂ = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow₁ + onesCol₀ - zerosRow₁ - zerosCol₀ = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow₁ + onesCol₁ - zerosRow₁ - zerosCol₁ = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow₁ + onesCol₂ - zerosRow₁ - zerosCol₂ = 3 + 2 - 0 - 0 = 5
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10⁵`
- `1 <= m * n <= 10⁵`
- `grid[i][j]` is either `0` or `1`.
