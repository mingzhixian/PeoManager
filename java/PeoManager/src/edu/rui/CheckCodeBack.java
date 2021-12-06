package edu.rui;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.OutputStream;

@WebServlet(name = "CheckCodeBack", value = "/CheckCodeBack")
public class CheckCodeBack extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session = request.getSession(true);

        CheckCodeCreate coder = new CheckCodeCreate();
        session.setAttribute("CheckCode", coder.getCodeString());
        response.setContentType("image/png");
        try (OutputStream output = response.getOutputStream()) {
            coder.outputCodeImage(output);
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.getWriter().write("Post!");
    }

}
