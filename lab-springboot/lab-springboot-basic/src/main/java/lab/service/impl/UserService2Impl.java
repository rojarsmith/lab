package lab.service.impl;

import org.springframework.stereotype.Service;

import lab.pojo.User;

/**
 * @author Rojar Smith
 *
 * @date 2021-07-30
 */
@Service
public class UserService2Impl {
	
	public void printUser(User user) {
		if (user == null) {
			System.out.println("Check user is null...");
			throw new RuntimeException("Check user is null...");
		}
		System.out.println("ID:" + user.getId());
		System.out.println("User Name:" + user.getUserName());
		System.out.println("Note:" + user.getNote());
	}
	
}
