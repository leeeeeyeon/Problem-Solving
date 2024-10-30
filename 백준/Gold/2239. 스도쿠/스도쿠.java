import java.io.*;
import java.util.*;

public class Main {

    public static int[][] board = new int[9][9];
    public static List<Point> blanks = new ArrayList<>();

    public static boolean finished = false;

    public static void checkSquare(int[][] board, boolean[] visited, int x, int y) {
        for (int i = 3*x; i < 3*x+3; i++) {
            for (int j = 3*y; j < 3*y+3; j++) {
                visited[board[i][j]] = true;
            }
        }
    }

    // 가로에 없는 숫자 + 세로에 없는 숫자 중 제일 작은거
    // 만약 없다면 go back
    public static void fillBoard(int[][] board, int idx) {
        // 재귀 탈출 조건: idx == blanks.size()면 모든 칸을 다 채운 것
        if (idx == blanks.size()) {
            finished = true;

            // 정답 출력
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(board[i][j]);
                }
                System.out.println();
            }

            return;
        }

        int cx = blanks.get(idx).x;
        int cy = blanks.get(idx).y;

        boolean[] visited = new boolean[10];

        // 가로 & 세로에 있는 숫자 체크
        for (int i = 0; i < 9; i++) {
            visited[board[cx][i]] = true;
            visited[board[i][cy]] = true;
        }

        // 사각형에 있는 숫자 체크
        checkSquare(board, visited, cx/3, cy/3);

        // 만약 모든 수가 visited라면 백트래킹으로 이전 칸으로 돌아가야 함
        boolean allVisited = true;
        for (int i = 1; i <= 9; i++) {
            if (!visited[i]) {
                allVisited = false;
                break;
            }
        }
        if (allVisited) return;

        for (int num = 1; num <= 9; num++) {
            if (!visited[num]) {
                board[cx][cy] = num;
                fillBoard(board, idx+1);
                if (finished) break;
                
                board[cx][cy] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력
        for (int i = 0; i < 9; i++) {
            String line = br.readLine();
            for (int j = 0; j < 9; j++) {
                int num = line.charAt(j) - '0';
                board[i][j] = num;

                if (num == 0) blanks.add(new Point(i, j));
            }
        }

        // 백트래킹
        fillBoard(board, 0);
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
