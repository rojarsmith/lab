package lab.springboot.jparepository.controller;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import lab.springboot.jparepository.entity.Person;
import lab.springboot.jparepository.jparepository.PersonRepository;

@RestController
@RequestMapping(value = {"/api"})
public class MainController {
	@Autowired
	private PersonRepository personRepository;
	
    @PostConstruct
    private void init() {
    	List<Person> persons = new ArrayList<>();
    	
        //Person person1 = new Person("Rojar", 35);
        Person person1 = new Person();
        person1.setName("Rojar");
        person1.setAge(35);
        //Person person2 = new Person("Peter", 20);
        Person person2 = new Person();
        person2.setName("Peter");
        person2.setAge(20);
        //Person person3 = new Person("Billy Jean", 25);
        Person person3 = new Person();
        person3.setName("Billy Jean");
        person3.setAge(25);
        //Person person4 = new Person("Denny", 28);
        Person person4 = new Person();
        person4.setName("Denny");
        person4.setAge(28);
        
        persons.add(person1);
        persons.add(person2);
        persons.add(person3);
        persons.add(person4);
        
        personRepository.saveAll(persons);
    }
    
    @GetMapping("/person/findById")
    public Person findById() {
    	Optional<Person> person = personRepository.findById(1L);
    	if(person.isEmpty()) {
    		return null;
    	}
    	
    	return person.get();
    }
    
    @GetMapping("/person/findByName")
    public Person findByName() {
    	Optional<Person> person = personRepository.findByName("Rojar");
    	if(person.isEmpty()) {
    		return null;
    	}
    	
    	return person.get();
    }
    
    @GetMapping("/person/findByNamePart")
    public Person findByNamePart() {
    	Optional<Person> person = personRepository.findByNamePart("Roj");
    	if(person.isEmpty()) {
    		return null;
    	}
    	
    	return person.get();
    }
    
    @GetMapping("/person/delete")
    public void crudRepository_delete() {
    	Person person2 = new Person();
    	person2.setId(2L);
        person2.setName("Peter");
        person2.setAge(20);
        personRepository.delete(person2);
    }
    
    @GetMapping("/person/count")
    public Long count() {   	
    	return personRepository.count();
    }
    
    @GetMapping("/person/findAllPageable")
    public Pageable findAllPageable() {
    	Pageable pageable = PageRequest.of(1, 2, Sort.by("id").descending());
    	Page<Person> page = personRepository.findAll(pageable);
    	
        System.out.println("Page count:" + page.getTotalPages());
        System.out.println("Total count:" + page.getTotalElements());
        System.out.println("Current page:" + (page.getNumber() + 1));
        System.out.println("Set of current page:" + page.getContent());
        System.out.println("Count of current page:" + page.getNumberOfElements());
        
        return pageable;
    }    
}
