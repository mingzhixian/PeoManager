package cn.edu.swu.ws;

import java.util.HashMap;
import java.util.Map;

public class Store {

	private Map<String, String> books = null;
	
	public Map<String, String> getBooks() {		
		if (this.books == null) {
			synchronized(this) {
				if (this.books == null ){
					this.books = new HashMap<String, String>();
				}				
			}
		}
		return this.books;
	} 
	
}
