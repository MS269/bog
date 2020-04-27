import java.io.*;
import java.util.StringTokenizer;

public class RGBStreet {
    static final int MAX = 1000;

    static int[][] cost = new int[MAX + 1][3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            cost[i][0] = Integer.parseInt(st.nextToken()) + Math.min(cost[i - 1][1], cost[i - 1][2]);
            cost[i][1] = Integer.parseInt(st.nextToken()) + Math.min(cost[i - 1][0], cost[i - 1][2]);
            cost[i][2] = Integer.parseInt(st.nextToken()) + Math.min(cost[i - 1][0], cost[i - 1][1]);
        }

        int minCost = Math.min(Math.min(cost[n][0], cost[n][1]), cost[n][2]);

        bw.write(minCost + "\n");

        br.close();
        bw.close();
    }
}
