package edu.swu.rui;

import javax.imageio.stream.FileImageOutputStream;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

// TODO: 实现 BookDataSource 中定义的所有接口函数
public class FileMoviesDataSource implements MoviesDataSource {

    // 用来存储图书的目录
    private String directory;

    // 格式化日期的类。把格式化的日期作为文件夹名称
    private SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

    public FileMoviesDataSource(String directory) {
        this.directory = directory;
    }

    public List<Movies> getNewMovies() throws IOException {
        List<Movies> movies =new ArrayList<>();
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + date + "/";
        File[] files = new File(filePath).listFiles();
        for(File file : files) {
            Movies Movies=new Movies();
            try {
                FileReader reader = new FileReader(file);
                BufferedReader buffer = new BufferedReader (reader);
                try {
                    Movies.setCode(buffer.readLine());
                    Movies.setName(buffer.readLine());
                    Movies.setScore(Float.parseFloat(buffer.readLine()));
                    Movies.setImageUrl(buffer.readLine());
                    Movies.setImageFile(buffer.readLine());
                    reader.close();
                    buffer.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            movies.add(Movies);
        }

        return movies;
    }

    public void saveNewMovies(Movies Movies) throws IOException {
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + date + "/" +Movies.getCode()+"-"+ Movies.getName() + ".txt";
        File file = new File(filePath);
        file.getParentFile().mkdirs();

        String imageFilePath = this.downloadImage(Movies);
        Movies.setImageFile(imageFilePath);

        FileWriter fileWriter = new FileWriter(file);
        fileWriter.write(Movies.getCode() + "\n");
        fileWriter.write(Movies.getName() + "\n");
        fileWriter.write(String.valueOf(Movies.getScore()) + "\n");
        fileWriter.write(Movies.getImageUrl() + "\n");
        fileWriter.write(Movies.getImageFile());
        fileWriter.close();
    }

    @Override
    public List<Movies> findMoviesByCode(String code){
        List<Movies> movies =new ArrayList<>();
        Movies Movies= new Movies();
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + date + "/";
        File[] files = new File(filePath).listFiles();
        for(File file : files) {
            if (file.getName().substring(0, file.getName().indexOf("-")).equals(code))
            {
                try {
                    FileReader reader = new FileReader(file);
                    BufferedReader buffer = new BufferedReader (reader);
                    try {
                        Movies.setCode(buffer.readLine());
                        Movies.setName(buffer.readLine());
                        Movies.setScore(Float.parseFloat(buffer.readLine()));
                        Movies.setImageUrl(buffer.readLine());
                        Movies.setImageFile(buffer.readLine());
                        reader.close();
                        buffer.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    movies.add(Movies);
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                }
                return movies;
            }
        }
        return null;
    }

    @Override
    public List<Movies> findMoviesByName(String name) {
        List<Movies> movies =new ArrayList<>();
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + date + "/";
        File[] files = new File(filePath).listFiles();
        for(File file : files) {
            if (file.getName().substring(file.getName().indexOf("-") + "-".length(), file.getName().indexOf(".txt")).equals(name)) {
                movies=findMoviesByCode(file.getName().substring(0, file.getName().indexOf("-")));
                return movies;
            }
        }
        return null;
    }

    public void deleteMoviesByCode(String code) {
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + date + "/";
        File[] files = new File(filePath).listFiles();
        for(File file : files) {
            if (file.getName().substring(0, file.getName().indexOf("-")).equals(code)) {
                    file.delete();
            }
        }
    }

    public List<Movies> findMoviesByScore(float minScore, float maxScore) {
        List<Movies> allmovies =new ArrayList<>();
        List<Movies> movies =new ArrayList<>();
        Movies Movies=new Movies();
        try {
            allmovies=getNewMovies();
            for (Movies Movie:allmovies)
            {
                if (minScore<Movie.getScore()&&Movie.getScore()<maxScore)
                {
                    movies.add(Movie);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return movies;
    }

    private String downloadImage(Movies Movies) {
        byte[] data = new byte[0];
        try {
            data = HttpTools.getImage(Movies.getImageUrl());
        } catch (IOException e) {
            e.printStackTrace();
        }
        String imageFilePath = this.generateImageFilePath(Movies);
        this.saveImage(data, imageFilePath);
        return imageFilePath;
    }

    private String generateImageFilePath(Movies Movies) {

        // TODO: 随机或者根据 Movies 类生成一个存储图片的文件路径
        String date = this.simpleDateFormat.format(new Date());
        String filePath = this.directory  + "pic/" +date+"/"+Movies.getCode()+".jpg";
        File file = new File(filePath);
        file.getParentFile().mkdirs();
        return filePath;
    }

    private void saveImage(byte[] data, String filePath){
        // TODO: 保存图片到指定的文件路径
        File file = new File(filePath);
        FileImageOutputStream jpg ;
        try {
            jpg = new FileImageOutputStream(file);
            jpg.write(data,0, data.length);
            jpg.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}




