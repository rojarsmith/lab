package com.wearesoft.Java_Jna;

import java.util.ArrayList;
import java.util.List;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;

public interface Java_JnaPureCLibrary extends Library {

	Java_JnaPureCLibrary instance = (Java_JnaPureCLibrary) Native.loadLibrary(
			"Java_JnaPureCLibrary", Java_JnaPureCLibrary.class);

	public static class item extends Structure {
		public static class ByValue extends item implements Structure.ByValue {
		}

		public String name;
		public float weight;

		@Override
		protected List<String> getFieldOrder() {
			List<String> fields = new ArrayList<String>();
			fields.add("name");
			fields.add("weight");
			return fields;
		}
	}

	public static class order_item extends Structure {
		public static class ByReference extends order_item implements
				Structure.ByReference {
		}

		public int order_count;
		public item.ByValue order_item;

		@Override
		protected List<String> getFieldOrder() {
			List<String> fields = new ArrayList<String>();
			fields.add("order_count");
			fields.add("order_item");
			return fields;
		}
	}

	public static class order extends Structure {
		public static class ByValue extends order implements Structure.ByValue {
		}

		public static class ByReference extends order implements
				Structure.ByReference {
		}

		public int order_items_count;
		public order_item.ByReference order_items;

		@Override
		protected List<String> getFieldOrder() {
			List<String> fields = new ArrayList<String>();
			fields.add("order_items_count");
			fields.add("order_items");
			return fields;
		}
	}

	public int add(int input1, int input2);

	public order.ByValue get_order(int order_items_count);

	public order.ByValue get_order_return_point(int order_items_count);

	public order.ByValue change_order(order input, float new_weight);
}