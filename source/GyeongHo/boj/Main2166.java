import java.util.*;
import java.io.*;

class Pos {
	double x, y;
	Pos(double x, double y) {
		this.x = x;
		this.y = y;
	}
}

public class Main2166 {

	public static int n;
	public static Pos[] positions = new Pos[100000];
	public static Pos bp;

	public static double CalArea(Pos p1, Pos p2) {
		double ans = (p1.x - bp.x) * (p2.y - bp.y) - (p1.y - bp.y) * (p2.x - bp.x);
		return ans / 2D;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		for (int i = 0; i < n; ++i) {
			String[] tmp = br.readLine().split(" ");
			positions[i] = new Pos(Double.parseDouble(tmp[0]), Double.parseDouble(tmp[1]));
		}
		br.close();
		bp = positions[0];

		double ans = 0;
		for (int i = 1; i < n - 1; ++i)
			ans += CalArea(positions[i], positions[i + 1]);
		if (ans < 0)
			ans *= -1;

		System.out.println(String.format("%.1f", ans));
	}
}
