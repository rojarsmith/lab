package lab.springboot.controller;

import java.security.Principal;

import org.springframework.http.HttpEntity;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ResourceController {
    /**
     * Get current login user
     *
     * @param principal current login user
     * @return 
     */
    @GetMapping("/resource")
    public HttpEntity<?> resource(Principal principal) {
        return ResponseEntity.ok(principal);
    }
}
