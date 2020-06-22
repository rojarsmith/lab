package lab;

import lab.interceptor.impl.MyInterceptor;
import lab.proxy.ProxyBean;
import lab.service.HelloService;
import lab.service.impl.HelloServiceImpl;

public class AOP {
	public static void main(String[] args) {
		HelloService helloService = new HelloServiceImpl();
		HelloService proxy = (HelloService)ProxyBean.getProxyBean(helloService, new MyInterceptor());
		proxy.sayHello("Rojar");
		
		
	}
}
