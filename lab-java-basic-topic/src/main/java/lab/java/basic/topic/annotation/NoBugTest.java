package lab.java.basic.topic.annotation;

import java.lang.reflect.Method;

public class NoBugTest {
	public static void main(String[] args) {
		NoBug testobj = new NoBug();
		
		Class clazz = testobj.getClass();
		
		Method[] method = clazz.getDeclaredMethods();
		// Log for test
		StringBuilder log = new StringBuilder();
		int errornum=0;
		
		for( Method m: method) {
			if(m.isAnnotationPresent(NoBugAnnotation.class)) {
				try {
					m.setAccessible(true);
					m.invoke(testobj, null);					
				}catch(Exception e) {
					errornum++;
					log.append(m.getName());
					log.append(" ");
					log.append("hass error:");
					log.append("\n\r  caused by ");
					log.append(e.getCause().getClass().getSimpleName());
					log.append("\n\r");
					log.append(e.getCause().getMessage());
					log.append("\n\r");					
				}
			}
		}
		
		
		log.append(clazz.getSimpleName());
		log.append(" has ");
		log.append(errornum);
		log.append(" error.");
		
		System.out.println(log.toString());
	}
}
