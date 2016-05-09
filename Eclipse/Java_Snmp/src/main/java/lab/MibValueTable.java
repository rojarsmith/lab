package lab;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Properties;

public class MibValueTable {
	String _pathMib = "mib.properties";
	Properties _properties;

	public MibValueTable() {
		_properties = new Properties();

		try {
			String userdir = System.getProperty("user.dir");
			Path base = Paths.get(userdir);
			Path pathMib = base.resolve("bin").resolve("mib.properties");
			_pathMib = pathMib.toString();
			System.out.println("OID Return Map=" + _pathMib);

			_properties.load(new FileInputStream(_pathMib));
		} catch (IOException e) {
			System.out.println("error of reading properties file.");
			e.printStackTrace();
		}
	}

	/**
	 * get value by oid.
	 * 
	 * @param oid
	 * @return
	 */
	public String getValueByOID(String oid) {
		return _properties.getProperty(oid);
	}

	public void setValueByOID(String oid, String value) {

		_properties.setProperty(oid, value);
		try {
			_properties.store(new FileOutputStream(_pathMib), _pathMib);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static void main(String[] args) {
		MibValueTable cfg = new MibValueTable();
		String oid = "1.3.6.1.2.1.1.8.0";
		System.out.println("---------" + cfg.getValueByOID(oid));

		cfg.setValueByOID(oid, "test");

		System.out.println("---------" + cfg.getValueByOID(oid));
	}
}
