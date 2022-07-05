import java.util.*;
import java.io.*;

public class Main1697 {
    static int n, k;
    static int[] dist = new int[100001];

    static int bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        while(!q.isEmpty()) {
            int cur = q.poll();
            if (cur == k)
                return dist[cur];
            int d[] = {cur - 1, cur + 1, cur * 2};
            for (int i = 0; i < 3; ++i) {
                int nxt = d[i];
                if (nxt > 100000 || nxt < 0)
                    continue;
                if (dist[nxt] != 0 && dist[nxt] <= dist[cur] + 1)
                    continue;
                q.add(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        k = Integer.parseInt(tmp[1]);
        System.out.println(bfs());
    }
}
