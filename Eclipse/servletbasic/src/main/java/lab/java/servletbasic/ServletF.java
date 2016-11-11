package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletF extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		ServletConfig config = getServletConfig();
		String driver = config.getInitParameter("driver");
		out.print("Driver is: " + driver);
		
		Enumeration<String> names = config.getInitParameterNames();		
		String tmp = "";
		while(names.hasMoreElements()){
			tmp=names.nextElement();
			out.print("<br>Name:" + tmp);
			out.print(" Value:" + config.getInitParameter(tmp));
		}
		
		ServletContext context = getServletContext();
		String driverName = context.getInitParameter("Dname");
		out.print("<br>driver name is=" + driverName);
		
		context.setAttribute("company", "IBM");		
		
		out.close();
	}
}
