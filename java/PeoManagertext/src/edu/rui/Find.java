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


        response.getWriter().write(str);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = "<div class=\"form one\">\n" +
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
                "                         <span style=\"margin:20px 0 0 86px;\" " +
                " >修改</span>\n" +
                "                         <span id=\"%s\" style=\"margin:20px 0 0 30px;\">删除</span>\n" +
                "                         <script>document.getElementById(\"%s\").onclick = function (){update(%s)}</script>" +
                "                    </td>" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";


        StringBuilder stringBuilder = new StringBuilder();

        //返回网页框架
        String findstr = findstr(request.getParameter("name"), request.getParameter("id"));

        //数据库查询，想返回值中增加记录。
        try {
            List<Peo> peos = DBtool.all(findstr);
            for (Peo peo : peos) {
                stringBuilder.append(String.format(str, peo.getName(), peo.getId(), peo.getId(), peo.getId(), peo.getId()));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        response.getWriter().write(stringBuilder.toString());
    }

    private String findstr(String name, String id) {
        //根据不同查找类型（只限制姓名、只限制id、均进行限制）返回不同数据库查询语句。
        String findstr = "";
        if (Objects.equals(name, "") && !Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo WHERE id LIKE '%" + id + "%';";
        } else if (!Objects.equals(name, "") && Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo WHERE name LIKE '%" + name + "%';";
        } else if (Objects.equals(name, "") && Objects.equals(id, "")) {
            findstr = "SELECT * FROM peo ;";
        } else {
            findstr = "SELECT * FROM peo WHERE name LIKE '%" + name + "%' and id LIKE '%" + id + "%';";
        }
        return findstr;
    }
}
