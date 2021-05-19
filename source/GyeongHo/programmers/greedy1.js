function solution(n, lost, reserve) {
    let cloth = new Array(n + 1).fill(0);
    let answer = 0;
    
    for (let i of lost) {
        cloth[i] -= 1;
    }
    for (let i of reserve) {
        cloth[i] += 1;
    }
    
    for (let i = 1; i <= n; ++i) {
        if (cloth[i] < 0 && i - 1 >= 0 && cloth[i - 1] === 1) {
            cloth[i] = 0;
            cloth[i - 1] = 0;
        }
        if (cloth[i] < 0 && i + 1 <= n && cloth[i + 1] === 1) {
            cloth[i] = 0;
            cloth[i + 1] = 0;
        }
    }
    
    for (let i = 1; i <= n; ++i) {
        if (cloth[i] > -1)
            ++answer;
    }
    return answer;
}