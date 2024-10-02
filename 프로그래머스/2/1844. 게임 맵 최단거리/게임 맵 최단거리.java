import java.util.*;

class Solution {
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};
    
    public int solution(int[][] maps) {
        int answer = Integer.MAX_VALUE;
        
        int n = maps.length;
        int m = maps[0].length;
        
        boolean[][] visited = new boolean[n][m]; // 방문여부
        
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0, 0, 1));
        visited[0][0] = true;
        
        while(!q.isEmpty()) {
            Point cur = q.poll();
            if (cur.x == n-1 && cur.y == m-1) {
                answer = Math.min(answer, cur.d);
                break;
            } 
            
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (maps[nx][ny] == 0) continue;
                if (visited[nx][ny]) continue;
                
                q.add(new Point(nx, ny, cur.d + 1));
                visited[nx][ny] = true;
            }
        }
        
        if (answer == Integer.MAX_VALUE) return -1;
        else return answer;
    }
    
    public class Point {
        int x;
        int y;
        int d;
        
        Point(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }
}