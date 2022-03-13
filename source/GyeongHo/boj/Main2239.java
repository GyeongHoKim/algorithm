import java.io.*;

public class Main2239 {
    public static int[][] board = new int[9][9];
    public static int[][] position = new int[81][2];
    public static int[] dy = new int[] {0, 0, 1, -1};
    public static int[] dx = new int[] {1, -1, 0, 0};
    public static int zeros = 0;
    public static StringBuilder sb = new StringBuilder();

    public static boolean chk(int y, int x, int num) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][x] == num && i != y)
                return false;
            if (board[y][i] == num && i != x)
                return false;
        }
        
        for (int i = y / 3 * 3; i < y / 3 * 3 + 3; ++i)
            for (int j = x / 3 * 3; j < x / 3 * 3 + 3; ++j)
                if (board[i][j] == num) {
                    if (i == y && j == x)
                        continue;
                    return false;
                }
        return true;
    }

    public static boolean dfs(int cnt) {
        if (cnt >= zeros) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    sb.append(board[i][j]);
                }
                sb.append('\n');
            }
            return true;
        }
        for (int n = 1; n < 10; ++n) {
            if (!chk(position[cnt][0], position[cnt][1], n))
                continue;
            board[position[cnt][0]][position[cnt][1]] = n;
            if (dfs(cnt + 1))
                return true;
            board[position[cnt][0]][position[cnt][1]] = 0;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; ++i) {
            String tmp = br.readLine();
            for (int j = 0; j < 9; ++j) {
                board[i][j] = tmp.charAt(j) - '0';
                if (board[i][j] == 0) {
                    position[zeros][0] = i;
                    position[zeros][1] = j;
                    ++zeros;
                }
            }
        }

        dfs(0);
        System.out.print(sb);
    }
}
