package masterSpringMvc.controller;

import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.social.twitter.api.SearchResults;
import org.springframework.social.twitter.api.Tweet;
import org.springframework.social.twitter.api.Twitter;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class TweetController {

	@Autowired
	private Twitter twitter;

	@RequestMapping("/showTwitter2")
	public String showTwitter2(@RequestParam(defaultValue = "RojarSmith") String search, Model model){
		SearchResults searchResult = twitter.searchOperations().search(search);
		List<Tweet> messages = searchResult.getTweets();		
		model.addAttribute("tweets", messages);
		model.addAttribute("search", search);
		return "resultTwitter2";
	}
	
	@RequestMapping("/showTwitter")
	public String showTwitter(@RequestParam(defaultValue = "RojarSmith") String search, Model model){
		SearchResults searchResult = twitter.searchOperations().search(search);
		List<String> messages = searchResult.getTweets()
				.stream()
				.map(Tweet::getText)
				.collect(Collectors.toList());		
		model.addAttribute("tweets", messages);
		return "resultTwitter";
	}
}
