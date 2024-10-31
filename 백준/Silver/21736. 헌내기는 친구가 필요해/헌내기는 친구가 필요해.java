import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        Queue<Point> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                char c = line.charAt(j);
                board[i][j] = c;

                if (c == 'I') {
                    q.offer(new Point(i, j));
                    visited[i][j] = true;
                }
            }
        }

        // BFS
        int answer = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();

            for (int k = 0; k < 4; k++) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 'X') continue;
                if (visited[nx][ny]) continue;

                q.offer(new Point(nx, ny));
                visited[nx][ny] = true;
                if (board[nx][ny] == 'P') answer++;
            }
        }

        if (answer == 0) System.out.println("TT");
        else System.out.println(answer);
    }

    public static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
