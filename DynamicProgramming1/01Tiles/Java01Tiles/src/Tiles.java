import java.io.*;

public class Tiles {
    static final int MAX = 1000000;
    static final int MOD = 15746;

    static int n;
    static int[] d = new int[MAX + 1];

    static void getTiles() {
        d[0] = 0;
        d[1] = 1;
        d[2] = 2;

        for (int i = 3; i <= n; i++) {
            d[i] = (d[i - 1] + d[i - 2]) % MOD;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        getTiles();

        bw.write(d[n] + "\n");
        bw.flush();
    }
}
