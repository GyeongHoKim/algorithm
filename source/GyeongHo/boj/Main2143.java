import java.util.*;
import java.io.*;

public class Main2143 {
    public static int lower_bound(ArrayList<Integer> list, int val) {
        int start = 0, end = list.size();
        int mid;
        while (start < end) {
            mid = (start + end) >> 1;
            if (list.get(mid) >= val)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    public static int upper_bound(ArrayList<Integer> list, int val) {
        int start = 0, end = list.size();
        int mid;
        while (start < end) {
            mid = (start + end) >> 1;
            if (list.get(mid) <= val)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
    public static void main(String[] args) throws IOException {
        long ans = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        int m = Integer.parseInt(br.readLine());
        int[] b = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; ++i) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        
        ArrayList<Integer> aSum = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int tmp = a[i];
            aSum.add(tmp);
            for (int j = i + 1; j < n; ++j) {
                tmp += a[j];
                aSum.add(tmp);
            }
        }


        ArrayList<Integer> bSum = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int tmp = b[i];
            bSum.add(tmp);
            for (int j = i + 1; j < m; ++j) {
                tmp += b[j];
                bSum.add(tmp);
            }
        }
        Collections.sort(aSum);
        Collections.sort(bSum);

        for (int ap = 0; ap < aSum.size(); ++ap) {
            int val = t - aSum.get(ap);
            int high = upper_bound(bSum, val);
            int low = lower_bound(bSum, val);
            ans += high - low;
        }
        System.out.println(ans);
    }
}
