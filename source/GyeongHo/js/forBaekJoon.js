let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let count = input[0];
let numbers = [];

for (let i = 1; i < input.length; i++) {
  if (input[i] !== '') {
    numbers.push(input[i].split(' '));
  }
}

/*여기까지 했을 때,
count에는 숫자 하나 그리고 numbers에는 [[], [], []]이런 식으로 줄별로 나뉘어서 들어감.
첫 번째 줄에 테스트케이스의 개수, 그 뒤로 각각의 테스트케이스가 주어진다는 것을 가정하고 쓴 코드임.
*/

for (let i = 0; i < numbers.length; i++){
  let num1 = Number(numbers[i][0]);
  let num2 = Number(numbers[i][1]);

  console.log(num1 + num2);
}