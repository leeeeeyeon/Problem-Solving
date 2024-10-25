import java.util.*;

class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        // 최대공약수
        int a = 1;
        int mn = Math.min(n, m);
        for (int i = mn; i >= 1; i--) {
            if (n % i == 0 && m % i == 0) {
                a = i;
                break;
            }
        }
        
        // 최소공배수
        int b = (n / a) * (m / a) * a;
        
        answer[0] = a;
        answer[1] = b;
        
        return answer;
    }
}