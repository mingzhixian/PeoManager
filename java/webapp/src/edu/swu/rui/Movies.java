package edu.swu.rui;

public class Movies {
    /**
     * 电影排名
     */
    private String code;

    /**
     * 电影名字
     */
    private String name;

    /**
     * 分数
     */
    private float score;

    /**
     * 图片的 URL 地址
     */
    private String imageUrl;

    /**
     * 保存图片的文件路径
     */
    private String imageFile;


    public void setCode(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setScore(float score) {
        this.score = score;
    }

    public float getScore() {
        return score;
    }

    public void setImageUrl(String imageUrl) {
        this.imageUrl = imageUrl;
    }

    public String getImageUrl() {
        return imageUrl;
    }

    public void setImageFile(String file) {
        this.imageFile = file;
    }

    public String getImageFile() {
        return this.imageFile;
    }

    public String toString() {
        return this.getCode() + ", " + this.getName() + ", " + this.getScore() + ", " + this.getImageUrl();
    }
}
