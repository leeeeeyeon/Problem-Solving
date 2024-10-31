import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[][] board = new int[r][c];
        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < c; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 구간 합
        int[][] sumArr = new int[r+1][c+1];
        for (int i = 1; i < r+1; i++) {
            for (int j = 1; j < c+1; j++) {
                sumArr[i][j] = board[i-1][j-1] + sumArr[i-1][j] + sumArr[i][j-1] - sumArr[i-1][j-1];
            }
        }

        // 각 좌표별 밝기 평균 계산
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int sx = Integer.parseInt(st.nextToken()) - 1;
            int sy = Integer.parseInt(st.nextToken()) - 1;
            int ex = Integer.parseInt(st.nextToken()) - 1;
            int ey = Integer.parseInt(st.nextToken()) - 1;

            // 부분합
            int sum = sumArr[ex+1][ey+1] - sumArr[sx][ey+1] - sumArr[ex+1][sy] + sumArr[sx][sy];
            int divisor = (ex-sx+1) * (ey-sy+1);
            System.out.println(sum / divisor);
        }
    }
}
