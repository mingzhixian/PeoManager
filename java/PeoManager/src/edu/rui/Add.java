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
            "INSERT INTO web (`name`, `id`) " +
                    "VALUES ('%s', '%s')";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str = "<form method=\"post\" action=\"Add\">\n" +
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
                "                    <td><input type=\"submit\" style=\"color: aliceblue;margin:20px 0 0 200px;" +
                "\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";


        response.getWriter().write(GetHtml.GetaddHead("添加记录") +
                str + GetHtml.GetaddEnd());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = String.format(INSERT_TEMPLATE, request.getParameter("name"), request.getParameter("id"));
        try {
            DBtool.excute(str);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetaddHead("添加记录") +
                "<h1 style=\"color=\"aliceblue\"\">添加成功</h1>" + GetHtml.GetaddEnd();
        response.getWriter().write(html);
    }
}
