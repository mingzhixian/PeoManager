package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;

@WebServlet(name = "main", value = "/main")
public class main extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        {
            Connection sql = null;
            try {
                Class.forName("org.sqlite.JDBC");
                sql = DriverManager.getConnection("jdbc:sqlite:/home/kic/文档/code/java/web1/rui.db");
                System.out.println("Opened database successfully");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }   //数据库连接

        response.setCharacterEncoding("utf-8");

        StringBuilder stringBuilder = new StringBuilder();

        {
            stringBuilder.append("<html>\n" +
                    "<head>\n" +
                    "    <meta charset=\"utf-8\"/>\n" +
                    "    <title>rui</title>\n" +
                    "</head>\n" +
                    "<body>");
        }  //头部操作

        {
            for (int i = 1; i < 7; i++) {
                String s = "<h" + i + ">你好，hello.</h" + i + ">\n<br>\n";
                stringBuilder.append(s);
            }
        }    //body操作

        {
            stringBuilder.append("</body>\n" +
                    "</html>");
        }   //尾部操作

        response.getWriter().write(stringBuilder.toString());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
