package lab.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.ComponentScan.Filter;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.FilterType;
import org.springframework.stereotype.Service;

import lab.pojo.User;

@Configuration
@ComponentScan(
		basePackages = "lab.*",
		excludeFilters = {@Filter(classes = {Service.class})},
		lazyInit = true
		)
public class AppConfig {
//	@Bean(name = "user")
//	public User initUser() {
//		User user = new User();
//		user.setId(1L);
//		user.setUserName("user_name_1");
//		user.setNote("note_1");
//		return user;
//	}
}
