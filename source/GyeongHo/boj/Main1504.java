import java.util.*;
import java.io.*;

class Node {
    int destination, cost;

    Node(int destination, int cost) {
        this.destination = destination;
        this.cost = cost;
    }
}

public class Main1504 {

    public static int n, e;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static int[] dist = new int[801];

    public static int solution(int middle1, int middle2) {
        int oneTwo = 0, twoOne = 0;

        dijkstra(1);
        oneTwo += dist[middle1];
        twoOne += dist[middle2];
        dijkstra(middle1);
        oneTwo += dist[middle2];
        twoOne += dist[n];
        dijkstra(middle2);
        oneTwo += dist[n];
        twoOne += dist[middle1];

        return Math.min(oneTwo, twoOne) >= 20000000 ? -1 : Math.min(oneTwo, twoOne);
    }

    public static void dijkstra(int start) {
        Arrays.fill(dist, 200000000);
        PriorityQueue<Node> pq = new PriorityQueue<Node>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        dist[start] = 0;
        pq.add(new Node(start, 0));
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.destination] < cur.cost)
                continue;
            for (int i = 0; i < graph.get(cur.destination).size(); ++i) {
                Node nxt = graph.get(cur.destination).get(i);
                if (nxt.cost + cur.cost < dist[nxt.destination]) {
                    dist[nxt.destination] = nxt.cost + cur.cost;
                    pq.offer(new Node(nxt.destination, nxt.cost + cur.cost));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        e = Integer.parseInt(tmp[1]);

        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());

        for (int i = 0; i < e; ++i) {
            String[] tmp2 = br.readLine().split(" ");
            graph.get(Integer.parseInt(tmp2[0])).add(new Node(Integer.parseInt(tmp2[1]), Integer.parseInt(tmp2[2])));
            graph.get(Integer.parseInt(tmp2[1])).add(new Node(Integer.parseInt(tmp2[0]), Integer.parseInt(tmp2[2])));
        }

        String[] tmp3 = br.readLine().split(" ");
        int middle1 = Integer.parseInt(tmp3[0]);
        int middle2 = Integer.parseInt(tmp3[1]);
        
        System.out.println(solution(middle1, middle2));
    }
}