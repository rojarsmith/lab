package lab.algorithm;

public class Fibonacci {
	//Extension of Fibonacci
	public static long f1(int n){
		return	n <= 4 ?  1 :  f1(n-1) + f1(n-2) + f1(n-3) + f1(n-4);
	}

	public static long f2(int n){
		if(n <= 4) return 1;
		int a = 1;
		int b = 1;
		int c = 1;
		int d = 1;		
		for(int i = 4; i<n;i++) {
			int temp = a+b+c+d;
			a = b;
			b = c;
			c = d;
			d = temp;
		}
		return	d;
	}
}
