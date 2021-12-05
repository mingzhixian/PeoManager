package edu.rui;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Objects;

@WebFilter(filterName = "Filter", urlPatterns = "/web/*")

public class Filter implements javax.servlet.Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {

        HttpServletResponse response = (HttpServletResponse) servletResponse;
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        response.setCharacterEncoding("utf-8");
        request.setCharacterEncoding("utf-8");

        //选出关于登录有关的cookie
        Cookie[] cookies = request.getCookies();
        Cookie logined = null;
        if (cookies != null) {
            for (Cookie cookie : cookies) {  //查找登录用户的cookie
                if (Objects.equals(cookie.getName(), "logined")) {
                    logined = cookie;
                    break;
                }
            }
        }

        //检查如果无登录信息则拦截，else跳转并为cookie续命。
        if (logined == null && !Objects.equals(request.getRequestURI(), "/PeoManager/web/Login")) {
            response.sendRedirect("./Login");
        } else if (logined != null || Objects.equals(request.getRequestURI(), "/PeoManager/web/Login")) {
            if (logined != null) {
                logined.setMaxAge(60 * 10);   //cookie续命
                response.addCookie(logined);

                try {                      //权限检查
                    Count count = DBtool.login("SELECT * FROM count WHERE name = '" + logined.getValue() + "';");
                    if (Objects.equals(request.getRequestURI(), "/PeoManager/web/Add") && count.getAdmin() == 0 || Objects.equals(request.getRequestURI(), "/PeoManager/web/Update") && count.getAdmin() == 0) {
                        response.getWriter().write(GetHtml.GetaddHead("人员管理") + "<h1 style=\"color:#edeff2a3\">权限不足</h1>" + GetHtml.GetaddEnd());
                    }
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }

            filterChain.doFilter(request, response);
        }
    }

    @Override
    public void destroy() {

    }
}
