package lab;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import lab.aspect.validator.UserValidator;
import lab.pojo.User;
import lab.service.UserService;
import lab.service.impl.UserService2Impl;

@Controller
@RequestMapping("/user")
public class UserController {

	@Autowired
	private UserService userService = null;

	@Autowired
	UserService2Impl userService2Impl;

	@RequestMapping("/print")
	@ResponseBody
	public User printUser(Long id, String userName, String note) {
		User user = new User();
		user.setId(id);
		user.setUserName(userName);
		user.setNote(note);
		UserValidator userValidator = (UserValidator) userService;
		if (userValidator.validate(user)) {
			userService.printUser(user);
//			userService.printUser(null);
		}
		return user;
	}

	@RequestMapping("/print2")
	@ResponseBody
	public User printUser2(Long id, String userName, String note) {
		User user = new User();
		user.setId(id);
		user.setUserName(userName);
		user.setNote(note);
		userService2Impl.printUser(user);
		return user;
	}
}
