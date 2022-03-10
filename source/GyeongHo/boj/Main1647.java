import java.util.*;
import java.io.*;

class Edge {
    int start, end, cost;
    Edge(int start, int end, int cost) {
        this.start = start;
        this.end = end;
        this.cost = cost;
    }
}

public class Main1647 {
    public static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }

    public static void union(int[] parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = 0;
        int max_val = 0;

        int[] parent = new int[n + 1];
        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            edges.add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        for (int i = 0; i < n + 1; ++i)
            parent[i] = i;
        edges.sort((o1, o2) -> Integer.compare(o1.cost, o2.cost));

        for (int i = 0; i < m; ++i) {
            Edge edge = edges.get(i);
            if (find(parent, edge.start) != find(parent, edge.end)) {
                union(parent, edge.start, edge.end);
                ans += edge.cost;
                max_val = edge.cost;
            }
        }

        System.out.println(ans - max_val);
    }
}
