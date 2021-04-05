let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let day = Number(input[0]);
let numbers = [];
let count = 0;

for (let i = 1; i < input.length; i++) {
  if (input[i] !== '') {
    numbers.push(input[i].split(' '));
  }
}

for (let i of numbers[0]) {
    if (Number(i) % 10 == day) {
        ++count;
    }
}

console.log(count);