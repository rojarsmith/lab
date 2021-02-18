package lab.springboot.jparepository.jparepository;

import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import lab.springboot.jparepository.entity.Person;

@Repository
public interface PersonRepository extends JpaRepository<Person, Long>{
	Optional<Person> findByName(String name);
	
	@Query("SELECT d FROM Person d WHERE d.name LIKE %?1%")
	Optional<Person> findByNamePart(String part);
}
