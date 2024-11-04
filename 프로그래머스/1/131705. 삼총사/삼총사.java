import java.util.*;

class Solution {
    
    int answer = 0;
    boolean[] visited = new boolean[13];
    
    public void combi(int idx, int[] number, List<Integer> arr) {
        if (arr.size() == 3) {
            int sum = 0;
            
            for (int elem : arr) {
                sum += elem;
            }
            
            if (sum == 0) answer++;
        }
        
        for (int i = idx; i < number.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr.add(number[i]);
                
                combi(i+1, number, arr);
                
                visited[i] = false;
                arr.remove(arr.size()-1);
            }
        }
    }
    
    
    public int solution(int[] number) {        
        List<Integer> arr = new ArrayList<>();
        combi(0, number, arr);
        
        return answer;
    }
}