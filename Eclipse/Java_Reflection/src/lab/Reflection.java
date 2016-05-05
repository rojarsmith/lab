package lab;

import java.lang.reflect.Constructor;
import java.util.HashMap;

public class Reflection {

	private final static String PERSIONNAMESPACE_STRING = "lab.";
	private static HashMap<Integer, Persion> persionMap;

	static {
		persionMap = new HashMap<Integer, Persion>();
		PersionData p1 = new PersionData("Tom", 10);
		PersionData p2 = new PersionData("Roger", 20);
		persionMap.put(1000, p1);
		persionMap.put(2000, p2);
	}

	public static void main(String[] args) {
		Persion p1 = new Tom("Tom", 10);
		Persion p2 = new Roger("Roger", 20);
		p1.sayHello();
		p2.sayHello();

		for (Integer k : persionMap.keySet()) {

			Class<?> c = null;
			try {
				// c = Class.forName("lab.Tom");
				c = Class.forName(PERSIONNAMESPACE_STRING
						+ persionMap.get(k).getName());

				/* (Begin)=============== 生成物件 ===============(Begin) */

				// 指定Constructor所使用的參數型態
				Class<?>[] oParam = new Class<?>[2];
				oParam[0] = String.class;
				oParam[1] = Integer.TYPE;

				// 產生Constructor
				Constructor<?> constructor = c.getConstructor(oParam);

				// 指定參數的內容
				Object[] paramObjs = new Object[2];
				paramObjs[0] = persionMap.get(k).getName();
				paramObjs[1] = persionMap.get(k).getAge();

				// 透過Constructor產生物件
				Persion p3 = (Persion) constructor.newInstance(paramObjs);

				/* (End)=============== 生成物件 ===============(End) */

				p3.sayHello();			
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

}
