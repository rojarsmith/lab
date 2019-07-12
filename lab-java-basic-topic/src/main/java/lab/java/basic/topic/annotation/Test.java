package lab.java.basic.topic.annotation;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

@Perform
@Check("hi")
@TestAnnotation(id=3, msg="hello annotation")
public class Test {
	@Check(value="hi")
	public int a;
	
	@Perform
	public void testMethod() {}
	
	@SuppressWarnings("deprecation")
	public void test1() {
	}
}
