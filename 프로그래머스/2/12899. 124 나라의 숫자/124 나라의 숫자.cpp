#include <string>
#include <vector>
#include <cmath>

using namespace std;

string calculate(int k) {
    string result = "";
    while (k >= 0) {
        int lastNum = pow(2, k%3);
        result = to_string(lastNum) + result;
        
        k = k/3 - 1;
    }
    
    return result;
}

string solution(int n) {  
    int lastNum = pow(2, (n-1) % 3);
    if (n <= 3) return to_string(lastNum);
    
    return calculate(n-1);
}