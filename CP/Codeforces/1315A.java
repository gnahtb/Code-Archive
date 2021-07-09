import java.util.Scanner;

public class Solve1315A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        while (test > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int ans = 0;
            ans = Math.max(ans, x * b);
            ans = Math.max(ans, (a - x - 1) * b);
            ans = Math.max(ans, a * y);
            ans = Math.max(ans, a * (b - y - 1));
            System.out.println(ans);
            --test;
        }
        sc.close();
    }
}
