using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;

    while(true) {
        if (a == b) break;
        
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
    }
    
    
    return answer;
}

// 참고: https://eunhee-programming.tistory.com/145
