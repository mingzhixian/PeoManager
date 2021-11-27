package edu.swu.rui;

import java.io.IOException;
import java.util.List;

public class Application {
    public static void main(String[] args) throws IOException {
        // 初始化一个应用程序对象
        Application application = new Application();

        // 通过 run 方法启动运行的逻辑
        application.run();
    }

    public void run() throws IOException {
        // 定义数据源
        edu.swu.rui.MoviesDataSource webSource = new WebMoviesDataSource( "http://101.35.99.213:88/");
        edu.swu.rui.MoviesDataSource fileSource = new FileMoviesDataSource("/home/kic/文档/code/java/webapp/source/");
        // 下载并保存数据
        {
            List<Movies> getmovies = webSource.getNewMovies();
            for(int i=0; i<getmovies.size(); i++) {
                Movies movies = getmovies.get(i);
                System.out.println(movies.toString());
                fileSource.saveNewMovies(movies);
                System.out.printf("保存第 %s 个电影%n", i + 1);
            }
        }

        // 对保存的数据做增、删，改，查的操作
        System.out.println("按排名查找（12）");
        this.log(fileSource.findMoviesByCode("12"));
        System.out.println("按名字查找（教父）");
        this.log(fileSource.findMoviesByName("教父"));
        System.out.println("获取所有");
        //this.log(fileSource.getNewMovies());
        System.out.println("按评分查找（7.3-8.4）");
        this.log(fileSource.findMoviesByScore(7.3f, 7.7f));
        System.out.println("按排名删除（12）");
        List<Movies> movies=fileSource.findMoviesByCode("12");
        fileSource.deleteMoviesByCode("12");
        if (fileSource.findMoviesByCode("12")==null)
        {
            System.out.println("已经删除排名为12的文件。");
        }
        System.out.println("重新添加排名为12的文件");
        fileSource.saveNewMovies(movies.get(0));
        this.log(fileSource.findMoviesByCode("12"));
    }


    /**
     * 打印图书列表的日志输出类
     * @param movies
     */
    public void log(List<Movies> movies) {
        if (movies==null)
        {
            System.out.println("列表空");
        }
        else
        {
            for(Movies Movies : movies) {
                System.out.println(Movies.toString());
            }
        }
    }

    /**
     * 打印图书的日志输出类
     * @param movies
     */
    public void log(Movies movies) {
        System.out.println(movies.toString());
    }


    class MoviesDataSource {
    }
}
