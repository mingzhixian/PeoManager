package edu.rui;

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
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = "<form method=\"post\" action=\"Add\"  class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"\" required>\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   value=\"\" required>\n" +
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
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = String.format(INSERT_TEMPLATE, request.getParameter("name"), request.getParameter("id"));
        String back = "";
        try {
            if (DBtool.ishave(request.getParameter("id"))) {
                back = "已有该id，不可重复";
            } else {
                DBtool.excute(str);
                back = "添加成功";
            }
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetaddHead("添加记录") +
                "<h1 style=\"color:#edeff2a3\">" + back + "</h1>" + GetHtml.GetaddEnd();
        response.getWriter().write(html);
    }
}
