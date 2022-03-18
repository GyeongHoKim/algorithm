import java.io.*;
import java.util.*;

class Node {
    int end, cost;
    Node(int end, int cost) {
        this.end = end;
        this.cost = cost;
    }
}

public class Main5972 {
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static int[] dist = new int[50001];

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<Node>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        pq.add(new Node(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.end] < cur.cost)
                continue;
            for (int i = 0; i < graph.get(cur.end).size(); ++i) {
                Node nxt = graph.get(cur.end).get(i);
                if (cur.cost + nxt.cost < dist[nxt.end]) {
                    dist[nxt.end] = cur.cost + nxt.cost;
                    pq.add(new Node(nxt.end, cur.cost + nxt.cost));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        int n, m;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<Node>());

        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph.get(start).add(new Node(end, cost));
            graph.get(end).add(new Node(start, cost));
        }
        
        Arrays.fill(dist, 987654321);
        dijkstra(1);
        System.out.println(dist[n]);
    }
}
