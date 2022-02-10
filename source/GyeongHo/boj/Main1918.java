import java.io.*;
import java.util.*;

public class Main1918 {
    public static Stack<Character> st = new Stack<>();
    public static Map<Character, Integer> oper = new HashMap<Character, Integer>() {{
        put('(', 0);
        put('+', 1);
        put('-', 1);
        put('*', 2);
        put('/', 2);
    }};

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String sentence = br.readLine();

        for (int i = 0; i < sentence.length(); ++i) {
            char tmp = sentence.charAt(i);
            if (oper.containsKey(tmp)) {
                while(!st.isEmpty() && tmp != '(' && oper.get(st.peek()) >= oper.get(tmp)) {
                    char tmp2 = st.pop();
                    if (tmp2 != '(' && tmp2 != ')')
                        sb.append(tmp2);
                }
                st.push(tmp);
            }
            else if (tmp == '(') {
                st.push(tmp);
            }
            else if (tmp == ')') {
                while (st.peek() != '(')
                    sb.append(st.pop());
                st.pop();
            }
            else
                sb.append(tmp);
        }
        while (!st.isEmpty()) {
            char tmp = st.pop();
            if (tmp != '(' && tmp != ')')
                sb.append(tmp);
        }
        System.out.print(sb);
    }
}