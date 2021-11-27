package cn.edu.swu.ws;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class HttpTools {
	
	public static byte[] downloadImage(String strUrl) throws IOException {
		URL url = new URL(strUrl);
		HttpURLConnection connection = (HttpURLConnection) url.openConnection();		
		try (InputStream inputStream = connection.getInputStream()) {			
			int length = connection.getContentLength();
			byte[] data = new byte[length];
			int offset = 0;
			int size = 0;			
			while ((size = inputStream.read(data, offset, length - offset)) != -1) {
				offset += size;
			}			
			return data;			
		} 
	}
	
}
