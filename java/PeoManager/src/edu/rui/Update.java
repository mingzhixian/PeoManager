package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "Update", value = "/web/Update")
public class Update extends HttpServlet {
    //删除与修改的数据库语句。
    private static final String UPDATE_TEMPLATE =
            "UPDATE peo SET name ='%s' WHERE id ='%s'";
    private static final String DELETE_TEMPLATE =
            "DELETE FROM peo WHERE id ='%s'";


    //为减少运行的servlet程序，删除与修改放在同一个servlet程序中，删除仅需传递id值便可所以使用get,修改须传递id值以及修改后的名字，使用post。
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = String.format(DELETE_TEMPLATE, request.getParameter("id"));
        try {
            DBtool.excute(str);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetaddHead("删除记录") +
                "<h1 style=\"color:#edeff2a3\">删除成功</h1>" + GetHtml.GetaddEnd();
        response.getWriter().write(html);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = String.format(UPDATE_TEMPLATE, request.getParameter("name"), request.getParameter("id"));
        try {
            DBtool.excute(str);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetaddHead("修改记录") +
                "<h1 style=\"color:#edeff2a3\">更改成功</h1>" + GetHtml.GetaddEnd();
        response.getWriter().write(html);
    }
}

