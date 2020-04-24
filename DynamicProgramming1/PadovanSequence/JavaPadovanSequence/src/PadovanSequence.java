import java.io.*;

public class PadovanSequence {
    static final int MAX = 100;

    static long[] padovanSequence = new long[MAX + 1];

    static void getPadovanSequence() {
        padovanSequence[0] = 0;
        padovanSequence[1] = 1;
        padovanSequence[2] = 1;
        padovanSequence[3] = 1;

        for (int i = 4; i <= MAX; i++)
            padovanSequence[i] = padovanSequence[i - 2] + padovanSequence[i - 3];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        getPadovanSequence();

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            bw.write(padovanSequence[n] + "\n");
        }

        br.close();
        bw.close();
    }
}
