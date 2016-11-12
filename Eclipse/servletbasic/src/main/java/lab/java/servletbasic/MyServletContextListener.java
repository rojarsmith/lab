package lab.java.servletbasic;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

public class MyServletContextListener implements ServletContextListener {
	public void contextDestroyed(ServletContextEvent event) {
	}

	public void contextInitialized(ServletContextEvent event) {
		try {
			String dbURL = "jdbc:postgresql://59.127.136.43:5542/test";
			String user = "postgres";
			String pass = "123ZXC$%";

			Class.forName("org.postgresql.Driver");
			Connection con = DriverManager.getConnection(dbURL, user, pass);

			// storing connection object as an attribute in ServletContext
			ServletContext ctx = event.getServletContext();
			ctx.setAttribute("mycon", con);

			// check table exist.
			String query = "SELECT EXISTS (\n   SELECT 1\n   FROM   information_schema.tables \n   WHERE  table_schema = \'public\'\n   AND    table_name = \'company\'\n);";

			PreparedStatement ps = con.prepareStatement(query);
			ps.execute();

			ResultSet rs = ps.executeQuery();
			boolean existTable1 = false;

			while (rs.next()) {
				existTable1 = rs.getBoolean(1);
			}

			if (false == existTable1) {
				query = "CREATE TABLE company(\n   ID INT PRIMARY KEY     NOT NULL,\n   NAME           TEXT    NOT NULL,\n   AGE            INT     NOT NULL,\n   ADDRESS        CHAR(50)\n);";
				ps = con.prepareStatement(query);
				ps.executeUpdate();

				query = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS) VALUES (4, 'Mark', 25, 'Rich-Mond '), (5, 'David', 27, 'Texas');";
				ps = con.prepareStatement(query);
				ps.executeUpdate();
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
