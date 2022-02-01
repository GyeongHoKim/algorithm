package source.GyeongHo.boj;

import java.io.*;
import java.util.*;

public class Main13549 {
    public static int[] dist = new int[100001];
    public static int n, k;

    public static boolean chk(int x) {
        if (x < 0 || x > 100000)
            return false;
        return true;
    }

    public static class Node {
        int end, cost;
        Node(int end, int cost) {
            this.end = end;
            this.cost = cost;
        }
    }

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.cost, y.cost));
        pq.add(new Node(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.end] < cur.cost)
                continue;
            for (int i = 0; i < 3; ++i) {
                if (chk(cur.end * 2) && i == 0 && cur.cost < dist[cur.end * 2]) {
                    dist[cur.end * 2] = cur.cost;
                    pq.add(new Node(cur.end * 2, cur.cost));
                }
                if (chk(cur.end - 1) && i > 0 && cur.cost + 1 < dist[cur.end - 1]) {
                    dist[cur.end - 1] = cur.cost + 1;
                    pq.add(new Node(cur.end - 1, cur.cost + 1));
                }
                if (chk(cur.end + 1) && i > 0 && cur.cost + 1 < dist[cur.end + 1]) {
                    dist[cur.end + 1] = cur.cost + 1;
                    pq.add(new Node(cur.end + 1, cur.cost + 1));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        sc.close();

        Arrays.fill(dist, Integer.MAX_VALUE);
        dijkstra(n);
        System.out.print(dist[k]);
    }
}