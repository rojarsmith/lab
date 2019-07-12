package lab.java.basic.topic.annotation;

import java.lang.annotation.Repeatable;

@Repeatable(Persons.class)
@interface Person {
	String role() default "";
}
