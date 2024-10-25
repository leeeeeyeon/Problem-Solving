import java.util.*;

import java.io.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        
        Queue<String> q1 = new LinkedList<String>();
        Queue<String> q2 = new LinkedList<String>();
        
        for (String card : cards1) {
            q1.offer(card);
        }
        
        for (String card : cards2) {
            q2.offer(card);
        }
        
        for (String elem : goal) {
            if (!q1.isEmpty() && q1.peek().equals(elem)) {
                q1.poll();
            } else if (!q2.isEmpty() && q2.peek().equals(elem)) {
                q2.poll();
            } else {
                answer = "No";
                break;
            }
        }
        
        return answer;
    }
}