import java.util.*;
import java.io.*;

public class 예산 {
    public static void main(String[] args) {
        int[] budgets = new int[] {120, 110, 140, 150};
        int M = 485;

        Solution s = new Solution();
        System.out.println(s.solution(budgets, M));
    }
}

class Solution {
    public int solution(int[] budgets, int M) {
        int ans = 0;
        int start = 0, end = 0;
        for (int i : budgets) {
            end = Math.max(end, i);
        }
        while (start <= end) {
            int total = 0;
            int mid = (start + end) / 2;
            for (int budget : budgets) {
                if (budget > mid)
                    total += mid;
                else
                    total += budget;
            }
            if (total > M)
                end = mid - 1;
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
}