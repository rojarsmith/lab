package lab.springboot.authorization.config;

import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;

@Configuration
@RequiredArgsConstructor
@EnableAuthorizationServer
public class Oauth2AuthorizationServerConfig extends AuthorizationServerConfigurerAdapter {
	private final @NonNull AuthenticationManager authenticationManager = null;
	
    @Override
    public void configure(AuthorizationServerEndpointsConfigurer endpoints) throws Exception {
        endpoints.authenticationManager(this.authenticationManager);
    }
}
