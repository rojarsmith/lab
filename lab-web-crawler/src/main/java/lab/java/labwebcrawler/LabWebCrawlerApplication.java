package lab.java.labwebcrawler;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import edu.uci.ics.crawler4j.crawler.CrawlConfig;
import edu.uci.ics.crawler4j.crawler.CrawlController;
import edu.uci.ics.crawler4j.fetcher.PageFetcher;
import edu.uci.ics.crawler4j.robotstxt.RobotstxtConfig;
import edu.uci.ics.crawler4j.robotstxt.RobotstxtServer;

@SpringBootApplication
public class LabWebCrawlerApplication implements CommandLineRunner {

	private static Logger LOG = LoggerFactory.getLogger(LabWebCrawlerApplication.class);

	public static void main(String[] args) {
		SpringApplication.run(LabWebCrawlerApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		LOG.info("EXECUTING : command line runner");

		for (int i = 0; i < args.length; ++i) {
			LOG.info("args[{}]: {}", i, args[i]);
		}

		// String crawlStorageFolder = "/data/crawl/root";
		String crawlStorageFolder = "E:\\temp\\test";
		int numberOfCrawlers = 7;

		CrawlConfig config = new CrawlConfig();
		config.setCrawlStorageFolder(crawlStorageFolder);

		// Instantiate the controller for this crawl.
		PageFetcher pageFetcher = new PageFetcher(config);
		RobotstxtConfig robotstxtConfig = new RobotstxtConfig();
		RobotstxtServer robotstxtServer = new RobotstxtServer(robotstxtConfig, pageFetcher);
		CrawlController controller;

		controller = new CrawlController(config, pageFetcher, robotstxtServer);
		// For each crawl, you need to add some seed urls. These are the first
		// URLs that are fetched and then the crawler starts following links
		// which are found in these pages
		controller.addSeed("https://www.ics.uci.edu/~lopes/");
		controller.addSeed("https://www.ics.uci.edu/~welling/");
		controller.addSeed("https://www.ics.uci.edu/");

		// The factory which creates instances of crawlers.
		CrawlController.WebCrawlerFactory<MyCrawler> factory = MyCrawler::new;

		// Start the crawl. This is a blocking operation, meaning that your code
		// will reach the line after this only when crawling is finished.
		controller.start(factory, numberOfCrawlers);
	}
}
