import java.io.*;
import java.util.*;

class Edge {
    int start, end;
    double cost;
    Edge(int start, int end, double cost) {
        this.start = start;
        this.end = end;
        this.cost = cost;
    }
}

class Node {
    double y, x;
    Node(double y, double x) {
        this.y = y;
        this.x = x;
    }

    public double distBetween(Node n) {
        double ydiff = Math.abs(this.y - n.y);
        double xdiff = Math.abs(this.x - n.x);

        return Math.sqrt(ydiff * ydiff + xdiff * xdiff);
    }
}

public class Main4386 {
    
    public static int n;
    public static Node[] nodeList = new Node[101];
    public static int[] parent = new int[101];

    public static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        ArrayList<Edge> edgeList = new ArrayList<>();

        for (int i = 1; i <= n; ++i) {
            String[] tmp = br.readLine().split(" ");
            double x = Double.parseDouble(tmp[0]);
            double y = Double.parseDouble(tmp[1]);
            nodeList[i] = new Node(y, x);
        }
        br.close();

        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                edgeList.add(new Edge(i, j, nodeList[i].distBetween(nodeList[j])));
        
        edgeList.sort((o1, o2) -> Double.compare(o1.cost, o2.cost));

        double ans = 0;
        for (Edge e : edgeList) {
            if (find(e.start) != find(e.end)) {
                union(e.start, e.end);
                ans += e.cost;
            }
        }
        System.out.println(Math.floor(ans * 100) / 100);
    }
}
