import java.io.*;
import java.util.*;

public class Main {

    public static int countZero(List<Integer> arr) {
        int cnt = 0;
        for (int num : arr) {
            if (num == 0) cnt++;
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<Integer> belt = new ArrayList<>();
        List<Boolean> robots = new ArrayList<>(); // 로봇이 존재하는 칸
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 2*n; i++) {
            int num = Integer.parseInt(st.nextToken());
            belt.add(num);
            robots.add(false);
        }

        int level = 0;
        while (true) {
            level++;

            // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
            Collections.rotate(robots, 1);
            Collections.rotate(belt, 1);

            robots.set(n-1, false);

            // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
            for (int i = n-2; i >= 0; i--) {
                // 이동하려는 칸에 로봇이 없고 내구도가 1 이상인 경우 로봇 이동
                if (robots.get(i) && !robots.get(i+1) && belt.get(i+1) > 0) {
                    // 현재 위치에 로봇이 없다고 표시
                    robots.set(i, false);

                    // 다음 위치에 로봇이 있다고 표시
                    robots.set(i+1, true);

                    // 다음 위치의 내구도 1만큼 감소
                    belt.set(i+1, belt.get(i+1)-1);
                }
            }

            robots.set(n-1, false);
            // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다
            if (belt.get(0) > 0) {
                robots.set(0, true);
                belt.set(0, belt.get(0)-1);
            }

            // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
            if (countZero(belt) >= k) break;
        }

        System.out.println(level);
    }
}

// 피드백) 로봇이 내리는 위치에 도달하면 그 즉시 내린다는 n+1번 칸으로 내리는 게 아니라 "벨트에서 제거한다"는 의미
