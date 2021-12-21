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


        response.getWriter().write(GetHtml.GetaddHead("搜索记录") +
                str + GetHtml.GetaddEnd());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str1 = "<form method=\"post\" action=\"Update\" class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\" readonly=\"readonly\" value=\"%s\" >\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                         <input type=\"submit\" style=\"color: aliceblue;margin:20px 0 0 86px;\" " +
                "value=\"修改\">\n" +
                "                         <input type=\"button\" id=\"%s\" style=\"color: aliceblue;margin:20px 0" +
                " 0 30px;\" value=\"删除\">\n" +
                "                         <script>document.getElementById(\"%s\").onclick = function () {open('" +
                "./Update?id=%s')}</script>" +
                "                    </td>" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";

        String str2 = "<form method=\"post\" action=\"Update\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\" readonly=\"readonly\" value=\"%s\" >\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                         <input type=\"submit\" style=\"color: aliceblue;margin:20px 0 0 86px;\" " +
                "value=\"修改\">\n" +
                "                         <input type=\"button\" id=\"%s\" style=\"color: aliceblue;margin:20px 0" +
                " 0 30px;\" value=\"删除\">\n" +
                "                         <script>document.getElementById(\"%s\").onclick = function () {open('" +
                "./Update?id=%s')}</script>" +
                "                    </td>" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
        String str3 = "<h1 style=\"color:#edeff2a3\"><span>查找名:</span><span id=\"findname\">%s</span><span>查找id:</span><span id=\"findid\">%s</span></h1>";
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
                    stringBuilder.append(String.format(str1, peo.getName(), peo.getId(), peo.getId(), peo.getId(),
                            peo.getId()));
                }
                stringBuilder.append(GetHtml.GetallEnd());
            } else {
                for (Peo peo : peos) {
                    stringBuilder.append(String.format(str2, peo.getName(), peo.getId(), peo.getId(), peo.getId(),
                            peo.getId()));
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
