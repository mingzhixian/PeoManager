package edu.rui;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "Uset", value = "/web/Uset")
public class Uset extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str1 = GetHtml.GetHtmlSelect("GetUsetFormBody", "");
        String str2 = GetHtml.GetHtmlSelect("GetUsetFormBodyChecked", "");

        StringBuilder stringBuilder = new StringBuilder();
        try {
            stringBuilder.append(GetHtml.GetHtmlSelect("GetHead", "权限管理"));
            stringBuilder.append(GetHtml.GetHtmlSelect("GetUsetFormHead", ""));
            List<Count> counts = DBtool.login("SELECT * FROM count;");
            for (Count count : counts) {
                if (count.getAdmin() == 0) {
                    stringBuilder.append(String.format(str1, count.getName(), count.getName()));
                } else {
                    stringBuilder.append(String.format(str2, count.getName(), count.getName()));
                }
            }
            stringBuilder.append(GetHtml.GetHtmlSelect("GetUsetFormEnd", ""));
            stringBuilder.append(GetHtml.GetHtmlSelect("GetAddEnd", ""));

        } catch (SQLException e) {
            e.printStackTrace();
        }
        response.getWriter().write(stringBuilder.toString());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            List<String> sqls = new ArrayList<>();
            List<Count> counts = DBtool.login("SELECT * FROM count;");
            for (Count count : counts) {
                String i = request.getParameter(count.getName());
                if (i == null) {
                    sqls.add(String.format("UPDATE count SET admin ='0' WHERE name ='%s';", count.getName()));
                } else {
                    sqls.add(String.format("UPDATE count SET admin ='1' WHERE name ='%s';", count.getName()));
                }
            }
            DBtool.excuteBatch(sqls);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        response.getWriter().write(GetHtml.GetHtmlSelect("GetHead", "权限管理") + "<h1 style=\"color:#edeff2a3\">权限设置成功</h1>" + GetHtml.GetHtmlSelect("GetEnd", ""));
    }

}
