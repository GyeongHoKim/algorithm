import java.io.*;
import java.util.*;

class Node {
    int end, cost;
    Node(int end, int cost) {
        this.end = end;
        this.cost = cost;
    }
}

public class Main1865 {
    public static int n, m, w;
    public static int[] dist;
    public static ArrayList<ArrayList<Node>> graph;
    public static final int INF = 987654321;

    public static boolean bf(int start) {
        Arrays.fill(dist, INF);
        dist[start] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (Node curNode : graph.get(j)) {
                    int cur = j, nxt = curNode.end, cost = curNode.cost;
                    if (dist[cur] != INF && cost + dist[cur] < dist[nxt]) {
                        dist[nxt] = cost + dist[cur];
                        if (i == n - 1)
                            return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        while (TC-- > 0) {
            String[] tmp = br.readLine().split(" ");
            n = Integer.parseInt(tmp[0]);
            m = Integer.parseInt(tmp[1]);
            w = Integer.parseInt(tmp[2]);

            dist = new int[n + 1];
            graph = new ArrayList<>();
            for (int i = 0; i <= n; ++i)
                graph.add(new ArrayList<Node>());
            for (int i = 0; i < m; ++i) {
                tmp = br.readLine().split(" ");
                int start = Integer.parseInt(tmp[0]);
                int end = Integer.parseInt(tmp[1]);
                int time = Integer.parseInt(tmp[2]);
                graph.get(start).add(new Node(end, time));
                graph.get(end).add(new Node(start, time));
            }
            for (int i = 0; i < w; ++i) {
                tmp = br.readLine().split(" ");
                int start = Integer.parseInt(tmp[0]);
                int end = Integer.parseInt(tmp[1]);
                int time = Integer.parseInt(tmp[2]);
                graph.get(start).add(new Node(end, time * -1));
            }
            if (bf(1))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
