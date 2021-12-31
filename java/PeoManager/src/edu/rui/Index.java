package edu.rui;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "Index", value = "/web/Index")
public class Index extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String str = GetHtml.GetHtmlSelect("GetIndexForm", "");
        try {
            String PeoEle = String.valueOf(DBtool.allEle("peo"));
            String CountEle = String.valueOf(DBtool.allEle("count"));
            String Online = String.valueOf(DBtool.allEle("peo"));
            str = String.format(str, PeoEle, CountEle, Online);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        String string = GetHtml.GetHtmlSelect("GetHead", "人员管理") + str + GetHtml.GetHtmlSelect("GetEnd", "");
        response.getWriter().write(string);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
