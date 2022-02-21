import java.io.*;
import java.util.*;

class Node {
    int end, cost;
    Node(int end, int cost) {
        this.end = end;
        this.cost = cost;
    }
}

public class Main1167 {
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
    public static int[] dist = new int[100001];
    public static int v, max_val = 0;

    public static void dijkstra(int start) {
        pq.add(new Node(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()) {
            Node curNode = pq.poll();
            if (dist[curNode.end] < curNode.cost)
                continue;
            ArrayList<Node> curList = graph.get(curNode.end);
            for (int i = 0; i < curList.size(); ++i) {
                int nxt = curList.get(i).end, ncost = curList.get(i).cost + curNode.cost;
                if (dist[nxt] <= ncost)
                    continue;
                dist[nxt] = ncost;
                pq.add(new Node(nxt, ncost));
            }
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int max_idx = 0;
        v = Integer.parseInt(br.readLine());
        for (int i = 0; i <= v; ++i)
            graph.add(new ArrayList<Node>());
        for (int i = 1; i < v + 1; ++i) {
            String[] tmp = br.readLine().split(" ");
            for (int j = 1; j < tmp.length - 1; j += 2) {
                graph.get(Integer.parseInt(tmp[0])).add(new Node(Integer.parseInt(tmp[j]), Integer.parseInt(tmp[j + 1])));
            }
        }
        br.close();
        
        Arrays.fill(dist, Integer.MAX_VALUE);
        dijkstra(1);
        for (int i = 1; i <= v; ++i) {
            if (max_val < dist[i]) {
                max_idx = i;
                max_val = dist[i];
            }
        }
        Arrays.fill(dist, Integer.MAX_VALUE);
        dijkstra(max_idx);
        for (int i = 1; i <= v; ++i) {
            if (max_val < dist[i]) {
                max_idx = i;
                max_val = dist[i];
            }
        }
        System.out.print(max_val);
    }
}
