#include <stdio.h>
#include <stdlib.h>
int main() {
	int T, input[6], D, R, *ans, dif;
	scanf("%d", &T);
	ans = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%d", &input[j]);
		}

		dif = input[2] - input[5];
		dif = dif * dif;

		R = input[2] + input[5];
		R = R * R;

		D = (input[0] - input[3]) * (input[0] - input[3]) +
			(input[1] - input[4]) * (input[1] - input[4]);
		if (D > R) {
			ans[i] = 0;
		}
		else if (D == R) {
			ans[i] = 1;
		}
		else if (D > dif){
			ans[i] = 2;
		}
		else if (D == dif) {
			if (D == 0) {
				ans[i] = -1;
			}
			else{
				ans[i] = 1;
			}
		}
		else {
			ans[i] = 0;
		}

	}
	for (int i = 0; i < T; i++) {
		printf("%d", ans[i]);
		if (i != T - 1) {
			printf("\n");
		}

	}



	free(ans);
	return 0;
}
