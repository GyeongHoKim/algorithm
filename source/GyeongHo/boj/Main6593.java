import java.util.*;
import java.io.*;

class Node {
    int z, y, x;
    Node(int _z, int _y, int _x) {
        this.z = _z;
        this.y = _y;
        this.x = _x;
    }
}

public class Main6593 {
    static char[][][] dungeon;
    static int[][][] dist;
    static int k, n, m;
    static int[] dz = {0, 0, 0, 0, 1, -1};
    static int[] dy = {0, 0, 1, -1, 0, 0};
    static int[] dx = {1, -1, 0, 0, 0, 0};
    
    public static boolean inRange(int z, int y, int x) {
        if (z < 0 || z >= k || y < 0 || y >= n || x < 0 || x >= m)
            return false;
        return true;
    }

    public static int bfs(Node start) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(start.z, start.y, start.x));
        dist[start.z][start.y][start.x] = 0;
        while(!q.isEmpty()) {
            Node cur = q.poll();
            if (dungeon[cur.z][cur.y][cur.x] == 'E')
                return dist[cur.z][cur.y][cur.x];
            for (int i = 0; i < 6; ++i) {
                int nz = cur.z + dz[i];
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (!inRange(nz, ny, nx) || dungeon[nz][ny][nx] == '#')
                    continue;
                if (dist[nz][ny][nx] != 0 && dist[nz][ny][nx] <= dist[cur.z][cur.y][cur.x] + 1)
                    continue;
                q.add(new Node(nz, ny, nx));
                dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] tmp = br.readLine().split(" ");
            k = Integer.parseInt(tmp[0]);
            n = Integer.parseInt(tmp[1]);
            m = Integer.parseInt(tmp[2]);
            if (k == 0 && n == 0 && m == 0)
                return;
            dungeon = new char[k][n][m];
            dist = new int[k][n][m];
            Node start = null;
            
            for (int z = 0; z < k; ++z) {
                for (int i = 0; i < n; ++i) {
                    String line = br.readLine();
                    for (int j = 0; j < m; ++j) {
                        dungeon[z][i][j] = line.charAt(j);
                        if (dungeon[z][i][j] == 'S')
                            start = new Node(z, i, j);
                    }
                }
                br.readLine();
            }
            int time = bfs(start);
            if (time != -1) {
                System.out.print("Escaped in ");
                System.out.print(time);
                System.out.println(" minute(s).");
            }
            else {
                System.out.println("Trapped!");
            }
        }
    }
}