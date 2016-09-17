package masterSpringMvc.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.social.twitter.api.SearchResults;
import org.springframework.social.twitter.api.Twitter;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

	@Autowired
	private Twitter twitter;	
	
	@RequestMapping("/helloTwitter")
	public String helloTwitter(@RequestParam(defaultValue = "RojarSmith") String search, Model model){
		SearchResults searchResult = twitter.searchOperations().search(search);
		String text = searchResult.getTweets().get(0).getText();
		model.addAttribute("message", text);
		return "resultPage2";
	}
	
	@RequestMapping("/helloInput2")
	public String helloInput2(@RequestParam(defaultValue = "Rojar") String name, Model model){
		model.addAttribute("message", "Hello, " + name);
		return "resultPage2";
	}
	
	@RequestMapping("/helloInput")
	public String helloInput(@RequestParam("name") String userName, Model model){
		model.addAttribute("message", "Hello, " + userName);
		return "resultPage2";
	}
	
	@RequestMapping("/helloModel")
	public String helloModel(Model model){
		model.addAttribute("message", "Hello from the controller");
		return "resultPage2";
	}
	
	@RequestMapping("/helloPage")
	public String helloPage(){
		return "resultPage";
	}
	
	@RequestMapping("/helloString")
	@ResponseBody
	public String helloString(){
		return "Hello World";
	}
}
