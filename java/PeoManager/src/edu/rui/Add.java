package edu.rui;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "Add", value = "/web/Add")
public class Add extends HttpServlet {

    private static final String INSERT_TEMPLATE =
            "INSERT INTO peo (`name`, `id`) " +
                    "VALUES ('%s', '%s')";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = GetHtml.GetHtmlSelect("GetAddForm", "");


        response.getWriter().write(GetHtml.GetHtmlSelect("GetHead", "添加记录") +
                str + GetHtml.GetHtmlSelect("GetEnd", ""));
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = String.format(INSERT_TEMPLATE, request.getParameter("name"), request.getParameter("id"));
        String back = "";
        try {
            if (DBtool.ishave(request.getParameter("id"))) {
                back = "已有该id，不可重复";
            } else {
                DBtool.excute(str);
                back = "添加成功";
            }
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetHtmlSelect("GetHead", "添加记录") +
                "<h1 style=\"color:#edeff2a3\">" + back + "</h1>" + GetHtml.GetHtmlSelect("GetEnd", "");
        response.getWriter().write(html);
    }
}
