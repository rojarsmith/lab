package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletC extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public void service(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {		
		String method = req.getMethod();
		if (method.equals("GET")) {
			doGet(req, res);
		}
	}

	public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
		res.setContentType("text/html"); // setting the content type
		PrintWriter pw = res.getWriter(); // get the stream to write the data

		// writing html in the stream
		pw.println("<html><body>");
		pw.println("Welcome to servlet");
		pw.println("</body></html>");

		pw.close();// closing the stream
	}

}
