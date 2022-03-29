import java.io.*;
import java.util.*;

public class Main2252 {

    public static boolean topologySort(int n, int[] inDegree, int[] order, ArrayList<ArrayList<Integer>> graph) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; ++i)
            if (inDegree[i] == 0)
                q.add(i);
        for (int i = 1; i <= n; ++i) {
            if (q.isEmpty())
                return false;
            int cur = q.poll();
            order[i] = cur;
            for (int j = 0; j < graph.get(cur).size(); ++j)
                if(--inDegree[graph.get(cur).get(j)] == 0)
                    q.add(graph.get(cur).get(j));
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] inDegree = new int[n + 1];
        int[] order = new int[n + 1];
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            graph.get(start).add(end);
            ++inDegree[end];
        }
        if (topologySort(n, inDegree, order, graph))
            for (int i = 1; i <= n; ++i)
                System.out.printf("%d ", order[i]);
        else
            System.out.println("Error");
    }
}
