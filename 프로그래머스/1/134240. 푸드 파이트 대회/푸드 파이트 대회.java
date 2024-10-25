class Solution {
    public String solution(int[] food) {
        String answer = "";
        
        for (int i = 1; i < food.length; i++) {
            String c = i + "";
            answer += c.repeat(food[i] / 2);
        }
        
        StringBuffer sb = new StringBuffer(answer);
        String temp = sb.reverse().toString();
        
        answer += '0';
        answer += temp;
        
        return answer;
    }
}