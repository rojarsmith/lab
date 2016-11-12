package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletPGSQL extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		try {
			ServletContext ctx = getServletContext();
			Connection con = (Connection) ctx.getAttribute("mycon");

			// retieving data from emp32 table
			PreparedStatement ps = con.prepareStatement("select * from company", ResultSet.TYPE_SCROLL_SENSITIVE,
					ResultSet.CONCUR_UPDATABLE);

			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				out.print("<br>" + rs.getString(1) + " " + rs.getString(2));
			}
			con.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

		out.close();
	}
}
