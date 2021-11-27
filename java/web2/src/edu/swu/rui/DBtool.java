package edu.swu.rui;

import javax.servlet.annotation.WebServlet;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "DBtool", value = "/DBtool")
public class DBtool {
    private static final String DB_DRIVER = "org.sqlite.JDBC";
    private static final String DB_URL = "jdbc:sqlite:/home/kic/文档/code/java/web2/web2.db";

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
}
