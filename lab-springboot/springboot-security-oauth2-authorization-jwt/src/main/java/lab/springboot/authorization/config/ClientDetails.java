package lab.springboot.authorization.config;

import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.oauth2.provider.client.BaseClientDetails;

import lombok.Data;

@Data
@Configuration
@ConfigurationProperties("application.security.oauth")
public class ClientDetails {
	private List<BaseClientDetails> client;
}
