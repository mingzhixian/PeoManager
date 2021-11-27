package cn.edu.swu.ws;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class BingDownloader {
	
	private final static String IMAGES_FILE = "resources/images.txt";
	
	private String storePath = null; 
	
	public void download() throws IOException {		
		List<String> urls = this.getImageUrls();
		for (int i=0; i< urls.size(); i++) {
			DownloadThread task = new DownloadThread(
				urls.get(i),  
				Paths.get(this.getStorePath(), i + ".jpg").toFile()
			);		
			(new Thread(task)).start();
		}
	}
	
	private List<String> getImageUrls() throws IOException {
		List<String> urls = new ArrayList<String>();
		InputStream inputStream = this.getClass().getClassLoader().getResourceAsStream(IMAGES_FILE);
		InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
		BufferedReader reader = new BufferedReader(inputStreamReader);
		String line = null;
		
		while((line = reader.readLine()) != null) {
			urls.add(line);
		}
		
		return urls;
	}
	
	public void setStorePath(String path) {
		this.storePath = path;		
	}
	
	public String getStorePath() {
		return this.storePath;
	}

}
