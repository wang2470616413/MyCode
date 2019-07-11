
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
              while(t-- != 0)
              {
            	  num = cin.nextBigInteger(10);
            	  BigInteger a = num;
            	  BigInteger mark0 = new BigInteger("0");
            	  BigInteger mark1 = new BigInteger("3");
            	  BigInteger mark = mark1;
            	  while(mark.min(a)== mark)
            	  {
            		  mark = (mark1.multiply(new BigInteger("6")).subtract(mark0)).add(new BigInteger("2"));
            		  mark0 = mark1;
            		  mark1 = mark;
            	  }
            	  System.out.println(mark);
              }
         }
}
