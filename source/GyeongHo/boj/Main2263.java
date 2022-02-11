import java.io.*;

public class Main2263 {
    public static int n;
    public static int[] inOrder = new int[100001];
    public static int[] inOrderIdx = new int[100001];
    public static int[] postOrder = new int[100001];
    public static StringBuilder sb = new StringBuilder();

    public static void dfsPrint(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
        if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd)
            return;
        int root = postOrder[postOrderEnd];
        sb.append(root + " ");

        int inOrderRoot = inOrderIdx[root];
        int LSubSize = inOrderRoot - inOrderStart;

        dfsPrint(inOrderStart, inOrderRoot - 1, postOrderStart, postOrderStart + LSubSize - 1);
        dfsPrint(inOrderRoot + 1, inOrderEnd, postOrderStart + LSubSize, postOrderEnd - 1);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        String[] tempInOrder = br.readLine().split(" ");
        String[] tempPostOrder = br.readLine().split(" ");
        for (int i = 1; i <= n; ++i) {
            inOrder[i] = Integer.parseInt(tempInOrder[i - 1]);
            postOrder[i] = Integer.parseInt(tempPostOrder[i - 1]);
        }
        for (int i = 1; i <= n; ++i)
            inOrderIdx[inOrder[i]] = i;

        dfsPrint(1, n, 1, n);

        System.out.print(sb);
    }
}
