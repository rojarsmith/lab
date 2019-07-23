package lab.pojo;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.PropertySource;
import org.springframework.stereotype.Component;

@Component
//@ConfigurationProperties("database")
@PropertySource("classpath:my.properties")
public class DataBaseProperties {
	public String getDriverName() {
		return driverName;
	}

	public String getUrl() {
		return url;
	}

	public String getUsername() {
		return username;
	}

	public String getPassword() {
		return password;
	}

	@Value("${spring.mvc.view.suffix}")
	private String driverName = null;
	
	@Value("${database.url}")
	private String url = null;
	
	private String username = null;
	
	private String password = null;
	
	@Value("${database.username}")
	public void setDriverName(String driverName) {
		System.out.println(driverName);
		this.driverName = driverName;
	}
	
	@Value("${database.password}")
	public void setUrl(String url) {
		System.out.println(url);
		this.url = url;
	}
	
	@Value("${database.username}")
	public void setUsername(String username) {
		System.out.println(username);
		this.url = username;
	}
	
	@Value("${database.password}")
	public void setPassword(String password) {
		System.out.println(password);
		this.url = password;
	}
}
