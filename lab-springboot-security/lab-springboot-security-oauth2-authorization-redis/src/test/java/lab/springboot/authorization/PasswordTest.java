package lab.springboot.authorization;

import org.junit.jupiter.api.Test;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

/**
 * Grab encrypted password
 *
 * @author <a href="https://echocow.cn">EchoCow</a>
 * @date 19-7-13 下午4:36
 */
public class PasswordTest {

    @Test
    public void password() {
        System.out.println(new BCryptPasswordEncoder().encode("oauth2"));
        System.out.println(new BCryptPasswordEncoder().encode("test"));
    }
}
