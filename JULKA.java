import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner br = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		while (br.hasNext())
		{
			BigInteger total = new BigInteger(br.nextLine());
			BigInteger more = new BigInteger(br.nextLine());
			
			total = total.subtract(more);
			total = total.divide(BigInteger.valueOf(2));
			
			BigInteger other = total;
			
			other = other.add(more);
			
			System.out.println(other);
			System.out.println(total);
		}
	}
}