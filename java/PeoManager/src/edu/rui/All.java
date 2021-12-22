package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet(name = "All", value = "/web/All")
public class All extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str1 = "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\" class=\"one\">\n" +
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
                "        </form></a>";
        String str2 = "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\">\n" +
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
                "        </form></a>";

        StringBuilder stringBuilder = new StringBuilder();
        try {
            if (request.getParameter("ele") == null) {
                stringBuilder.append(GetHtml.GetaddHead("所有记录"));
                List<Peo> peos = DBtool.all("SELECT * FROM peo LIMIT 10 OFFSET 0;");
                for (Peo peo : peos) {
                    stringBuilder.append(String.format(str1, peo.getId(), peo.getName(), peo.getId()));
                }
                stringBuilder.append(GetHtml.GetallEnd());
            } else {
                List<Peo> peos = DBtool.all("SELECT * FROM peo LIMIT 10 OFFSET " + request.getParameter("ele") + ";");
                for (Peo peo : peos) {
                    stringBuilder.append(String.format(str2, peo.getId(), peo.getName(), peo.getId()));
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
        response.getWriter().write(stringBuilder.toString());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.getWriter().write("Post!!");
    }
}
