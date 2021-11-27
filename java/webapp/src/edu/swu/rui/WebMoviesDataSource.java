package edu.swu.rui;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

// TODO: 将 MoviesDataSource 中定义的新增接口通过抛出异常的方式实现
public class WebMoviesDataSource implements MoviesDataSource{

    private String url = null;

    private  int overcode =0;

    public WebMoviesDataSource(String url) {
        this.setUrl(url);
    }

    public List<Movies> getNewMovies() throws IOException {
        List<Movies> movies = new ArrayList<>();
        String html = HttpTools.getHtml(this.getUrl(),"utf-8");
        String[] lines = html.split("\n");
        boolean start = false;
        String bulider=null;
        for(String line : lines) {
            if (line.contains("<tr class=")) {
                start = true;
            }
            if (start) {
                if (line.contains("target=\"_blank\"><img src=\"")||line.contains("<td class=\"rl_grade_IMDB\">")) {
                    bulider=bulider+line;
                };
                if (line.contains("</span></td>"))
                {
                    Movies Movies = this.parseMoviesFromLine(bulider);
                    movies.add(Movies);
                    bulider=null;
                    start = false;
                }
            }
        }

        return movies;
    }

    private Movies parseMoviesFromLine(String line) {
        String html = line.substring(line.indexOf("target=\"_blank\"><img src=\"./") + "target=\"_blank\"><img src=\"./".length());
        //获取图片地址
        String imgUrl = "http://101.35.99.213:88/" +html.substring(0, html.indexOf("\" alt=\""));
        //获取名字
        html = html.substring(html.indexOf("\" alt=\"") + "\" alt=\"".length());
        String name = html.substring(0, html.indexOf("\" onerror=\""));
        //获取电影排名
        overcode++;
        String code = String.valueOf(overcode);
        //获取电影分数
        html = html.substring(html.indexOf("</i><span>") + "</i><span>".length());
        String score = html.substring(0, html.indexOf("</span></td>"));

        Movies Movies = new Movies();
        Movies.setCode(code);
        Movies.setName(name);
        Movies.setScore(Float.parseFloat(score));
        Movies.setImageUrl(imgUrl);
        return Movies;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public String getUrl() {
        return this.url;
    }

    @Override
    public List<Movies> findMoviesByName(String name) {
        throw new java.lang.UnsupportedOperationException("不能查找。");
    }
    public void saveNewMovies(Movies Movies) {
        throw new java.lang.UnsupportedOperationException("不能保存");
    }
    public List<Movies> findMoviesByCode(String code)
    {
        throw new java.lang.UnsupportedOperationException("不能查找.");
    }

    @Override
    public List<Movies> findMoviesByScore(float minScore, float maxScore) {
        throw new java.lang.UnsupportedOperationException("不能查找。");
    }

    @Override
    public void deleteMoviesByCode(String code) {
        throw new java.lang.UnsupportedOperationException("不能删除。");
    }
}
