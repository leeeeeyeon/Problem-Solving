import java.util.*;

class Solution {
    public int solution(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for (int num : nums) {
            hm.put(num, hm.getOrDefault(num, 0)+1);
        }
        
        if (hm.size() > nums.length/2) {
            return nums.length/2;
        } else {
            return hm.size();
        }
    }
}