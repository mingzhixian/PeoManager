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
        String str = "<form method=\"post\" action=\"All\">\n" +
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


        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append(GetHtml.GetaddHead("所有记录"));

        try {
            List<Peo> peos = DBtool.all("SELECT * FROM web;");
            for (Peo peo : peos) {
                stringBuilder.append(String.format(str, peo.getName(), peo.getId()));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        stringBuilder.append(GetHtml.GetaddEnd());
        response.getWriter().write(stringBuilder.toString());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.getWriter().write("Post!!");
    }
}
