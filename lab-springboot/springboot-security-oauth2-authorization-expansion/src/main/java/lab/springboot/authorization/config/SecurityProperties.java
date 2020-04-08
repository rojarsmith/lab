package lab.springboot.authorization.config;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

import lombok.Data;

@Data
@Configuration
@ConfigurationProperties("application.security.oauth")
public class SecurityProperties {
	// The path of login.
	private String loginProcessingUrl = "/authorization/form";
}
