#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    
    return strA + strB > strB + strA;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    bool allZero = true;
    for (int number : numbers) {
        if (number != 0) allZero = false;
        answer += to_string(number);
    }
    
    if (allZero) return "0";
    else return answer;
}

// 반례) [0, 0, 0, 0], 0