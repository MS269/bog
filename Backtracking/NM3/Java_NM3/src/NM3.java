import java.io.*;
import java.util.StringTokenizer;

public class NM3 {
    static final int MAX = 7 + 1;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static int[] numList = new int[MAX];

    static void permutationWithRepetition(int cnt) throws IOException {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                bw.write(numList[i] + " ");
            }
            bw.newLine();
            return;
        }

        for (int i = 1; i <= n; i++) {
            numList[cnt] = i;
            permutationWithRepetition(cnt + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        permutationWithRepetition(0);

        bw.flush();
    }
}
