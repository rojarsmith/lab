package com.wearesoft.Java_Jna;

public class EntryPoint {

	public static void main(String[] args) {
		try {
			System.out.println("test func [add]");
			int r1 = Java_JnaPureCLibrary.instance.add(1, 2);
			System.out.println("result : " + r1);

			System.out.println("test func [get_order]");
			Java_JnaPureCLibrary.order.ByValue o1 = Java_JnaPureCLibrary.instance
					.get_order(3);
			Java_JnaPureCLibrary.order_item[] oi1 = (Java_JnaPureCLibrary.order_item[]) o1.order_items
					.toArray(o1.order_items_count);
			System.out.println("order_items_count : " + o1.order_items_count);
			for (int i = 0; i < o1.order_items_count; i++) {
				System.out.println("order_item[" + i + "]");
				System.out.println("order_count : " + oi1[i].order_count);
				System.out.println("name : " + oi1[i].order_item.name);
				System.out.println("weight : " + oi1[i].order_item.weight);
			}

			System.out.println("test func [get_order_return_point]");
			Java_JnaPureCLibrary.order.ByValue o2 = Java_JnaPureCLibrary.instance
					.get_order(2);
			Java_JnaPureCLibrary.order_item[] oi2 = (Java_JnaPureCLibrary.order_item[]) o2.order_items
					.toArray(o2.order_items_count);
			System.out.println("order_items_count : " + o2.order_items_count);
			for (int i = 0; i < o2.order_items_count; i++) {
				System.out.println("order_item[" + i + "]");
				System.out.println("order_count : " + oi2[i].order_count);
				System.out.println("name : " + oi2[i].order_item.name);
				System.out.println("weight : " + oi2[i].order_item.weight);
			}

			System.out.println("test func [change_order]");
			Java_JnaPureCLibrary.order.ByReference o3 = new Java_JnaPureCLibrary.order.ByReference();
			o3.order_items_count = 2;
			o3.order_items = new Java_JnaPureCLibrary.order_item.ByReference();
			Java_JnaPureCLibrary.order_item[] oi3 = (Java_JnaPureCLibrary.order_item[]) o3.order_items
					.toArray(o3.order_items_count);
			for (int i = 0; i < o3.order_items_count; i++) {
				oi3[i].writeField("order_count", i + 1);
				oi3[i].order_item.writeField("name", "order" + (i + 1));
				oi3[i].order_item.writeField("weight", (float) (i + 0.1));
			}
		
			System.out.println("order_items_count : " + o3.order_items_count);
			for (int i = 0; i < o3.order_items_count; i++) {
				System.out.println("order_item[" + i + "]");
				System.out.println("order_count : " + oi3[i].order_count);
				System.out.println("name : " + oi3[i].order_item.name);
				System.out.println("weight : " + oi3[i].order_item.weight);
			}

			Java_JnaPureCLibrary.order.ByValue o4 = Java_JnaPureCLibrary.instance
					.change_order(o3, (float) 0.9);
			System.out.println("result==========");
			Java_JnaPureCLibrary.order_item[] oi4 = (Java_JnaPureCLibrary.order_item[]) o4.order_items
					.toArray(o4.order_items_count);
			System.out.println("order_items_count : " + o4.order_items_count);
			for (int i = 0; i < o4.order_items_count; i++) {
				System.out.println("order_item[" + i + "]");
				System.out.println("order_count : " + oi4[i].order_count);
				System.out.println("name : " + oi4[i].order_item.name);
				System.out.println("weight : " + oi4[i].order_item.weight);
			}

		} catch (Exception e) {
			System.out.println(e.toString() + e.getMessage());
			return;
		}

		return;
	}
}