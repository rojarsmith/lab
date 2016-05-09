package lab.run.executable;

import java.io.IOException;

public class RunExecutableFile {

	public static void main(String[] args) {

		Process process;

		try {
			process = Runtime.getRuntime().exec("../JavaRunExecutableFileCppExe/Release/JavaRunExecutableFileCppExe.exe aaa bbb");
			process.waitFor();
			int returnCode = process.exitValue();		
			System.out.println(returnCode);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (Exception e){
			e.printStackTrace();
		}

		return;
	}
}
