import java.io.*;
import java.util.*;

public class Main1967 {
    public static Boolean[] visited = new Boolean[10001];
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static int n, max_cost = 0;

    public static class Node {
        int num, cost;
        Node(int num, int cost) {
            this.num = num;
            this.cost = cost;
        }
    }

    public static void dfs(int cur, int sum) {
        max_cost = Math.max(max_cost, sum);
        
        for (int i = 0; i < graph.get(cur).size(); ++i) {
            int nxt = graph.get(cur).get(i).num;
            int cost = graph.get(cur).get(i).cost;
            if (visited[nxt])
                continue;
            visited[nxt] = true;
            dfs(nxt, cost + sum);
            visited[nxt] = false;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n + 1; ++i) {
            graph.add(new ArrayList<Node>());
        }
        for (int i = 0; i < n - 1; ++i) {
            String[] tmp = br.readLine().split(" ");
            int start = Integer.parseInt(tmp[0]), end = Integer.parseInt(tmp[1]), cost = Integer.parseInt(tmp[2]);
            graph.get(start).add(new Node(end, cost));
            graph.get(end).add(new Node(start, cost));
        }
        for (int i = 1; i < n + 1; ++i) {
            Arrays.fill(visited, false);
            visited[i] = true;
            dfs(i, 0);
        }
        System.out.print(max_cost);
    }
}