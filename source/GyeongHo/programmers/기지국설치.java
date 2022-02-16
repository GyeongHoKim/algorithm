public class 기지국설치 {
    class Solution {
        public int solution(int n, int[] stations, int w) {
            int ans = (stations[0] - w - 1) / (w * 2 + 1);
            if (0 < (stations[0] - w - 1) % (w * 2 + 1) && (stations[0] - w - 1) % (w * 2 + 1) < (w * 2 + 1))
                ++ans;
            for (int i = 1; i < stations.length; ++i) {
                int cur = stations[i];
                int prev = stations[i - 1];
                ans += (cur - w - (prev + w) - 1) / (w * 2 + 1);
                if (0 < (cur - w - (prev + w) - 1) % (w * 2 + 1) && (cur - w - (prev + w) - 1) % (w * 2 + 1) < (w * 2 + 1))
                    ++ans;
            }
            if (stations[stations.length - 1] + w < n) {
                ans += (n - stations[stations.length - 1] - w) / (w * 2 + 1);
                if (0 < (n - stations[stations.length - 1] - w) % (w * 2 + 1) && (n - stations[stations.length - 1] - w) % (w * 2 + 1) < w * 2 + 1)
                    ++ans;
            }
            return ans;
        }
    }
}
