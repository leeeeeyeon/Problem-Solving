import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        Boolean allZero = true;
        for (int elem : scoville) {
            if (elem > 0) allZero = false;
            pq.offer(elem);
        }
        
        if (allZero) return -1;
        
        int cnt = 0;
        while (pq.peek() < K) {
            if (pq.size() == 1) return -1;
            
            int newFood = pq.poll() + pq.poll() * 2;
            pq.offer(newFood);
            cnt++;
        }
        
        return cnt;
    }
}