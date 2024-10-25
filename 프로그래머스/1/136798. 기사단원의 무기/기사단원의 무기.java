import java.util.*;
import java.io.*;

class Solution {
    private int countFactors(int n) {
        int result = 0;
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (i == Math.sqrt(n)) result++;
            else {
                if (n % i == 0) result += 2;
            }
        }
        
        return result;
    }
    public int solution(int number, int limit, int power) {
        int answer = 0;
        
        for (int i = 1; i <= number; i++) {
            int cnt = countFactors(i);
            if (cnt > limit) answer += power;
            else answer += cnt;
        }
        
        return answer;
    }
}