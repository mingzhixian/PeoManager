package edu.swu.rui;

import java.io.IOException;
import java.net.MalformedURLException;
import java.util.List;

public interface MoviesDataSource {
    /**
     * 获取当前最新的电影列表
     */
    public List<Movies> getNewMovies() throws IOException;

    /**
     * 保存数据到数据源
     */
    public void saveNewMovies(Movies Movies) throws IOException;

    /**
     * 根据提供的编号获取详细信息
     */
    public List<Movies> findMoviesByCode(String code);

    /**
     * 根据提供的书名，查找返回符合条件的图书。
     * 例如：输入 “哲学”，可能返回所有书名中包含哲学的书
     */
    public List<Movies> findMoviesByName(String name);

    /**
     * 根据提供的编号删除一本数据的详细信息
     */
    public void deleteMoviesByCode(String code);

    /**
     * 查找给定分数区间的图书
     */
    public List<Movies> findMoviesByScore(float minScore, float maxScore);

}
