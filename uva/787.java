import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextInt()) {
      ArrayList<BigInteger> Arr = new ArrayList<BigInteger>();
      while(true) {
        BigInteger Number = BigInteger.valueOf(sc.nextInt());
        if(Number.intValue() == -999999) break;
        if(Arr.size() > 0 && Arr.get(Arr.size()-1).compareTo(BigInteger.ZERO) != 0)
          Number = Number.multiply(Arr.get(Arr.size()-1));
        Arr.add(Number);
      }
      BigInteger Ans = Arr.get(0);
      for(int i = 1; i < Arr.size(); ++i) Ans = Ans.max(Arr.get(i));
      for(int i = 0; i < Arr.size(); ++i) {
        if(Arr.get(i).compareTo(BigInteger.ZERO) == 0) continue; 
        for(int j = i+1; j < Arr.size() && Arr.get(j).compareTo(BigInteger.ZERO) != 0; ++j)
          Ans = Ans.max(Arr.get(j).divide(Arr.get(i)));
      }
      System.out.println(Ans);
    }
  }
}
