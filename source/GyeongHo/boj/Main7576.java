import java.io.*;
import java.util.*;

class Node {
    int y, x;
    Node(int _y, int _x) {
        this.y = _y;
        this.x = _x;
    }
}

public class Main7576 {
    static int n, m;
    static int box[][];

    static void bfs(Queue<Node> q) {
        int dy[] = {0, 0, -1, 1};
        int dx[] = {-1, 1, 0, 0};
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || box[ny][nx] == -1 || box[ny][nx] > 0)
                    continue;
                box[ny][nx] = box[cur.y][cur.x] + 1;
                q.add(new Node(ny, nx));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[1]);
        m = Integer.parseInt(tmp[0]);
        box = new int[n][m];
        Queue<Node> startPoint = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; ++j) {
                box[i][j] = Integer.parseInt(tmp[j]);
                if (box[i][j] == 1)
                    startPoint.add(new Node(i, j));
            }
        }

        bfs(startPoint);
        int max_day = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (box[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                max_day = Math.max(max_day, box[i][j]);
            }
        }
        System.out.println(max_day - 1);
    }
}
