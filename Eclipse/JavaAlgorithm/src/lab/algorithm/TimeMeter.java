package lab.algorithm;

import java.math.BigDecimal;
import java.util.ArrayList;

public class TimeMeter {
	ArrayList<Record> records;
	long timePrevious;
	long timeNow;	

	public TimeMeter(){
		reset();		
	}

	public void record(String log){
		timePrevious = timeNow; 
		timeNow = System.nanoTime();
		Record r = new Record((timeNow-timePrevious)/1000000000.0, log);
		records.add(r);
				
	}

	public void setBegin(){
		timePrevious = System.nanoTime();
	}

	public void reset(){
		records = new ArrayList<>();
		timePrevious = System.nanoTime();
		resetNow();
	}
	
	public void resetNow(){
		timeNow = System.nanoTime();
	}

	public void showRecords(){
		for(int i=0;i< records.size();i++){
			showRecord(i);
		}		
	}
	
	public void showRecord(int index){
		BigDecimal bd = new BigDecimal(records.get(index).timeDifference);
		String formatStr = "%04d";
		String lineNumber = String.format(formatStr, index+1) + " :: ";
		System.out.println(lineNumber + records.get(index).log + "=" + bd.toPlainString() + " sec");
	}
	
	private class Record{		
		public double timeDifference;				
		public String log;
		
		public Record(double timeDifference, String log){
			this.timeDifference = timeDifference;
			this.log = log;
		}
	}	
}