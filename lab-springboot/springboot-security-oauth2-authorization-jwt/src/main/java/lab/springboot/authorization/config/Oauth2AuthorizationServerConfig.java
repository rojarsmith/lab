package lab.springboot.authorization.config;

import java.time.Duration;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.ClassPathResource;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.oauth2.common.DefaultOAuth2AccessToken;
import org.springframework.security.oauth2.config.annotation.builders.InMemoryClientDetailsServiceBuilder;
import org.springframework.security.oauth2.config.annotation.configurers.ClientDetailsServiceConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerSecurityConfigurer;
import org.springframework.security.oauth2.provider.token.TokenEnhancer;
import org.springframework.security.oauth2.provider.token.TokenEnhancerChain;
import org.springframework.security.oauth2.provider.token.TokenStore;
import org.springframework.security.oauth2.provider.token.store.JwtAccessTokenConverter;
import org.springframework.security.oauth2.provider.token.store.JwtTokenStore;
import org.springframework.security.oauth2.provider.token.store.KeyStoreKeyFactory;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;

// Test URL:
// localhost:8000/oauth/authorize?response_type=code&client_id=oauth2&redirect_uri=http://example.com&scope=all

@Configuration
@RequiredArgsConstructor
@EnableAuthorizationServer
public class Oauth2AuthorizationServerConfig extends AuthorizationServerConfigurerAdapter {
	@Autowired
	private @NonNull AuthenticationManager authenticationManager;

	@Override
	public void configure(ClientDetailsServiceConfigurer clients) throws Exception {
		InMemoryClientDetailsServiceBuilder builder = clients.inMemory();
		builder
		// 構建一個 id 為 oauth2 的客戶端
        .withClient("oauth2")
        // 設置她的密鑰，加密後的
        .secret("$2a$10$K74U3q/EBh/cO2UmFsxC7.ffxbhjH/Gdw0lNh02ANeoVole73gSLS")
        // 設置允許訪問的資源 id
        .resourceIds("oauth2")
        // 授權的類型
        .authorizedGrantTypes("password", "authorization_code", "refresh_token")
        // 可以授權的角色
        .authorities("ROLE_ADMIN", "ROLE_USER")
        // 授權的範圍
        .scopes("all")
        // token 有效期
        .accessTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
        // 刷新 token 的有效期
        .refreshTokenValiditySeconds(Math.toIntExact(Duration.ofHours(1).getSeconds()))
        // 授權碼模式的重定向地址
        .redirectUris("http://example.com");
	}

	@Override
	public void configure(AuthorizationServerEndpointsConfigurer endpoints) {
//	    endpoints.authenticationManager(this.authenticationManager)
//	        .tokenStore(tokenStore())
//	        .accessTokenConverter(jwtAccessTokenConverter());
		
		TokenEnhancerChain tokenEnhancerChain = new TokenEnhancerChain();
		tokenEnhancerChain.setTokenEnhancers(
		    Arrays.asList(tokenEnhancer(), jwtAccessTokenConverter()));

		endpoints.tokenStore(tokenStore())
		    .tokenEnhancer(tokenEnhancerChain)
		    .authenticationManager(authenticationManager);
	}

    /**
     * Token Enhancer
     *
     * @return TokenEnhancer
     */
    @Bean
    public TokenEnhancer tokenEnhancer() {
        return (accessToken, authentication) -> {
            Map<String, Object> additionalInfo = new HashMap<>(1);
            additionalInfo.put("organization", authentication.getName());
            ((DefaultOAuth2AccessToken) accessToken).setAdditionalInformation(additionalInfo);
            return accessToken;
        };
    }	
	
	/**
	 * 1. Token converter with asymmetric encryption
	 *
	 * @return JwtAccessTokenConverter
	 */
	@Bean
	public JwtAccessTokenConverter jwtAccessTokenConverter() {
	    JwtAccessTokenConverter converter = new JwtAccessTokenConverter();
	    // Symmetric Encryption.
	    //converter.setSigningKey("oauth2");
	    // Asymmetric Encryption.
	    KeyStoreKeyFactory keyStoreKeyFactory = new KeyStoreKeyFactory(
	    		new ClassPathResource("oauth2.jks"), "oauth2".toCharArray());
	    converter.setKeyPair(keyStoreKeyFactory.getKeyPair("oauth2"));
	    return converter;
	}

	/**
	 * 2. Implement of token store
	 *
	 * @return JwtTokenStore
	 */
	@Bean
	public TokenStore tokenStore() {
	    return new JwtTokenStore(jwtAccessTokenConverter());
	}

	@Override
	public void configure(AuthorizationServerSecurityConfigurer security) {
	    security
	        .checkTokenAccess("isAuthenticated()")
	        // Can access public key.
	        .tokenKeyAccess("isAuthenticated()");
	}

}
