package lab.java.basic.topic;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

import lab.java.basic.topic.annotation.*;

public class Entry {

	public static void main(String[] args) {
		SuperMan man1 = new SuperMan();
		man1.hashCode();

		Test test = new Test();
		test.hashCode();

		boolean hasAnnotation = Test.class.isAnnotationPresent(TestAnnotation.class);

		if (hasAnnotation) {
			TestAnnotation testAnnotation = Test.class.getAnnotation(TestAnnotation.class);

			System.out.println("id:" + testAnnotation.id());
			System.out.println("msg:" + testAnnotation.msg());
		}

		try {
			Field a = Test.class.getDeclaredField("a");
			a.setAccessible(true);
			Check check = a.getAnnotation(Check.class);

			if (check != null) {
				System.out.println("check value:" + check.value());
			}

			Method testMethod = Test.class.getDeclaredMethod("testMethod");

			if (testMethod != null) {
				Annotation[] ans = testMethod.getAnnotations();
				for (int i = 0; i < ans.length; i++) {
					System.out.println("method testMethod annotation:" + ans[i].annotationType().getSimpleName());
				}
			}

		} catch (NoSuchFieldException e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
		} catch (SecurityException e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
		}

		return;
	}

}
