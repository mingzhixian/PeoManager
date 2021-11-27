package edu.rui;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
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
        if (logined == null && !Objects.equals(request.getRequestURI(), "/web3_war_exploded/web/Login")) {
            response.sendRedirect("./Login");
        } else if (logined != null || Objects.equals(request.getRequestURI(), "/web3_war_exploded/web/Login")) {
            filterChain.doFilter(request, response);
        }
    }

    @Override
    public void destroy() {

    }
}
