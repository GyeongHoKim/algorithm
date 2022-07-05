import java.util.*;
import java.io.*;

class Node {
    int y, x;
    Node(int _y, int _x) {
        this.y = _y;
        this.x = _x;
    }
}

class Main4179 {

    static int n, m;
    static int[][] forest;
    static int[][] distJ;
    static int[][] distF;

    static void bfs(Queue<Node> qFire, Queue<Node> qJoe) {
        int dy[] = {0, 0, -1, 1};
        int dx[] = {-1, 1, 0, 0};
        while (!qFire.isEmpty()) {
            Node cur = qFire.poll();
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || distF[ny][nx] != 0 || forest[ny][nx] == 1)
                    continue;
                qFire.add(new Node(ny, nx));
                distF[ny][nx] = distF[cur.y][cur.x] + 1;
            }
        }

        while (!qJoe.isEmpty()) {
            Node cur = qJoe.poll();
            if (cur.y == 0 || cur.y == n - 1 || cur.x == 0 || cur.x == m - 1) {
                System.out.println(distJ[cur.y][cur.x]);
                return;
            }
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (distJ[ny][nx] != 0 || forest[ny][nx] == 1)
                    continue;
                if (distF[ny][nx] != 0 && distF[ny][nx] <= distJ[cur.y][cur.x] + 1)
                    continue;
                qJoe.add(new Node(ny, nx));
                distJ[ny][nx] = distJ[cur.y][cur.x] + 1;
            }
        }
        System.out.println("IMPOSSIBLE");
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        Queue<Node> qFire = new LinkedList<>();
        Queue<Node> qJoe = new LinkedList<>();
        forest = new int[n][m];
        distJ = new int[n][m];
        distF = new int[n][m];

        for (int i = 0; i < n; ++i) {
            String line = br.readLine();
            for (int j = 0; j < m; ++j) {
                if (line.charAt(j) == '#')
                    forest[i][j] = 1;
                else if (line.charAt(j) == '.')
                    forest[i][j] = 0;
                else if (line.charAt(j) == 'J') {
                    forest[i][j] = 0;
                    qJoe.add(new Node(i, j));
                    distJ[i][j] = 1;
                }
                else if (line.charAt(j) == 'F') {
                    forest[i][j] = 1;
                    qFire.add(new Node(i, j));
                    distF[i][j] = 1;
                }
            }
        }

        bfs(qFire, qJoe);
    }
}