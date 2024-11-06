import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 돌의 개수
        int m = Integer.parseInt(st.nextToken()); // 크기가 작은 돌의 개수

        boolean[] smallRocks = new boolean[10001];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());

            smallRocks[num] = true;
        }

        // 2차원 DP
        int maxJump = (int)Math.sqrt(2*n);
        int[][] dp = new int[n+1][maxJump+2];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], 10001);
        }

        dp[1][0] = 0;
        for (int i = 2; i < dp.length; i++) {
            if (smallRocks[i]) continue;

            for (int j = 1; j < (int)Math.sqrt(2*i)+1; j++) {
                dp[i][j] = Math.min(dp[i-j][j-1], Math.min(dp[i-j][j], dp[i-j][j+1])) + 1;
            }
        }

        int answer = 10001;
        for (int elem : dp[n]) {
            answer = Math.min(answer, elem);
        }

        if (answer >= 10001) System.out.println(-1);
        else System.out.println(answer);
    }
}
