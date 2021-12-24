package edu.rui;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.sql.SQLException;
import java.util.Objects;

import static java.lang.String.valueOf;

@WebServlet(name = "Login", value = "/web/Login")
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        //str1为登录界面，str2为登出界面
        String str1 = "<form method=\"post\" action=\"Login\"  class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        账户\n" +
                "                        <input type=\"text\" name=\"name\" value=\"\" required>\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        密码\n" +
                "                        <input type=\"password\" name=\"password\"   value=\"\" required>\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        验证码\n" +
                "                        <input type=\"text\" name=\"checkcode\"   value=\"\" required>\n" +
                "                    </td>\n" +
                "                    <td><img id=\"checkcodepic\"  onclick=\"checkcodeupdate()\" src=\"../CheckCodeBack\"/></td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td><input type=\"submit\" style=\"color: aliceblue;margin:20px 0 0 200px;" +
                "\" value=\"登录或注册\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
        String str2 = "<form method=\"post\" action=\"Login\"  class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td><input type=\"submit\" style=\"color: aliceblue;margin:20px 0 0 200px;" +
                "\" value=\"登出\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";

        //寻找cookie记录
        Cookie logined = null;
        if (request.getCookies() != null) {
            Cookie[] cookies = request.getCookies();
            for (Cookie cookie : cookies) {
                if (Objects.equals(cookie.getName(), "logined")) {
                    logined = cookie;
                    break;
                }
            }
        }
        //判断登录还是登出
        if (logined != null) {
            response.getWriter().write(GetHtml.GetaddHead("后台登录") +
                    str2 + GetHtml.GetaddEnd());
        } else {
            response.getWriter().write(GetHtml.GetaddHead("后台登录") +
                    str1 + GetHtml.GetaddEnd());
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String back = "";
        Cookie logined = null;
        Cookie[] cookies = request.getCookies();

        //找出cookies中登录相关的cookie
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (Objects.equals(cookie.getName(), "logined")) {
                    logined = cookie;
                    break;
                }
            }
        }

        //如果当前有登录记录，则登出，else检测验证码然后再检查数据库，数据库没有记录则注册，数据库有则检测密码。
        if (logined != null) {
            logined.setMaxAge(0);
            response.addCookie(logined);
            back = "<h1 style=\"color:#edeff2a3;\">登出成功</h1>";
        } else {
            HttpSession session = request.getSession(true);
            if (valueOf(session.getAttribute("CheckCode")).equalsIgnoreCase(request.getParameter("checkcode"))) {
                try {
                    Count count = DBtool.login("SELECT * FROM count WHERE name = '" + request.getParameter("name") + "';");
                    if (count == null) {   //找不到便注册自动新用户
                        if (Objects.equals(request.getParameter("name"), "") || Objects.equals(request.getParameter("password"), "")) {
                            back = "<h1 style=\"color:#edeff2a3;\">用户名或密码不应为空。</h1>";
                        } else {
                            DBtool.excute("INSERT INTO count (`name`, `password`) VALUES ('" + request.getParameter("name") + "', '" + request.getParameter("password") + "')");
                            back = "<h1 style=\"color:#edeff2a3;\">账户已注册，请返回登录。</h1>";
                        }
                    } else if (Objects.equals(count.getPassword(), request.getParameter("password"))) {
                        back = "<h1 style=\"color:#edeff2a3;\">登录成功</h1>";
                        logined = new Cookie("logined", URLEncoder.encode(request.getParameter("name"), StandardCharsets.UTF_8));
                        logined.setMaxAge(60 * 10);
                        response.addCookie(logined);
                    } else {
                        back = "<h1 style=\"color:#edeff2a3;\">密码错误</h1>";
                    }
                } catch (SQLException | ClassNotFoundException e) {
                    e.printStackTrace();
                }
            } else {
                back = "<h1 style=\"color:#edeff2a3;\">验证码错误</h1>";
            }
        }
        response.getWriter().write(GetHtml.GetaddHead("后台登录") + back + GetHtml.GetaddEnd());

    }

}