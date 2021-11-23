package lab.springboot.dummy;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

import lombok.extern.slf4j.Slf4j;

@Component
@Slf4j
@Profile({ "default", "prod", "dev", "test" })
public class InitialApplication implements ApplicationRunner {

	@Value("${properties.name}")
	private String propertiesName;

	@Override
	public void run(ApplicationArguments args) throws Exception {
		log.info("[InitialApplication] " + Const.Name);
		log.info("[properties.name] " + propertiesName);
	}
}
