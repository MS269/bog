import java.io.*;

public class FibonacciFunction {
    static final int MAX = 41;

    static int[] memo0 = new int[MAX];
    static int[] memo1 = new int[MAX];

    static void fibonacciFunction() {
        memo0[0] = 1;
        memo1[0] = 0;
        memo0[1] = 0;
        memo1[1] = 1;

        for (int i = 2; i < MAX; i++) {
            memo0[i] = memo0[i - 1] + memo0[i - 2];
            memo1[i] = memo1[i - 1] + memo1[i - 2];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        fibonacciFunction();

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            bw.write(memo0[n] + " " + memo1[n] + "\n");
        }

        bw.flush();
    }
}
