package cn.edu.swu.ws;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class DownloadThread implements Runnable {

	private String url;
	private File file;
	
	public DownloadThread(String url, File file) {
		this.url = url;
		this.file = file;
	}
	
	@Override
	public void run() {
		try {
			byte[] imgData = HttpTools.downloadImage(this.url);
			this.saveImage(imgData, this.file);
			System.out.println("download image : " + this.file.getAbsolutePath());
		} catch(IOException ex) {
			ex.printStackTrace();
		}
	}
	
	private void saveImage(byte[] data, File file) throws IOException {
		try( FileOutputStream out = new FileOutputStream(file) ){
			out.write(data);
		}
	}

}
