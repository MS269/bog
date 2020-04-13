import java.io.*;

public class NQueen {
    static int n, ans;
    static Boolean[] height, downTopDiagonal, topDownDiagonal;

    static void nQueen(int i) {
        if (i == n) {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (height[j] || downTopDiagonal[i + j] || topDownDiagonal[i - j + n - 1])
                continue;

            height[j] = true;
            downTopDiagonal[i + j] = true;
            topDownDiagonal[i - j + n - 1] = true;
            nQueen(i + 1);
            height[j] = false;
            downTopDiagonal[i + j] = false;
            topDownDiagonal[i - j + n - 1] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        height = new Boolean[n];
        downTopDiagonal = new Boolean[2 * n - 1];
        topDownDiagonal = new Boolean[2 * n - 1];

        for (int i = 0; i < n; i++) {
            height[i] = false;
            downTopDiagonal[i] = false;
            topDownDiagonal[i] = false;
        }

        for (int i = n; i < 2 * n - 1; i++) {
            downTopDiagonal[i] = false;
            topDownDiagonal[i] = false;
        }

        nQueen(0);

        bw.write(ans + "\n");

        br.close();
        bw.close();
    }
}
