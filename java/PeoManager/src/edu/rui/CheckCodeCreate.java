package edu.rui;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Random;

public class CheckCodeCreate {

    private int width = 120;    // 定义图片的width
    private int height = 34;    // 定义图片的height
    private int codeCount = 4;    // 定义图片上显示验证码的个数
    private final int fontHeight = 27;   //图片字体大小
    private BufferedImage codeImage = null;   //图片
    private String codeString = null;    //图片包含字母
    private final char[] codeSequence = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    public CheckCodeCreate() {
        this.createCode();
    }

    public CheckCodeCreate(int width, int height) {
        this.width = width;
        this.height = height;
        this.createCode();
    }

    public CheckCodeCreate(int width, int height, int codeCount) {
        this.width = width;
        this.height = height;
        this.codeCount = codeCount;
        this.createCode();
    }

    private void createCode() {
        Random random = new Random();

        BufferedImage buffImg = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics gd = buffImg.getGraphics();
        gd.setColor(Color.WHITE);
        gd.fillRect(0, 0, width, height);

        // 设置字体
        Font font = new Font("Fixedsys", Font.BOLD, fontHeight);
        gd.setFont(font);

        // 画边框。
        gd.setColor(Color.BLACK);
        gd.drawRect(0, 0, width - 1, height - 1);


        StringBuffer randomCode = new StringBuffer();
        // 随机产生codeCount数字的验证码。
        for (int i = 0; i < codeCount; i++) {
            // 得到随机产生的验证码数字。
            String code = String.valueOf(codeSequence[random.nextInt(this.codeSequence.length)]);
            // 用随机产生的颜色将验证码绘制到图像中。
            gd.setColor(this.randomColor());
            gd.drawString(code, (i + 1) * (this.width / (this.codeCount + 2)), fontHeight - 2);
            // 将产生的四个随机数组合在一起。
            randomCode.append(code);
        }

        // 随机产生50条干扰线，使图象中的认证码不易被其它程序探测到。
        for (int i = 0; i < 50; i++) {
            int x1 = random.nextInt(width);
            int y1 = random.nextInt(height);
            int x2 = random.nextInt(width / 4);
            int y2 = random.nextInt(width / 4);
            gd.setColor(this.randomColor());
            gd.drawLine(x1, y1, x1 + x2, y1 + y2);
        }

        this.codeString = randomCode.toString();
        this.codeImage = buffImg;
    }

    // 产生随机的颜色分量来构造颜色值，这样输出的每位数字的颜色值都将不同。
    private Color randomColor() {
        Random random = new Random();
        int red = 0, green = 0, blue = 0;
        red = random.nextInt(255);
        green = random.nextInt(255);
        blue = random.nextInt(255);
        return new Color(red, green, blue);
    }

    public void outputCodeImage(String path) throws IOException {
        FileOutputStream output = new FileOutputStream(path);
        this.outputCodeImage(output);
    }

    public void outputCodeImage(OutputStream output) throws IOException {
        ImageIO.write(this.codeImage, "png", output);
    }

    public String getCodeString() {
        return this.codeString;
    }

}
