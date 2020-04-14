package lab.springboot.authorization.config;

import org.springframework.boot.autoconfigure.security.oauth2.resource.ResourceServerProperties;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableResourceServer;
import org.springframework.security.oauth2.config.annotation.web.configuration.ResourceServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configurers.ResourceServerSecurityConfigurer;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;

@Configuration
@RequiredArgsConstructor
@EnableResourceServer
public class Oauth2ResourceServerConfig extends ResourceServerConfigurerAdapter {

    /**
     * Config file.
     */
	private @NonNull ResourceServerProperties resourceServerProperties;
	
	@Override
	public void configure(ResourceServerSecurityConfigurer resources) throws Exception {
		// Resource server id
		resources.resourceId(resourceServerProperties.getResourceId());
	}
}
