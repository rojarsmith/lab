package lab.blockchain.coinhelper;

import java.util.Map.Entry;
import java.util.NavigableMap;
import java.util.TreeMap;

public class App {
	public static void main(String[] args) {
		bitcoin_total_supply();
		digitslate_total_supply();
		zcore_total_supply();

		long seconds_in_1year = 365 * 24 * 60 * 60;
		long blocks1 = seconds_in_1year / 600;
		long blocks2 = seconds_in_1year / 90;
		long blocks3 = seconds_in_1year / 360;

		long v1 = blocks3 * 40;
		long v2 = blocks3 * 20;
		long v3 = v1 + v2;
		
		String formatted;
		
		System.out.println("[600s]Blocks=" + blocks1);
		System.out.println("[360s]Blocks=" + blocks3);
		System.out.println("[90s]Blocks=" + blocks2);		
		
		formatted = format((long) v3);
		System.out.println("Blocks=" + formatted);

}
	
	public static void bitcoin_total_supply() {
		long halve = 210000;
		long satoshi = 100000000;

		long total = 0;
		long reward = 50 * satoshi;
		int halve_count = 0;
		
		do {
			halve_count++;
			for (int i = 0; i < halve; i++) {
				total += reward;
			}
			reward /= 2;
			if (reward == 0) {
			}
		} while (reward != 0);
		
		System.out.println("[Bitcoin]");
		String formatted = format((long) total / satoshi);
		System.out.println("Total=" + formatted + ", Halve Count=" + halve_count);
	}

	public static void digitslate_total_supply() {
		long halve = 87600 / 12;
		long satoshi = 100000000;

		long total = 0;
		long reward = 50 * satoshi * 16;
		int halve_count = 0;
		
		do {
			halve_count++;
			for (int i = 0; i < halve; i++) {
				total += reward;
			}
			// reward3 /= ((long)Math.Pow( 2 , 1));
			reward /= 2;
			if (reward == 0) {
			}
		} while (reward != 0);

		System.out.println("[DigitSlate]");		
		String formatted = format((long) total / satoshi);
		System.out.println("Total=" + formatted + ", Halve Count=" + halve_count);
	}
	
	public static void zcore_total_supply() {
		long halve = 394200;
		long satoshi = 100000000;

		long total = 0;
		long reward = 10 * satoshi;
		int halve_count = 0;

		do {
			halve_count++;

			for (int i = 0; i < halve; i++) {
				total += reward;
			}
			reward = reward / 4 * 3;

			if (reward == 0) {

			}
		} while (reward != 0);

		System.out.println("[Zcore]");		
		String formatted = format((long) total / satoshi);
		System.out.println("Total=" + formatted + ", Halve Count=" + halve_count);	
	}
	
	private static final NavigableMap<Long, String> suffixes = new TreeMap<Long, String>();

	static {
		suffixes.put(1000L, "k");
		suffixes.put(1000000L, "M");
		suffixes.put(1000000000L, "G");
		suffixes.put(1000000000000L, "T");
		suffixes.put(1000000000000000L, "P");
		suffixes.put(1000000000000000000L, "E");
	}

	public static String format(long value) {
		// Long.MIN_VALUE == -Long.MIN_VALUE so we need an adjustment here
		if (value == Long.MIN_VALUE)
			return format(Long.MIN_VALUE + 1);
		if (value < 0)
			return "-" + format(-value);
		if (value < 1000)
			return Long.toString(value); // deal with easy case

		Entry<Long, String> e = suffixes.floorEntry(value);
		Long divideBy = e.getKey();
		String suffix = e.getValue();

		long truncated = value / (divideBy / 10); // the number part of the output times 10
		boolean hasDecimal = truncated < 100 && (truncated / 10d) != (truncated / 10);
		return hasDecimal ? (truncated / 10d) + suffix : (truncated / 10) + suffix;
	}
}