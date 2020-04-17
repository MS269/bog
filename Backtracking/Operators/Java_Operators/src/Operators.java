import java.io.*;
import java.util.StringTokenizer;

public class Operators {
    static int n;
    static int[] numbers;
    static int[] operators = new int[4];
    static int maxNum = -1000000000;
    static int minNum = 1000000000;

    static void insertOperators(int num, int add, int sub, int mul, int div, int cnt) {
        if (cnt == n) {
            maxNum = Math.max(maxNum, num);
            minNum = Math.min(minNum, num);
            return;
        }

        if (add != 0)
            insertOperators(num + numbers[cnt], add - 1, sub, mul, div, cnt + 1);
        if (sub != 0)
            insertOperators(num - numbers[cnt], add, sub - 1, mul, div, cnt + 1);
        if (mul != 0)
            insertOperators(num * numbers[cnt], add, sub, mul - 1, div, cnt + 1);
        if (div != 0)
            insertOperators(num / numbers[cnt], add, sub, mul, div - 1, cnt + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        numbers = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            numbers[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++)
            operators[i] = Integer.parseInt(st.nextToken());

        insertOperators(numbers[0], operators[0], operators[1], operators[2], operators[3], 1);

        bw.write(maxNum + "\n");
        bw.write(minNum + "\n");

        br.close();
        bw.close();
    }
}
