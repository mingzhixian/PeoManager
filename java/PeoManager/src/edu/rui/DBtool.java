package edu.rui;

import com.ibatis.common.jdbc.ScriptRunner;
import com.ibatis.common.resources.Resources;
import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;

import javax.sql.DataSource;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DBtool {
    static DataSource ds = null;
    private static int IsFrist = 0;
    static String DbUrl = "jdbc:sqlite:/home/kic/DB/PeoManager.db";

    private static void setDataSource() throws ClassNotFoundException {
        Class.forName("org.sqlite.JDBC");
        HikariConfig config = new HikariConfig();
        config.setJdbcUrl(DbUrl);
        config.addDataSourceProperty("connectionTimeout", "1000"); // 连接超时：1秒
        config.addDataSourceProperty("idleTimeout", "5*60000"); // 空闲超时：5*1分钟
        config.addDataSourceProperty("maximumPoolSize", "10"); // 最大连接数：10
        ds = new HikariDataSource(config);
    }

    private static Connection getconnection() throws ClassNotFoundException, SQLException, IOException {
        if (ds == null) {
            setDataSource();
        }
        Class.forName("org.sqlite.JDBC");
        //初次运行判断数据库是否初始化
        if (IsFrist == 0) {
            IsFrist = 1;
            Connection connection = ds.getConnection();
            List<String> tables = getTables(connection);
            if (!tables.toString().contains("count")) {
                SqlInit(connection);
            }
            return connection;
        } else {
            return ds.getConnection();
        }
    }

    public static void excute(String str) throws SQLException, ClassNotFoundException, IOException {
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
        } catch (ClassNotFoundException | IOException e) {
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
        } catch (ClassNotFoundException | IOException e) {
            e.printStackTrace();
        }
        return count;
    }

    public static boolean ishave(String id) throws SQLException {
        String findstr = "SELECT * FROM peo WHERE id ='" + id + "';";
        List<Peo> peos = all(findstr);
        return !peos.isEmpty();
    }

    public static void SqlInit(Connection connection) throws SQLException, IOException {
        // 创建ScriptRunner，用于执行SQL脚本
        ScriptRunner runner = new ScriptRunner(connection, false, false);
        runner.setErrorLogWriter(null);
        runner.setLogWriter(null);
        runner.runScript(Resources.getResourceAsReader("edu/rui/db_init.sql"));
    }

    //用于列出tables，返回List
    public static List<String> getTables(Connection connection) throws SQLException {
        List<String> strings = new ArrayList<>();
        DatabaseMetaData databaseMetaData = connection.getMetaData();
        ResultSet resultSet = databaseMetaData.getTables(null, "public", "%", new String[]{"TABLE"});
        while (resultSet.next()) {
            strings.add(resultSet.getString("TABLE_NAME"));
        }
        resultSet.close();
        return strings;
    }
}
