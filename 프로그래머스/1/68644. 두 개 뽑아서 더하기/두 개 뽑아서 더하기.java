import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < numbers.length-1; i++) {
            for (int j = i+1; j < numbers.length; j++) {
                s.add(numbers[i] + numbers[j]);
            }
        }
        
        List<Integer> result = new ArrayList<>(s);
        Collections.sort(result);
        
        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}