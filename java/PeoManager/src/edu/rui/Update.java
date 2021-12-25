package edu.rui;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.Objects;

@WebServlet(name = "Update", value = "/web/Update")
public class Update extends HttpServlet {
    //删除与修改的数据库语句。
    private static final String UPDATE_TEMPLATE =
            "UPDATE peo SET name ='%s',id='%s' WHERE id ='%s'";
    private static final String DELETE_TEMPLATE =
            "DELETE FROM peo WHERE id ='%s'";
    private static final String SELECT_TEMPLATE = "SELECT * FROM peo WHERE id='%s';";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {

        String str = String.format(SELECT_TEMPLATE, request.getParameter("id"));
        String str1 = GetHtml.GetHtmlSelect("GetUpdateForm", "");
        try {
            List<Peo> peos = DBtool.all(str);
            String string = null;
            for (Peo peo : peos) {
                string = String.format(str1, peo.getId(), peo.getName(), peo.getId(), peo.getId(), peo.getId());
            }
            String html = GetHtml.GetHtmlSelect("GetHead", "更改记录") + string + GetHtml.GetHtmlSelect("GetAddEnd", "");
            response.getWriter().write(html);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str;
        String back = null;
        if (Objects.equals(request.getParameter("select"), "修改")) {
            try {
                if (!Objects.equals(request.getParameter("preid"), request.getParameter("id")) && DBtool.ishave(request.getParameter(
                        "id"))) {
                    back = "已有该id,不可重复";
                } else {
                    str = String.format(UPDATE_TEMPLATE, request.getParameter("name"), request.getParameter("id"), request.getParameter("preid"));
                    back = "修改成功";
                    DBtool.excute(str);
                }
            } catch (SQLException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            try {
                str = String.format(DELETE_TEMPLATE, request.getParameter("preid"));
                back = "删除成功";
                DBtool.excute(str);
            } catch (SQLException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        String html = GetHtml.GetHtmlSelect("GetHead", "更改记录") +
                "<h1 style=\"color:#edeff2a3\">" + back + "</h1>" + GetHtml.GetHtmlSelect("GetEnd", "");
        response.getWriter().write(html);

    }
}

