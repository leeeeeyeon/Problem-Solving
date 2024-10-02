import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int i = 0; i < commands.length; i++) {
            int[] command = commands[i];
            int[] subArray = Arrays.copyOfRange(array, command[0]-1, command[1]);
            Arrays.sort(subArray);
            
            answer[i] = subArray[command[2]-1];
        }
        
        return answer;
    }
}