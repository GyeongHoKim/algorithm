import java.util.*;
import java.io.*;

public class Main9466 {

    static boolean[] visited;
    static boolean[] cache;
    static int[] selection;
    static int n, cnt;

    static void dfs(int cur) {
        if (!cache[cur])
            return;
        if (visited[cur]) {
            ++cnt;
            for (int i = selection[cur]; i != cur; i = selection[i])
                ++cnt;
            return;
        }
        visited[cur] = true;
        dfs(selection[cur]);
        visited[cur] = false;
        cache[cur] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        visited = new boolean[100001];
        cache = new boolean[100001];
        selection = new int[100001];
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            n = Integer.parseInt(br.readLine());
            cnt = 0;
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; ++i) {
                visited[i] = false;
                cache[i] = true;
                selection[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= n; ++i)
                dfs(i);
            System.out.println(n - cnt);
        }
    }
}
