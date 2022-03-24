import java.util.*;
import java.io.*;

public class Main1005 {
    public static int n, k, w;
    public static ArrayList<ArrayList<Integer>> graph;
    public static int[] building;
    public static int[] inDegree;
    public static int[] buildCost;

    public static int topologySort() {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                buildCost[i] = building[i];
                q.add(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (q.isEmpty())
                return -1;
            int cur = q.poll();
            for (int j = 0; j < graph.get(cur).size(); ++j) {
                int nxt = graph.get(cur).get(j);
                buildCost[nxt] = Math.max(buildCost[cur] + building[nxt], buildCost[nxt]);
                --inDegree[nxt];
                if (inDegree[nxt] == 0)
                    q.add(nxt);
            }
        }

        return buildCost[w];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            building = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            graph = new ArrayList<ArrayList<Integer>>();
            graph.add(new ArrayList<>());
            for (int i = 1; i <= n; ++i) {
                building[i] = Integer.parseInt(st.nextToken());
                graph.add(new ArrayList<>());
            }
            inDegree = new int[n + 1];
            for (int i = 0; i < k; ++i) {
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                graph.get(start).add(end);
                ++inDegree[end];
            }
            w = Integer.parseInt(br.readLine());

            buildCost = new int[n + 1];
            System.out.println(topologySort());
        }
    }
}