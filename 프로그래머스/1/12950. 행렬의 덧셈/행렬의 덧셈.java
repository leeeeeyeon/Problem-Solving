import java.util.*;

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr1[0].length];
        
        List<List<Integer>> result = new ArrayList<>();
        
        for (int i = 0; i < arr1.length; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < arr1[0].length; j++) {
                temp.add(arr1[i][j] + arr2[i][j]);
            }
            result.add(temp);
        }
        
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(0).size(); j++) {
                answer[i][j] = result.get(i).get(j);
            }
        }
        
        return answer;
    }
}