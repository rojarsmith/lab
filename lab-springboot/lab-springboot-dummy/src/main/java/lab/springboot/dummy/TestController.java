package lab.springboot.dummy;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/test")
public class TestController {
	@GetMapping("hello")
	@ResponseBody
	public ResponseEntity<?> sayHello() {
		return ResponseEntity.ok().body("hello " + Const.Name);
	}
}
