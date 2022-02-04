package source.GyeongHo.boj;

import java.io.*;
import java.util.*;

class Pos {
    int y, x, drill;
    Pos(int y, int x, int drill) {
        this.y = y;
        this.x = x;
        this.drill = drill;
    }
}

public class Main2206 {
    public static int[][] maze = new int[1000][1000];
    public static int[][] visited = new int[1000][1000];
    public static int[][] visited2 = new int[1000][1000];
    public static int[] diry = {0, 0, -1, 1};
    public static int[] dirx = {-1, 1, 0, 0};
    public static int n, m;

    public static void bfs() {
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(0, 0, 0));
        visited[0][0] = 1;
        visited2[0][0] = 1;
        while (!q.isEmpty()) {
            Pos cur = q.poll();
            for (int i = 0; i < 4; ++i) {
                Pos nxt = new Pos(cur.y + diry[i], cur.x + dirx[i], cur.drill);
                if (nxt.y < 0 || nxt.x < 0 || nxt.y >= n || nxt.x >= m)
                    continue;
                if (maze[nxt.y][nxt.x] == 1) {
                    if (cur.drill == 1)
                        continue;
                    else {
                        nxt.drill = 1;
                        visited2[nxt.y][nxt.x] = visited[cur.y][cur.x] + 1;
                        q.add(nxt);
                    }
                } else {
                    if (cur.drill == 1 && visited2[cur.y][cur.x] + 1 < visited2[nxt.y][nxt.x]) {
                        visited2[nxt.y][nxt.x] = visited2[cur.y][cur.x] + 1;
                        q.add(nxt);
                    }
                    else if (cur.drill == 0 && visited[cur.y][cur.x] + 1 < visited[nxt.y][nxt.x]) {
                        visited[nxt.y][nxt.x] = visited[cur.y][cur.x] + 1;
                        q.add(nxt);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp;
        tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        for (int i = 0; i < n; ++i) {
            Arrays.fill(visited[i], Integer.MAX_VALUE);
            Arrays.fill(visited2[i], Integer.MAX_VALUE);
            String tmp2 = br.readLine();
            for (int j = 0; j < m; ++j) {
                maze[i][j] = tmp2.charAt(j) - '0';
            }
        }
        br.close();

        bfs();

        int ans = Math.min(visited[n - 1][m - 1], visited2[n - 1][m - 1]);
        if (ans == Integer.MAX_VALUE)
            System.out.print(-1);
        else
            System.out.print(ans);
    }
}
