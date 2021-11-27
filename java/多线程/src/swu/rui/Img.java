package swu.rui;

public class Img {
    private String weburls;
    private String fileurls;

    public Img(String fileurls, String weburls) {
        this.fileurls = fileurls;
        this.weburls = weburls;
    }

    public void setWeburls(String fileurls) {
        this.fileurls = fileurls;
    }

    public void setFileurls(String weburls) {
        this.weburls = weburls;
    }

    public String getWeburls() {
        return weburls;
    }

    public String getFileurls() {
        return fileurls;
    }

    @Override
    public String toString() {
        return "Img{" +
                "weburls='" + weburls + '\'' +
                ", fileurls='" + fileurls + '\'' +
                '}';
    }
}
