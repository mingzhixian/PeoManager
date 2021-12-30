package edu.rui;

import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.sql.SQLException;
import java.util.List;

@WebServlet(name = "Download", value = "/web/Download")
public class Download extends HttpServlet {
    private static final String SELECT_TEMPLATE = "SELECT * FROM peo WHERE id='%s';";

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = String.format(SELECT_TEMPLATE, request.getParameter("id"));
        String filePath = null;
        String fileName = null;
        try {
            List<Peo> peos = DBtool.all(str);
            for (Peo peo : peos) {
                filePath = peo.getFilPath();
            }
            String name = DBtool.getDataPath() + "attachment/" + request.getParameter("id");
            fileName = filePath.substring(filePath.indexOf(name) + name.length());
        } catch (SQLException e) {
            e.printStackTrace();
        }

        // 设置下载头信息
        response.setHeader("content-disposition", "attachment;filename=" + URLEncoder.encode(fileName, StandardCharsets.UTF_8));
        File file = new File(filePath);
        InputStream is = new FileInputStream(file);
        ServletOutputStream os = response.getOutputStream();
        int len;
        byte[] bytes = new byte[1024];
        while ((len = is.read(bytes)) != -1) {
            os.write(bytes, 0, len);
        }

        // 关闭资源
        os.close();
        is.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.getWriter().write("Post!!");
    }
}
