import java.util.*;

public class Solution {
    public int[] solution(int []arr) {        
        Stack<Integer> s = new Stack<Integer>();
        
        for (int elem : arr) {
            if (s.empty()) s.push(elem);
            else {
                if (s.peek() != elem) s.push(elem);
            }
        }
        
        List<Integer> answer = new ArrayList<>();
        while (!s.empty()) {
            answer.add(s.pop());
        }
        Collections.reverse(answer);

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}