package edu.swu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet(name = "Find", value = "/Find")
public class Find extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str = "<form method=\"post\" action=\"Find\">\n" +
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

        response.setCharacterEncoding("utf-8");

        response.getWriter().write(GetHtml.GetaddHead("搜索记录") +
                str + GetHtml.GetaddEnd());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = "<form method=\"post\" action=\"Find\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";

        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");

        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append(GetHtml.GetaddHead("搜索记录"));
        String findstr = findstr(request.getParameter("name"), request.getParameter("id"));

        try {
            List<Peo> peos = DBtool.all(findstr);
            for (Peo peo : peos) {
                stringBuilder.append(String.format(str, peo.getName(), peo.getId()));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        stringBuilder.append(GetHtml.GetaddEnd());
        response.getWriter().write(stringBuilder.toString());
    }

    private String findstr(String name, String id) {
        String findstr = "";
        if (name == null && id != null) {
            findstr = "SELECT * FROM web2 WHERE id LIKE %" + id + "%;";
        } else if (name != null && id == null) {
            findstr = "SELECT * FROM web2 WHERE name LIKE %" + name + "%;";
        } else if (name == null && id == null) {
            findstr = "SELECT * FROM web2 ;";
        } else {
            findstr = "SELECT * FROM web2 WHERE name LIKE %" + name + "% and id LIKE %" + id + "%;";
        }
        return findstr;
    }
}
