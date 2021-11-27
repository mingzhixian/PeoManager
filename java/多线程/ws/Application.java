package cn.edu.swu.ws;

import java.io.IOException;

public class Application {
	
	public static void main(String[] args) {
		Application app = new Application();
		app.run();
	}

	// time usage : 1763
	// time usage : 1804

	public void run() {
		long start = System.currentTimeMillis();
		BingDownloader downloader = new BingDownloader();
		downloader.setStorePath("C:\\workspace\\bing");
		
		try {
			downloader.download();
		} catch (IOException e) {
			e.printStackTrace();
		}
		long end = System.currentTimeMillis();
		System.out.println("time usage : " + (end - start));
	}
	
}
