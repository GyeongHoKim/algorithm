import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int cnt = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        int idx = -1;
        for (int i = 0; i < A.length; ++i) {
            for (int j = idx + 1; j < B.length; ++j) {
                if (A[i] < B[j]) {
                    ++cnt;
                    idx = j;
                    break;
                }
            }
        }
        return cnt;
    }
}