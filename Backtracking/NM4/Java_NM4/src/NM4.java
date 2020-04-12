import java.io.*;
import java.util.StringTokenizer;

public class NM4 {
    static final int MAX = 8 + 1;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static int[] numList = new int[MAX];

    static void combinationWithRepetition(int cnt, int cur) throws IOException {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                bw.write(numList[i] + " ");
            }
            bw.newLine();
            return;
        }

        for (int i = cur; i <= n; i++) {
            numList[cnt] = i;
            combinationWithRepetition(cnt + 1, i);
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        combinationWithRepetition(0, 1);

        bw.flush();
    }
}
