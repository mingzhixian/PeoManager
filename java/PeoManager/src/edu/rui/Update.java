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

    private static final String UPDATE_TEMPLATE =
            "UPDATE web SET name ='%s' WHERE id ='%s'";
    private static final String DELETE_TEMPLATE =
            "DELETE FROM web WHERE id ='%s'";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String str = String.format(DELETE_TEMPLATE, request.getParameter("id"));
        try {
            DBtool.excute(str);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetaddHead("删除记录") +
                "<h1 style=\"color=\"aliceblue\"\">删除成功</h1>" + GetHtml.GetaddEnd();
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
                "<h1 style=\"color=\"aliceblue\"\">更改成功</h1>" + GetHtml.GetaddEnd();
        response.getWriter().write(html);
    }
}

