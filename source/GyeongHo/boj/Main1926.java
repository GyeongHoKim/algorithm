import java.util.*;
import java.io.*;

class Node {
    int y, x;
    Node(int _y, int _x) {
        this.y = _y;
        this.x = _x;
    }
}

public class Main1926 {

    static int n, m, max_area = 0, painting_num = 0;
    static boolean visited[][];
    static int painting[][];
    static int dy[] = {0, 0, -1, 1};
    static int dx[] = {-1, 1, 0, 0};

    static int bfs(int start_y, int start_x) {
        int area = 0;
        Queue<Node> q = new LinkedList<>();
        visited[start_y][start_x] = true;
        q.add(new Node(start_y, start_x));

        while (!q.isEmpty()) {
            Node cur = q.poll();
            ++area;
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || painting[ny][nx] == 0)
                    continue;
                visited[ny][nx] = true;
                q.add(new Node(ny, nx));
            }
        }

        max_area = Math.max(max_area, area);
        return 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        visited = new boolean[n][m];
        painting = new int[n][m];

        for (int i = 0; i < n; ++i) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; ++j) {
                painting[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!visited[i][j] && painting[i][j] == 1)
                    painting_num += bfs(i, j);
        
        System.out.println(painting_num);
        System.out.println(max_area);
    }
}