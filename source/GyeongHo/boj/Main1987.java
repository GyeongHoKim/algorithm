import java.io.*;
import java.util.*;

class Node {
    int y, x;
    Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Main1987 {

    public static int n, m, max_val = 0;
    public static char[][] board = new char[20][20];
    public static boolean[] visited = new boolean[26];
    public static int[] dy = new int[] {0, 0, -1, 1};
    public static int[] dx = new int[] {1, -1, 0, 0};

    public static void dfs(int y, int x, int count) {
        if (y < 0 || y >= n || x < 0 || x >= m)
            return;
        if (visited[board[y][x] - 'A'])
            return;
        max_val = Math.max(max_val, count);
        for (int i = 0; i < 4; ++i) {
            int nxty = y + dy[i];
            int nxtx = x + dx[i];
            visited[board[y][x] - 'A'] = true;
            dfs(nxty, nxtx, count + 1);
            visited[board[y][x] - 'A'] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; ++i) {
            String tmp = br.readLine();
            for (int j = 0; j < m; ++j)
                board[i][j] = tmp.charAt(j);
        }

        dfs(0, 0, 1);
        System.out.println(max_val);
    }
}
