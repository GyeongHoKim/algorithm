import java.util.*;
import java.io.*;

public class Main20040 {

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
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int ans = 1;
        boolean cycleFlag = false;
        int[] parent = new int[n];
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            if (find(parent, n1) != find(parent, n2) && !cycleFlag) {
                ++ans;
                union(parent, n1, n2);
            }
            else {
                cycleFlag = true;
            }
        }
        br.close();

        if (!cycleFlag)
            System.out.println(0);
        else
            System.out.println(ans);
    }
}
