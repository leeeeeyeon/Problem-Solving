#include <string>
#include <vector>

#include <iostream>

using namespace std;

// number를 n진수로 변환
string convert(int number, int n) {
    string result = "";
    
    while(number > 0) {
        string temp = "";
        if (number % n >= 10) {
            temp += 'A' + (number % n - 10);
        } else {
            temp = to_string(number % n);
        }
        
        result = temp + result;
        number /= n;
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    // 1. 0부터 t*m까지의 수를 준비한다 (numbers)
    vector<int> numbers;
    for (int i = 0; i <= t*m; i++) {
        numbers.push_back(i);
    }
    
    // 2. numbers를 n진수로 바꾸어 문자열을 만든다
    string game = "0";
    for (int i = 0; i < numbers.size(); i++) {
        string convertedNumber = convert(numbers[i], n);
        game += convertedNumber;
    }
    
    // 3. 그 중 x번째 수들만 골라서 answer에 추가한다
    int i = p-1;
    while(answer.size() < t) {
        answer += game[i];
        i += m;
    }
    
    return answer;
}