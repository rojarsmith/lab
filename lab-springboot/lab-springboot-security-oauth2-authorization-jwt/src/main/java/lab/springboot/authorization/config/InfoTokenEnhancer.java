package lab.springboot.authorization.config;

import java.util.HashMap;
import java.util.Map;

import org.springframework.security.oauth2.common.DefaultOAuth2AccessToken;
import org.springframework.security.oauth2.common.OAuth2AccessToken;
import org.springframework.security.oauth2.provider.OAuth2Authentication;
import org.springframework.security.oauth2.provider.token.TokenEnhancer;

//@Component
public class InfoTokenEnhancer implements TokenEnhancer{

	@Override
	public OAuth2AccessToken enhance(OAuth2AccessToken accessToken, OAuth2Authentication authentication) {
		// Create the customer information.
        Map<String, Object> additionalInfo = new HashMap<>(1);
        // The customer information.
        additionalInfo.put("organization", authentication.getName());
        // Inject the customer information.
        ((DefaultOAuth2AccessToken) accessToken).setAdditionalInformation(additionalInfo);
        
        return accessToken;
	}

}
