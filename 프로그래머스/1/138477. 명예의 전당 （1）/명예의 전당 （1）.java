import java.util.*;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < score.length; i++) {
            int elem = score[i];
            pq.offer(elem);
            
            if (pq.size() > k) pq.poll();
            
            answer[i] = pq.peek();
        }
        
        return answer;
    }
}