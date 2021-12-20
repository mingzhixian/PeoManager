package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "Add", value = "/web/Add")
public class Add extends HttpServlet {

    private static final String INSERT_TEMPLATE =
            "INSERT INTO peo (`name`, `id`) " +
                    "VALUES ('%s', '%s')";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str = "<div class=\"form\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   value=\"\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td><span>确定</span></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </div>";

        System.out.println(str);
        response.getWriter().write(str);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = String.format(INSERT_TEMPLATE, request.getParameter("name"), request.getParameter("id"));
        try {
            DBtool.excute(str);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        String html = "<h1 style=\"color:#edeff2a3\">添加成功</h1>";
        response.getWriter().write(html);
    }
}
