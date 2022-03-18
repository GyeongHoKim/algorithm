import java.io.*;
import java.util.*;

public class Main1584 {
    public static int[] dy = {0, 0, -1, 1};
    public static int[] dx = {1, -1, 0, 0};
    public static int[][] board = new int[501][501];
    public static int[][] visited = new int[501][501];

    public static void bfs() {
        Deque<int[]> q = new LinkedList<>();
        q.add(new int[] {0, 0});
        visited[0][0] = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int i = 0; i < 4; ++i) {
                int ny = dy[i] + cur[0];
                int nx = dx[i] + cur[1];
                if (ny < 0 || nx < 0 || ny > 500 || nx > 500 || visited[ny][nx] != -1 || board[ny][nx] == -1)
                    continue;
                if (board[ny][nx] == 0)
                    q.addFirst(new int[] {ny, nx});
                else
                    q.add(new int[] {ny, nx});
                visited[ny][nx] = visited[cur[0]][cur[1]] + board[ny][nx];
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int k = 0; k < n; ++k) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int nx1 = Integer.parseInt(st.nextToken());
            int ny1 = Integer.parseInt(st.nextToken());
            int nx2 = Integer.parseInt(st.nextToken());
            int ny2 = Integer.parseInt(st.nextToken());

            int starty = ny1 < ny2 ? ny1 : ny2;
            int endy = ny1 < ny2 ? ny2 : ny1;
            int startx = nx1 < nx2 ? nx1 : nx2;
            int endx = nx1 < nx2 ? nx2 : nx1;

            for (int i = starty; i <= endy; ++i)
                for (int j = startx; j <= endx; ++j)
                    board[i][j] = 1;
        }
        int m = Integer.parseInt(br.readLine());

        for (int k = 0; k < m; ++k) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int mx1 = Integer.parseInt(st.nextToken());
            int my1 = Integer.parseInt(st.nextToken());
            int mx2 = Integer.parseInt(st.nextToken());
            int my2 = Integer.parseInt(st.nextToken());

            int starty = my1 < my2 ? my1 : my2;
            int endy = my1 < my2 ? my2 : my1;
            int startx = mx1 < mx2 ? mx1 : mx2;
            int endx = mx1 < mx2 ? mx2 : mx1;

            for (int i = starty; i <= endy; ++i) {
                for (int j = startx; j <= endx; ++j) {
                    board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < 501; ++i)
            Arrays.fill(visited[i], -1);
        
        bfs();
        
        System.out.println(visited[500][500]);
    }
}
