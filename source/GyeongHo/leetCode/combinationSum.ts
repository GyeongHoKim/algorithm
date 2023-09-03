/**
 * 
 * @param candidates 
 * @param target 
 * @returns result
 * @description
 * Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
 */

function combinationSum(candidates: number[], target: number): number[][] {
  const result: number[][] = [];
  let visited: number[] = [];
  function dfs(depth: number, sum: number): void {
    if (sum >= target) {
      if (sum === target) {
        result.push([...visited]);
      }
      return;
    }
    for (let i = depth; i < candidates.length; ++i) {
      visited.push(candidates[i]);
      dfs(i, sum + candidates[i]);
      visited.pop();
    }
  }
  dfs(0, 0);
  return result;
};

console.log(combinationSum([2,3,6,7], 7));