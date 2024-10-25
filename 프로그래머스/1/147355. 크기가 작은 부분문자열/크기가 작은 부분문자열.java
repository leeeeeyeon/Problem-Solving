class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        
        for (int i = 0; i <= t.length() - p.length(); i++) {
            // t에서 i번째 문자부터 i + p.size()번째 문자까지 부분 문자열을 만든다
            String temp = t.substring(i, i+p.length());
            
            // p보다 작거나 같으면 answer++
            if (temp.compareTo(p) <= 0) answer++;
        }
        
        return answer;
    }
}