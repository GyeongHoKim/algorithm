import java.util.*;
import java.util.stream.*;
import java.io.*;

public class 가장큰수 {
	public static void main(String[] args) throws IOException {
		Solution tmp = new Solution();
		int[] param = new int[] {6, 10, 2};
		System.out.println(tmp.solution(param));
	}
}

class Solution {
	public String solution(int[] numbers) {
		String answer = IntStream.of(numbers)
			.mapToObj(String::valueOf)
			.sorted((s1, s2) -> (s2 + s1).compareTo(s1 + s2))
			.collect(Collectors.joining());

		if (answer.startsWith("0"))
			return "0";
		return answer;
	}
}
