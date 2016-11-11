package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ServletH extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		try {
			response.setContentType("text/html");
			PrintWriter out = response.getWriter();

			Cookie ck[] = request.getCookies();

			out.print("<br>Cookie");
			for (int i = 0; i < ck.length; i++) {
				out.print("<br>value=" + ck[i].getValue());
			}

			out.print("<br>Session");
			HttpSession session = request.getSession(false);
			Enumeration<String> names = session.getAttributeNames();
			while (names.hasMoreElements()) {
				String name = names.nextElement();
				out.print("<br>name=" + name + ", value=" + session.getAttribute(name));
			}

			out.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
