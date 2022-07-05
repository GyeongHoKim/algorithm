import java.util.*;
import java.io.*;

class Node {
    int y, x;

    Node(int _y, int _x) {
        this.y = _y;
        this.x = _x;
    }
}

public class Main2178 {
    static int n, m;
    static int visited[][];
    static int board[][];
    static int dy[] = {0, 0, -1, 1};
    static int dx[] = {1, -1, 0, 0};

    static void bfs(int start_y, int start_x) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(start_y, start_x));
        visited[start_y][start_x] = 1;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; ++i) {
                Node nxt = new Node(cur.y + dy[i], cur.x + dx[i]);
                if (nxt.y < 0 || nxt.y >= n || nxt.x < 0 || nxt.x >= m || visited[nxt.y][nxt.x] != 0 || board[nxt.y][nxt.x] == 0)
                    continue;
                q.add(nxt);
                visited[nxt.y][nxt.x] = visited[cur.y][cur.x] + 1;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        visited = new int[n][m];
        board = new int[n][m];

        for (int i = 0; i < n; ++i) {
            String line = br.readLine();
            for (int j = 0; j < m; ++j)
                board[i][j] = line.charAt(j) - '0';
        }

        bfs(0, 0);

        System.out.println(visited[n - 1][m - 1]);
    }
}
