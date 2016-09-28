package lab.algorithm;

import java.math.BigDecimal;
import java.util.regex.Pattern;

public class EntryPoint {

	static TimeMeter tm = new TimeMeter();

	public static void main(String[] args) {
		tm.resetNow();
		int[] A1={1,2,4,5,7,29,30};
		int[] A2={1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,29,30};
		int[] A3={1,2,3,4,5,7,8,9,10,11,12,14,15,16,17,18,19,20,21,22,23,29,30};
		int[] A4={1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
		int r1_TicketsNeededMinimumCost = TicketsNeededMinimumCost.solution(A1);
		tm.record("TicketsNeededMinimumCost.solution(A1)=" + r1_TicketsNeededMinimumCost);
		int r2_TicketsNeededMinimumCost = TicketsNeededMinimumCost.solution(A2);
		tm.record("TicketsNeededMinimumCost.solution(A2)=" + r2_TicketsNeededMinimumCost);
		int r3_TicketsNeededMinimumCost = TicketsNeededMinimumCost.solution(A3);
		tm.record("TicketsNeededMinimumCost.solution(A3)=" + r3_TicketsNeededMinimumCost);
		int r4_TicketsNeededMinimumCost = TicketsNeededMinimumCost.solution(A4);
		tm.record("TicketsNeededMinimumCost.solution(A4)=" + r4_TicketsNeededMinimumCost);
		
		tm.resetNow();
		String r1_MaximumPossibleValidTime = MaximumPossibleValidTime.solution(2,4,0,0);
		tm.record("MaximumPossibleValidTime.solution2(2,4,0,0)=" + r1_MaximumPossibleValidTime);
		String r2_MaximumPossibleValidTime = MaximumPossibleValidTime.solution(3,0,7,0);
		tm.record("MaximumPossibleValidTime.solution2(3,0,7,0)=" + r2_MaximumPossibleValidTime);

		tm.resetNow();
		int r1_DecimalZIP = DecimalZIP.solution(12,56);
		tm.record("DecimalZIP.solution(12,56)=" + r1_DecimalZIP);
		int r2_DecimalZIP = DecimalZIP.solution(123,67890);
		tm.record("DecimalZIP.solution(123,67890)=" + r2_DecimalZIP);

		tm.resetNow();
		long r1_Fibonacci = Fibonacci.f1(10);		
		tm.record("Fibonacci.f1(10)=" + r1_Fibonacci);		
		long r2_Fibonacci = Fibonacci.f1(28);
		tm.record("Fibonacci.f1(28)=" + r2_Fibonacci);
		long r3_Fibonacci = Fibonacci.f2(10);
		tm.record("Fibonacci.f2(10)=" + r3_Fibonacci);
		long r4_Fibonacci = Fibonacci.f2(28);
		tm.record("Fibonacci.f2(28)=" + r4_Fibonacci);

		tm.showRecords();
	}





















	//    private static int getsecond(String s) {
	//        int seconds = 0;
	//        for(int indx=0; indx<4; indx++) {
	//            int second =  Integer.parseInt(s.charAt(indx) +s.charAt(indx+1)+"");
	//            if(indx == 0) {
	//                seconds = seconds + second*3600;
	//                indx++;
	//            }  else {
	//                seconds = seconds + second*60;
	//                indx++;
	//            }
	//        }
	//        return seconds;
	//    }










	static String[] res = new String[24];
	static int pos = 0;

	public static  String solution3(int A, int B, int C, int D)
	{

		String str = A + "" + B + "" + C + "" + D;
		char[] charArry = str.toCharArray();
		permute(charArry, 0, 3);
		String maxstr = "0";
		for (int i = 0; i < 24; i++)
		{
			String a = res[i].toString().substring(2, 4);
			int subLeft = Integer.parseInt(res[i].toString().substring(0, 2));
			int subRight = Integer.parseInt(res[i].toString().substring(2, 4));

			if ((subLeft >= 0 && subLeft <= 23) && (subRight >= 0 && subRight <= 59))
			{
				if (Integer.parseInt(maxstr) < Integer.parseInt(res[i]))
				{
					maxstr = res[i];
				}
			}
		}

		if (maxstr == "0")
		{
			return "NOT POSSIBLE";
		}
		else
		{
			return maxstr.substring(0, 2) + ":" + maxstr.substring(2, 4);
		}

	}

	private static  void permute(char[] arry, int i, int n)
	{


		if (i == n)
		{
			res[pos] =  String.valueOf(arry[0]) + String.valueOf(arry[1]) + String.valueOf(arry[2]) + String.valueOf(arry[3]);
			pos++;
		}
		else
		{
			for (int j = i; j <= n; j++)
			{
				char tmp;
				tmp = arry[i];
				arry[i] = arry[j];
				arry[j] = arry[i];                

				permute(arry, i + 1, n);

				tmp = arry[i];
				arry[i] = arry[j];
				arry[j] = arry[i];                
			}
		}

	}






















}
