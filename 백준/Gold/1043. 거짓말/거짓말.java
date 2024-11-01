import java.io.*;
import java.util.*;

public class Main {

    public static int[] parent = new int[53];

    public static int find(int a) {
        if (a == parent[a]) return a;

        return parent[a] = find(parent[a]);
    }

    public static void merge(int a, int b) {
        int A = find(a);
        int B = find(b);

        if (A != B) {
            if (A <= B) parent[B] = a;
            else parent[A] = b;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 사람의 수
        int n = Integer.parseInt(st.nextToken());
        // 파티의 수
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        // 진실을 아는 사람의 수
        int k = Integer.parseInt(st.nextToken());
        // 진실을 아는 사람 리스트
        List<Integer> truthArr = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            int num = Integer.parseInt(st.nextToken());
            truthArr.add(num);
        }

        // 파티별 오는 사람과 번호
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());

            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < cnt; j++) {
                int num = Integer.parseInt(st.nextToken());
                temp.add(num);
            }

            graph.add(temp);
        }

        if (k == 0) System.out.println(m);
        else { // Union-find
            // parent 초기화
            for (int i = 0; i < parent.length; i++) {
                parent[i] = i;
            }

            // merge (parent 업데이트를 위해 2번)
            for (int i = 0; i < 2; i++) {
                for (List<Integer> party : graph) {
                    Collections.sort(party);
                    for (int j = 1; j < party.size(); j++) {
                        merge(party.get(0), party.get(j));
                    }
                }
            }

            // parent[i]가 truth에 있으면 i를 truth에 추가
            HashSet<Integer> truth = new HashSet<>();
            for (int elem : truthArr) truth.add(parent[elem]);

            for (int i = 1; i <= n; i++) {
                if (truth.contains(parent[i])) truth.add(i);
            }

            // 파티를 순회하며 truth에 있는 수를 포함하면 answer--
            int answer = 0;
            for(List<Integer> party : graph) {
                HashSet<Integer> truthSet = new HashSet<>(truth);
                HashSet<Integer> partySet = new HashSet<>(party);

                // 교집합 계산
                // 겹치는 원소(사람)이 하나라도 있으면 거짓말 들통남
                truthSet.retainAll(partySet);
                if (truthSet.isEmpty()) answer++;
            }

            System.out.println(answer);
        }
    }

}
