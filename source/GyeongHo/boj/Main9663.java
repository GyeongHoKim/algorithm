import java.util.*;
import java.io.*;

public class Main9663 {

    public static int n, cnt = 0;
    public static int[] visited = new int[15];

    public static boolean chk(int depth) {
        for (int i = 0; i < depth; ++i) {
            if (visited[i] == visited[depth])
                return false;
            if (Math.abs(i - depth) == Math.abs(visited[i] - visited[depth]))
                return false;
        }
        return true;
    }

    public static void dfs(int depth) {
        if (depth >= n) {
            ++cnt;
            return;
        }

        for (int i = 0; i < n; ++i) {
            visited[depth] = i;
            if (!chk(depth))
                continue;
            dfs(depth + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        dfs(0);
        System.out.println(cnt);
    }
}