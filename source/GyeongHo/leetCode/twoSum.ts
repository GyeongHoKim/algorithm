function twoSum(nums: number[], target: number): number[] {
  const indexedNumber = new Map<number, number>();
  let result: number[] = [];
  nums.some((num, idx) => {
    const complement = target - num;
    if (indexedNumber.has(complement) && indexedNumber.get(complement) !== idx) {
      result = [idx, indexedNumber.get(complement)];
      return true;
    }
    indexedNumber.set(num, idx);
    return false;
  });
  return result;
};