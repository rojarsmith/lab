/*
Given four digits, find the maximum valid time that can be displayed on a digital clock (in 24 -hour format) using those digits.
for example, given digits 2,3,5,9 the maximum valid time is "23:59".

note that "24:39" is not a valid time.

Answer should be in format "HH:MM" or "NOT POSSIBLE".
A,B,C,D can have value range 0 to 9.
 */

package lab.algorithm;

import java.util.regex.Pattern;

public class MaximumPossibleValidTime {
	// 1.Make all possible combination of four digits.
	// 2.Validate them against a regular expression.
	// 3.convert valid solution into seconds.
	// 4.Maximum seconds is the answer.	
	static String INVALID_INPUT ="NOT POSSIBLE";
	static String TIME24HOURS_PATTERN = "^(0[0-9]|1[0-9]|2[0-3])[0-5][0-9]$";

	public static String solution(int A, int B, int C, int D) {
		StringBuilder sb = new StringBuilder();
		sb.append(A);
		sb.append(B);
		sb.append(C);
		sb.append(D);

		StringBuilder output = new StringBuilder();
		permutation("", sb.toString(),output);

		String[] out = output.toString().split(";");

		int max = 0;
		String outputFormat = INVALID_INPUT;
		for(String s : out) {
			if(Pattern.matches(TIME24HOURS_PATTERN, s)) {
				if(max < Integer.parseInt(s)) {
					max = Integer.parseInt(s);
					outputFormat = s;
				}
			}
		}

		if(outputFormat.equals(INVALID_INPUT)) {
			return outputFormat;
		} else {
			return outputFormat.substring(0, 2) + ":" + outputFormat.substring(2, 4);
		}
	}

	private static void permutation(String prefix,String str,StringBuilder output) {
		int n = str.length();
		if (n == 0){
			output.append(prefix+";");
		}
		else {
			for (int i = 0; i < n; i++)
				permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n), output);
		}
	}
}
