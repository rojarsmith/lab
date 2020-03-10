package lab.java.labwebcrawler;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import edu.uci.ics.crawler4j.crawler.Page;
import edu.uci.ics.crawler4j.crawler.WebCrawler;
import edu.uci.ics.crawler4j.parser.HtmlParseData;
import edu.uci.ics.crawler4j.url.WebURL;

public class MyCrawler extends WebCrawler {
	private final static Pattern FILTERS = Pattern.compile(".*(\\.(css|js|gif|jpg" + "|png|mp3|mp4|zip|gz))$");

	List<String> emails = new ArrayList<>();

	@Override
	public boolean shouldVisit(Page referringPage, WebURL url) {
		String href = url.getURL().toLowerCase();
		// return false, will not be crawled.
		return !FILTERS.matcher(href).matches() && href.startsWith("https://www.ics.uci.edu/");
	}

	@Override
	public void visit(Page page) {
		final String dir = System.getProperty("user.dir");
		System.out.println("current dir = " + dir);

		String url = page.getWebURL().getURL();
		System.out.println("URL: " + url);

		if (page.getParseData() instanceof HtmlParseData) {
			HtmlParseData htmlParseData = (HtmlParseData) page.getParseData();
			String text = htmlParseData.getText();
			String html = htmlParseData.getHtml();
			Set<WebURL> links = htmlParseData.getOutgoingUrls();

			System.out.println("Text length: " + text.length());
			System.out.println("Html length: " + html.length());
			System.out.println("Number of outgoing links: " + links.size());

			// Find mail and write to file.
			Matcher m = Pattern.compile("[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+").matcher(text);
			while (m.find()) {
				String email = m.group();
				System.out.println(email);

				try {
					if (!emails.contains(email)) {
						emails.add(email);
						Files.write(Paths.get(dir, "emails.txt"), (email + System.lineSeparator()).getBytes(),
								StandardOpenOption.CREATE, StandardOpenOption.APPEND);
					}
				} catch (IOException e) {
					System.out.println(e.toString());
				}
			}
		}
	}
}