import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        int sum = 0; // 산술평균 계산
        List<Integer> arr = new ArrayList<>(); // 중앙값, 범위 계산
        HashMap<Integer, Integer> hm = new HashMap<>(); // 최빈값 계산

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());

            sum += num;
            arr.add(num);
            int cnt = hm.getOrDefault(num, 0);
            hm.put(num, cnt+1);
        }

        double avg = (double) sum / arr.size();
        // 산술평균
        System.out.println((int)Math.round(avg));
        // 중앙값
        Collections.sort(arr);
        System.out.println(arr.get(arr.size()/2));
        // 최빈값
        List<Integer> maxCntArr = new ArrayList<>();
        int maxCnt = Collections.max(hm.values());
        for(Integer num : hm.keySet()) {
            if (hm.get(num) == maxCnt) maxCntArr.add(num);
        }
        Collections.sort(maxCntArr);
        if (maxCntArr.size() == 1) System.out.println(maxCntArr.get(0));
        else {
            Collections.sort(maxCntArr);
            System.out.println(maxCntArr.get(1));
        }
        // 범위
        System.out.println(Collections.max(arr) - Collections.min(arr));
    }

}
