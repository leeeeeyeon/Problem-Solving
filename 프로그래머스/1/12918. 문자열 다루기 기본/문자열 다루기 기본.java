class Solution {
    public boolean solution(String s) {
        boolean answer = false;
        
        if (s.length() == 4 || s.length() == 6) {
            for (char c : s.toCharArray()) {
                if (!Character.isDigit(c)) {
                    answer = false;
                    break;
                } else {
                    answer = true;
                }
            }
        }
        
        return answer;
    }
}