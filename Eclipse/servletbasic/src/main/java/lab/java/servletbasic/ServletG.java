package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ServletG extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		ServletContext context = getServletContext();
		String attr1 = (String) context.getAttribute("company");
		out.print("<br>company=" + attr1);

		out.close();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		String n = request.getParameter("userName");
		out.print("Welcome " + n);

		Cookie ck = new Cookie("uname", n);
		response.addCookie(ck);

		HttpSession session = request.getSession();
		session.setAttribute("uname", n);

		out.print("<form action='ServletH'>");
		out.print("<input type='submit' value='go'>");
		out.print("</form>");
		out.close();
	}
}