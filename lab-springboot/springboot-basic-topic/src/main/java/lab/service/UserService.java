package lab.service;

import org.springframework.stereotype.Service;

import lab.pojo.User;

@Service
public class UserService {
	public void UserService(User user) {
		System.out.println("ID:" + user.getId());
		System.out.println("User Name:" + user.getUserName());
		System.out.println("Note:" + user.getNote());
	}
}
