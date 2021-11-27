package swu.rui;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class appmain {
    public static void main(String[] args) throws IOException {
        appmain app = new appmain();
        app.run();
    }

    public void run() throws IOException {
        long start = System.currentTimeMillis();
        List<Img> imgs = new ArrayList<>();
        Getimgs get = new Getimgs("https://sc.chinaz.com/ppt/");
        imgs = get.New();
        for (Img img : imgs) {
            Download download = new Download(img.getWeburls(), img.getFileurls());
            download.run();     //单线程
//            (new Thread(download)).start();   //多线程
        }
        long end = System.currentTimeMillis();
        System.out.println("主程序时间 : " + (end - start));
    }
}
