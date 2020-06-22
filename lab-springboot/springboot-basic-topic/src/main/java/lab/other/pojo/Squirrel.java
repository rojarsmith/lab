package lab.other.pojo;

import lab.pojo.definition.Animal;

public class Squirrel implements Animal{
	@Override
	public void use() {
		System.out.println("Squirrel可以採集松果");
	}
}
