package swu.rui;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Getimgs {
    private String urls;

    public Getimgs(String urls) {
        this.urls = urls;
    }

    public String getUrls() {
        return urls;
    }

    public void setUrls(String urls) {
        this.urls = urls;
    }

    public List<Img> New() throws IOException {
        List<Img> imgs = new ArrayList<>();
        String html = Httptool.getHtml(urls);
        String[] lines = html.split("\n");
        for (String line : lines) {
            Img img = this.analyze(line);
            if (img != null) {
                imgs.add(img);
            }
        }
        return imgs;
    }

    public Img analyze(String line) {        //解析
        if (line.contains("data-original='//") && !line.contains("' alt='") && !line.contains(".png'")) {
            line = line.substring(line.indexOf("data-original='//") + "data-original='//".length());
            line = line.substring(0, line.indexOf("'"));
            String filePath = this.path();
            Img img = new Img(filePath, "https://" + line);
            return img;
        }
        return null;
    }

    public String path() {   //设置本地保存地址
        String filePath = "/home/kic/文档/code/java/多线程/pic/" + UUID.randomUUID() + ".jpg";
        File file = new File(filePath);
        file.getParentFile().mkdirs();
        return filePath;
    }

}
