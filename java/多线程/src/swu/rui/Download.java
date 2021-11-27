package swu.rui;

import javax.imageio.stream.FileImageOutputStream;
import java.io.File;
import java.io.IOException;

public class Download implements Runnable {
    private String url;
    private String filePath;

    public Download(String url, String filePath) {
        this.url = url;
        this.filePath = filePath;
    }

    public void run() {
        long start = System.currentTimeMillis();
        try {
            byte[] data = Httptool.downloadImage(url);
            this.saveImage(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
        long end = System.currentTimeMillis();
        System.out.println("时间: " + (end - start) + "  保存" + url);
    }

    private void saveImage(byte[] data) throws IOException {
        try (FileImageOutputStream jpg = new FileImageOutputStream(new File(filePath));) {
            jpg.write(data, 0, data.length);
        }
    }
}
