import java.io.*;

public class Fibonacci {
    static long fibonacci(int n) {
        long[] memoization = new long[n + 1];

        memoization[0] = 0;
        memoization[1] = 1;

        for (int i = 2; i <= n; i++)
            memoization[i] = memoization[i - 1] + memoization[i - 2];

        return memoization[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        bw.write(fibonacci(n) + "\n");

        br.close();
        bw.close();
    }
}
