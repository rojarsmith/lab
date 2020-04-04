package lab.springboot.authorization.config;

import java.time.Duration;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.core.authority.AuthorityUtils;
import org.springframework.security.oauth2.config.annotation.builders.ClientDetailsServiceBuilder;
import org.springframework.security.oauth2.config.annotation.builders.InMemoryClientDetailsServiceBuilder;
import org.springframework.security.oauth2.config.annotation.configurers.ClientDetailsServiceConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;
import org.springframework.security.oauth2.provider.client.BaseClientDetails;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;

@Configuration
@RequiredArgsConstructor
@EnableAuthorizationServer
public class Oauth2AuthorizationServerConfig extends AuthorizationServerConfigurerAdapter {
	@Autowired
	private @NonNull AuthenticationManager authenticationManager;

	private @NonNull ClientDetails clientDetails;

	@Override
	public void configure(ClientDetailsServiceConfigurer clients) throws Exception {
//		InMemoryClientDetailsServiceBuilder builder = clients.inMemory();
//		builder
//		// 構建一個 id 為 oauth2 的客戶端
//        .withClient("oauth2")
//        // 設置她的密鑰，加密後的
//        .secret("$2a$10$K74U3q/EBh/cO2UmFsxC7.ffxbhjH/Gdw0lNh02ANeoVole73gSLS")
//        // 設置允許訪問的資源 id
//        .resourceIds("oauth2")
//        // 授權的類型
//        .authorizedGrantTypes("password", "authorization_code", "refresh_token")
//        // 可以授權的角色
//        .authorities("ROLE_ADMIN", "ROLE_USER")
//        // 授權的範圍
//        .scopes("all")
//        // token 有效期
//        .accessTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
//        // 刷新 token 的有效期
//        .refreshTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
//        // 授權碼模式的重定向地址
//        .redirectUris("http://example.com");
//		
//        builder
//        .withClient("test")
//        .secret("$2a$10$45FQBOnTRERkvav.sNAroeJkEaFLZrLzRC2qrMVIdQnLKCTL8z/9q")
//        .resourceIds("test")
//        .authorizedGrantTypes("password", "authorization_code", "refresh_token")
//        .authorities("ROLE_ADMIN", "ROLE_USER")
//        .scopes("all")
//        .accessTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
//        .refreshTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
//        .redirectUris("http://example.com");

		configClient(clients);
	}

	private void configClient(ClientDetailsServiceConfigurer clients) throws Exception {
		InMemoryClientDetailsServiceBuilder builder = clients.inMemory();
		for (BaseClientDetails client : clientDetails.getClient()) {
			ClientDetailsServiceBuilder<InMemoryClientDetailsServiceBuilder>.ClientBuilder clientBuilder = builder
					.withClient(client.getClientId());
			clientBuilder.secret(client.getClientSecret()).resourceIds(client.getResourceIds().toArray(new String[0]))
					.authorizedGrantTypes(client.getAuthorizedGrantTypes().toArray(new String[0]))
					.authorities(AuthorityUtils.authorityListToSet(client.getAuthorities()).toArray(new String[0]))
					.scopes(client.getScope().toArray(new String[0]));
			if (client.getAutoApproveScopes() != null) {
				clientBuilder.autoApprove(client.getAutoApproveScopes().toArray(new String[0]));
			}
			if (client.getAccessTokenValiditySeconds() != null) {
				clientBuilder.accessTokenValiditySeconds(client.getAccessTokenValiditySeconds());
			}
			if (client.getRefreshTokenValiditySeconds() != null) {
				clientBuilder.refreshTokenValiditySeconds(client.getRefreshTokenValiditySeconds());
			}
			if (client.getRegisteredRedirectUri() != null) {
				clientBuilder.redirectUris(client.getRegisteredRedirectUri().toArray(new String[0]));
			}
		}
	}

	@Override
	public void configure(AuthorizationServerEndpointsConfigurer endpoints) throws Exception {
		endpoints.authenticationManager(this.authenticationManager);
	}
}
