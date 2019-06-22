import java.util.Scanner;
import java.math.BigInteger;

public class Main {
  static Scanner sc = new Scanner(System.in);
  public static void main(String[] args) {
    BigInteger fact[] = new BigInteger [302];

    fact[0] = BigInteger.ONE;
    for(int i = 1; i < 302; i++){
       fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
    }

    BigInteger cat[] = new BigInteger [302];
    cat[0] = BigInteger.ONE;
    for(int i = 1; i < 302; i++){
      cat[i] = BigInteger.ZERO;
      for(int j = 0; j < i; j++){
        cat[i] = cat[i].add(cat[j].multiply(cat[i - j - 1]));
      }
    }

    while(sc.hasNext()){
       int n = sc.nextInt();
       if(n == 0)
        break;
       System.out.println(fact[n].multiply(cat[n]));
    }
  }
}
