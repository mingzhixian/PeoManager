package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.Objects;

@WebServlet(name = "Find", value = "/web/Find")
public class Find extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str = "<form method=\"post\" action=\"Find\"  class=\"one\">\n" +
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


        response.getWriter().write(GetHtml.GetaddHead("搜索记录") +
                str + GetHtml.GetaddEnd());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

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
        String str3 = "<h1 style=\"color:#edeff2a3\"><span>查找名:</span><span id=\"findname\">%s</span><span> 查找id:</span><span id=\"findid\">%s</span></h1>";
        String str4 = "<h1 style=\"color:#edeff2a3\">%s</h1>";


        StringBuilder stringBuilder = new StringBuilder();

        String findstr = findstr(request.getParameter("name"), request.getParameter("id"), request.getParameter("ele"));

        //数据库查询，想返回值中增加记录。
        try {
            List<Peo> peos = DBtool.all(findstr);
            if (request.getParameter("ele") == null) {
                //返回网页框架
                stringBuilder.append(GetHtml.GetaddHead("搜索记录"));
                if (peos.isEmpty()) {
                    stringBuilder.append(String.format(str4, "未找到"));
                } else {
                    stringBuilder.append(String.format(str3, request.getParameter("name"), request.getParameter("id")));
                }
                for (Peo peo : peos) {
                    stringBuilder.append(String.format(str1, peo.getId(), peo.getName(), peo.getId()));
                }
                stringBuilder.append(GetHtml.GetallEnd());
            } else {
                for (Peo peo : peos) {
                    stringBuilder.append(String.format(str2, peo.getId(), peo.getName(), peo.getId()));
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
        response.getWriter().write(stringBuilder.toString());
    }

    private String findstr(String name, String id, String ele) {
        //根据不同查找类型（只限制姓名、只限制id、均进行限制）返回不同数据库查询语句。
        String findstr = "";
        String limit = "LIMIT 10 OFFSET 0";
        if (ele != null) {
            limit = "LIMIT 10 OFFSET " + ele;
        }
        if (Objects.equals(name, "") && !Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo WHERE id LIKE '%" + id + "%'" + limit + ";";
        } else if (!Objects.equals(name, "") && Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo WHERE name LIKE '%" + name + "%'" + limit + ";";
        } else if (Objects.equals(name, "") && Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo " + limit + ";";
        } else {
            findstr = "SELECT * FROM peo WHERE name LIKE '%" + name + "%' and id LIKE '%" + id + "%'" + limit + ";";
        }
        return findstr;
    }
}
