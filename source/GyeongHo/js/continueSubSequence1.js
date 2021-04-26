function solution(m, arr) {
	let i = 0, j = 0, sum = 0, cnt = 0;
	while (i < arr.length) {
		if (sum >= m) {
			if (sum == m)
				++cnt;
			++i;
			j = i;
			sum = 0;
		}
		if (j >= arr.length)
			return cnt;
		sum += arr[j++];
	}
	return cnt;
}

let a = [1, 2, 1, 3, 1, 1, 1, 2];

try {
	console.log(solution(6, a));	
}
catch(err) {
	console.log(err);
}