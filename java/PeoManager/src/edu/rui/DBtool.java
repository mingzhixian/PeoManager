package edu.rui;

import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;

import javax.servlet.annotation.WebServlet;
import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "DBtool", value = "/web/DBtool")
public class DBtool {
    static DataSource ds = null;

    private static void setDataSource() throws ClassNotFoundException {
        Class.forName("org.sqlite.JDBC");
        HikariConfig config = new HikariConfig();
        config.setJdbcUrl("jdbc:sqlite:/home/kic/DB/PeoManager.db");
        config.addDataSourceProperty("connectionTimeout", "1000"); // 连接超时：1秒
        config.addDataSourceProperty("idleTimeout", "5*60000"); // 空闲超时：5*1分钟
        config.addDataSourceProperty("maximumPoolSize", "10"); // 最大连接数：10
        ds = new HikariDataSource(config);
    }

    private static Connection getconnection() throws ClassNotFoundException, SQLException {
        if (ds == null) {
            setDataSource();
        }
        Class.forName("org.sqlite.JDBC");
        return ds.getConnection();
    }

    public static void excute(String str) throws SQLException, ClassNotFoundException {
        try (Connection connection = getconnection()) {
            try (Statement statement = connection.createStatement()) {
                statement.execute(str);
            }
        }
    }

    public static List<Peo> all(String sql) throws SQLException {
        List<Peo> peos = new ArrayList<>();
        try (Connection connection = getconnection()) {
            try (Statement statement = connection.createStatement()) {
                ResultSet one = statement.executeQuery(sql);
                while (one.next()) {
                    Peo peo = new Peo(one.getString("name"), one.getString("id"));
                    peos.add(peo);
                }
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return peos;
    }

    public static Count login(String sql) throws SQLException {
        Count count = null;
        try (Connection connection = getconnection()) {
            try (Statement statement = connection.createStatement()) {
                ResultSet one = statement.executeQuery(sql);
                while (one.next()) {
                    count = new Count(one.getString("name"), one.getString("password"), one.getInt("admin"));
                }
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return count;
    }

    public static boolean ishave(String id) throws SQLException {
        String findstr = "SELECT * FROM peo WHERE id ='" + id + "';";
        List<Peo> peos = all(findstr);
        return !peos.isEmpty();
    }
}
