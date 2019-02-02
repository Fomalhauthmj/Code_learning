import java.math.BigInteger;

public class Test1018{
    public static void main(String[] args)
    {
        //System.out.println("test!");
        BigInteger fib[]=new BigInteger[1010];
        fib[0]=BigInteger.valueOf(1);
        fib[1]=BigInteger.valueOf(1);
        for(int i=2;i<=1000;i++)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
        }
        BigInteger x=fib[1000];
        BigInteger y=fib[999];
        String ans[]=new String[1100];
        for(int i=0;i<1000;i++)
        {
            ans[i]=y.divide(x).toString();
            y=y.remainder(x).multiply(BigInteger.valueOf(10));
        }
        for(int i=0;i<102;i++)
        {
            System.out.print(ans[i]);
        }
        System.out.println();
    }
}