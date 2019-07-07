
import java.math.*; 
 
import java.util.*;  

public class Main
{
         public static void main(String args[])
         {
              Scanner cin = new Scanner(System.in);     
              BigInteger num;  
              int t;
              t = cin.nextInt();
              
              for(int i = 1; i <= t; i++)
              {
            	  num = cin.nextBigInteger(10);
            	  int k = 0;
            	  while(!num.equals(new BigInteger("0")))
            	  {
            		  num = num.divide(new BigInteger("2"));
            		  k = k + 1;
            	  }
            	  System.out.println(new BigInteger("2").pow(k - 1));
              }
              
              
              
         }
}
