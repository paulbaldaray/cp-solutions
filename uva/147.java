import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int coins[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
    long[] dp = new long[6010]; dp[0] = 1;
    for(int c : coins)
      for(int p = 0; p <= 6000; ++p)
        if(dp[p] > 0 && p+c <= 6000)
          dp[p+c] += dp[p];
    while(true) {
      double init_price = sc.nextDouble();
      if(init_price == 0) break;
      int price = (int) (init_price*20.0+.5);
      System.out.printf("%6.2f%17d\n", init_price, dp[price]);
    }
  }
}
