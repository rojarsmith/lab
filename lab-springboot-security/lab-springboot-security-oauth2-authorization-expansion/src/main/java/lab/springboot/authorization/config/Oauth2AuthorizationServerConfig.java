package lab.springboot.authorization.config;

import java.time.Duration;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.oauth2.config.annotation.builders.InMemoryClientDetailsServiceBuilder;
import org.springframework.security.oauth2.config.annotation.configurers.ClientDetailsServiceConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerSecurityConfigurer;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;

@Configuration
@RequiredArgsConstructor
@EnableAuthorizationServer
public class Oauth2AuthorizationServerConfig extends AuthorizationServerConfigurerAdapter {
	@Autowired
	private @NonNull AuthenticationManager authenticationManager;
	private final @NonNull UserDetailsService userDetailsService;

	@Override
	public void configure(ClientDetailsServiceConfigurer clients) throws Exception {
		InMemoryClientDetailsServiceBuilder builder = clients.inMemory();
		builder.withClient("oauth2").secret("$2a$10$K74U3q/EBh/cO2UmFsxC7.ffxbhjH/Gdw0lNh02ANeoVole73gSLS")
				.resourceIds("oauth2").authorizedGrantTypes("password", "authorization_code", "refresh_token")
				.authorities("ROLE_ADMIN", "ROLE_USER").scopes("all")
				.accessTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
				.refreshTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
				.redirectUris("http://example.com");
	}

	@Override
	public void configure(AuthorizationServerEndpointsConfigurer endpoints) throws Exception {
		endpoints.authenticationManager(this.authenticationManager)
		.userDetailsService(userDetailsService);
	}

	@Override
	public void configure(AuthorizationServerSecurityConfigurer security) {
		security.checkTokenAccess("isAuthenticated()");
	}
}
