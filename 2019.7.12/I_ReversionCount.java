
import java.math.*; 
 
import java.util.*;  

public class Main
{
         public static void main(String args[])
         {
              Scanner cin = new Scanner(System.in);     
              BigInteger num;  
              while(cin.hasNext())
              {
            	  num = cin.nextBigInteger();
            	  BigInteger num0 = num;
            	  BigInteger num1 = new BigInteger("0");
            	  BigInteger mark = new BigInteger("1");
            	  int index = 1;
            	  int aux[] = new int[200];
            	  while(!num0.equals(new BigInteger("0")))
            	  {
            		  int temp = num0.mod(new BigInteger("10")).intValue();
            		  aux[index] = temp;
            		  index++;
            		  num0 = num0.divide(new BigInteger("10"));
            	  }
            	  for(int i = index - 1; i >= 1; i--)
            	  {
            		  num1 = num1.add(BigInteger.valueOf(aux[i]).multiply(mark));
            		  mark = mark.multiply(BigInteger.valueOf(10));
            	  }

            	  BigInteger res = (num.subtract(num1).abs()).divide(new BigInteger("9"));
            	  int data[] = new int[15];
            	  for(int i = 0; i < 15; i++)
            	  {
            		  data[i] = 0;
            	  }
            	  int flag = 0;
            	  mark = new BigInteger("1");
            	  int mark1 = res.mod(new BigInteger("10")).intValue();
            	  while(!res.equals(BigInteger.valueOf(0)))
            	  {
            		  int temp = res.mod(new BigInteger("10")).intValue();
            		  res = res.divide(new BigInteger("10"));
            		  if(temp != mark1)
            		  {
            			  flag = 1;
            			  break;
            		  }
            	  }
            	  if(flag == 0)
            	  {
            		  System.out.println("YES");
            	  }
            	  else
            	  {
            		  System.out.println("NO");
            	  }
              }

         }
}
