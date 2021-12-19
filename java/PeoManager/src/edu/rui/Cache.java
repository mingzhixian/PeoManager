package edu.rui;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;
import java.util.Objects;

@WebFilter(filterName = "Cache", urlPatterns = "/resource/*")

public class Cache implements javax.servlet.Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {

        HttpServletResponse response = (HttpServletResponse) servletResponse;
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        response.setCharacterEncoding("utf-8");
        request.setCharacterEncoding("utf-8");
        Date d = new Date();
        Long time;
        if (Objects.equals(request.getRequestURI(), "/PeoManager/resource/font/SysFont-Medium.ttf")) {
            response.setHeader("Cache-Control", "max-age=60*60*24*100");
        } else {
            response.setHeader("Cache-Control", "max-age=60*60*24");
        }
        filterChain.doFilter(request, response);
    }

    @Override
    public void destroy() {

    }
}

