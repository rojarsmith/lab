package lab.tomcat.embedded;

import java.io.File;
import java.util.Scanner;

import org.apache.catalina.core.StandardHost;
import org.apache.catalina.startup.Tomcat;

public class EmbeddedTomcatServer {

	private Tomcat tomcat;

	public EmbeddedTomcatServer() {
		try {
			String currentDir = System.getProperty("user.dir");
			String appDir = currentDir + File.separatorChar + "webapps";
			String tmpDir = currentDir + File.separatorChar + "tomcat_tmp";
			createDir(appDir);
			createDir(tmpDir);

			tomcat = new Tomcat();
			tomcat.setBaseDir(tmpDir); // Tomcat needs a directory for temp
										// files.
			tomcat.setPort(8080);

			StandardHost stdHost = (StandardHost) tomcat.getHost();
			stdHost.setAppBase(appDir);
			stdHost.setUnpackWARs(false);
			stdHost.setAutoDeploy(false);
			stdHost.setDeployOnStartup(false);
			tomcat.setHost(stdHost);
			tomcat.addWebapp("/", appDir); // A context path must either be an
											// empty string or start with a '/'.

			// 修正為不自動deploy ops.war檔
			// ，故註解掉 String appID = "ops.war";
			// File webApp = new File(appDir, appID);
			// if (!webApp.exists()) {
			// LOGGER.error("Can't find ops.war");
			// return;
			// }
			// tomcat.addWebapp(tomcat.getHost(), "/",
			// webApp.getAbsolutePath());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	private void createDir(String dirPath) {
		File dir = new File(dirPath);
		if (!dir.exists()) {
			dir.mkdir();
		}
	}

	public void start() {
		try {
			if (tomcat != null) {
				System.out.println("tomcat.start():Start");
				tomcat.start();
				// tomcat.getServer().await();
				System.out.println("tomcat.start():Success");
			}
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	public void stop() {
		try {
			if (tomcat != null) {
				tomcat.stop();
			}
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	/**
	 * @param args
	 *            the command line arguments
	 * 
	 *            test url=http://127.0.0.1:8080/
	 */
	public static void main(String[] args) {
		EmbeddedTomcatServer server = new EmbeddedTomcatServer();
		server.start();

		System.out.println("Input 'exit' to stop server");
		Scanner scanner = new Scanner(System.in);
		String cmd;
		do {
			cmd = scanner.next();
		} while (!cmd.equals("exit"));
		scanner.close();
		server.stop();
	}
}