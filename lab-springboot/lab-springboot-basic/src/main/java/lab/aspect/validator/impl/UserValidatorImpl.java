package lab.aspect.validator.impl;

import org.springframework.stereotype.Service;

import lab.aspect.validator.UserValidator;
import lab.pojo.User;

@Service
public class UserValidatorImpl implements UserValidator {
	@Override
	public boolean validate(User user) {
		System.out.println(UserValidator.class.getSimpleName());
		return user != null;
	}
}
