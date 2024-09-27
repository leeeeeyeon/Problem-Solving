#include <string>
#include <vector>

using namespace std;

// n을 k진수로 변환
string convert(int n, int k) {
    string result = "";
    
    while (n > 0) {
        int temp = n % k;
        result = to_string(temp) + result;
        n /= k;
    }
    
    return result;
}

bool isPrime(long n) {
    if (n == 1) return false;
    
    for (long i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    // 1. n을 k진수로 변환한다 (number)
    string number = convert(n, k);
    
    // 2. 0을 기준으로 number를 split
    vector<long> arr;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '0') continue;
        else {
            string elem = "";
            
            while(number[i] != '0') {
                elem += number[i];
                i++;
                
                if (i >= number.size()) break;
            }
            
            arr.push_back(stol(elem));
        }
    }
    
    // 3. numbers에서 소수인 수를 찾는다
    for (long elem : arr) {
        if (isPrime(elem)) answer++;
    }
    
    return answer;
}

// 반례) n = 797161, k = 3일 경우 변환하면 1111111111111 >>> int 초과