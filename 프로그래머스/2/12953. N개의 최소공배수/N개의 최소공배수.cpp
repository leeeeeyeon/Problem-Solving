#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
    int mx = max(a, b);
    int mn = min(a, b);
    
    int r = mx % mn;
    
    if (r == 0) return mn;
    else return gcd(mn, r);
}

// 최소공배수
int lcm(int a, int b) {
    int c = gcd(a, b);
    
    return a * b / c;
}


int solution(vector<int> arr) {
    int answer = 0;
    
    // Point) 최소공배수 = 최대공약수 * (원소를 최대공약수로 나눈 값)
    
    // 원소가 1개일 경우 return
    if (arr.size() == 1) return arr[0];
    
    // 원소가 2개일 경우
    if (arr.size() == 2) return lcm(arr[0], arr[1]);
    
    // 원소가 3개 이상일 경우
    // 반복문을 돌며 두 수의 최소공배수를 구하는 과정을 반복
    answer = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}