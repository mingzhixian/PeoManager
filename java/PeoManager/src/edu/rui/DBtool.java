package edu.rui;

import javax.servlet.annotation.WebServlet;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "DBtool", value = "/web/DBtool")
public class DBtool {
    private static final String DB_DRIVER = "org.sqlite.JDBC";
    private static final String DB_URL = "jdbc:sqlite:/home/kic/DB/PeoManager.db";

    public static void excute(String str) throws SQLException {
        try {
            Class.forName(DB_DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        try (Connection connection = DriverManager.getConnection(DB_URL)) {
            try (Statement statement = connection.createStatement()) {
                statement.execute(str);
            }
        }
    }

    public static List<Peo> all(String sql) throws SQLException {
        List<Peo> peos = new ArrayList<>();
        try {
            Class.forName(DB_DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        try (Connection connection = DriverManager.getConnection(DB_URL)) {
            try (Statement statement = connection.createStatement()) {
                ResultSet one = statement.executeQuery(sql);
                while (one.next()) {
                    Peo peo = new Peo(one.getString("name"), one.getString("id"));
                    peos.add(peo);
                }
            }
        }
        return peos;
    }

    public static Count login(String sql) throws SQLException {
        Count count = null;
        try {
            Class.forName(DB_DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        try (Connection connection = DriverManager.getConnection(DB_URL)) {
            try (Statement statement = connection.createStatement()) {
                ResultSet one = statement.executeQuery(sql);
                while (one.next()) {
                    count = new Count(one.getString("name"), one.getString("password"), one.getInt("admin"));
                }
            }
        }
        return count;
    }

    public static boolean ishave(String id) throws SQLException {
        String findstr = "SELECT * FROM peo WHERE id ='" + id + "';";
        List<Peo> peos = all(findstr);
        return !peos.isEmpty();
    }
}
