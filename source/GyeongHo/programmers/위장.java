import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int ans = 1;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < clothes.length; ++i) {
            if (map.containsKey(clothes[i][1])) {
                map.put(clothes[i][1], map.get(clothes[i][1]) + 1);
            }
            else {
                map.put(clothes[i][1], 1);
            }
        }
        for (int val : map.values()) {
            ans *= val + 1;
        }
        return ans - 1;
    }
}