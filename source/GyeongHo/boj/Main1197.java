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

public class Main1197 {

    public static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }

    public static void union(int[] parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a > b)
            parent[a] = b;
        else
            parent[b] = a;
    }
    public static void main(String[] args) throws IOException {
        ArrayList<Edge> edges = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int ans = 0;

        for (int i = 0; i < e; ++i) {
            st = new StringTokenizer(br.readLine());
            edges.add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        edges.sort((o1, o2) -> Integer.compare(o1.cost, o2.cost));

        int[] parent = new int[v + 1];
        for (int i = 0; i < parent.length; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < e; ++i) {
            Edge edge = edges.get(i);
            if (find(parent, edge.start) != find(parent, edge.end)) {
                union(parent, edge.start, edge.end);
                ans += edge.cost;
            }
        }
        System.out.println(ans);
    }
}
