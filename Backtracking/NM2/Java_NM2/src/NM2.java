import java.io.*;
import java.util.StringTokenizer;

public class NM2 {
    static final int MAX = 8 + 1;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static int[] numList = new int[MAX];
    static boolean[] checkList = new boolean[MAX];

    static void combination(int cnt, int cur) throws IOException {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                bw.write(numList[i] + " ");
            }
            bw.newLine();
            return;
        }

        for (int i = cur; i <= n; i++) {
            if (!checkList[i]) {
                numList[cnt] = i;
                checkList[i] = true;
                combination(cnt + 1, i + 1);
                checkList[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < MAX; i++) {
            checkList[i] = false;
        }

        combination(0, 1);

        bw.flush();
    }
}
