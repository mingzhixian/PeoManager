package edu.rui;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.Objects;

@WebServlet(name = "Add", value = "/web/Add")
public class Add extends HttpServlet {

    private static final String INSERT_TEMPLATE1 =
            "INSERT INTO peo (`name`, `id`,'filePath') VALUES ('%s', '%s','%s')";
    private static final String INSERT_TEMPLATE2 =
            "INSERT INTO peo (`name`, `id`) VALUES ('%s', '%s')";
    private static final int MEMORY_THRESHOLD = 1024 * 1024 * 3;  // 3MB
    private static final int MAX_FILE_SIZE = 1024 * 1024 * 40; // 40MB
    private static final int MAX_REQUEST_SIZE = 1024 * 1024 * 50; // 50MB

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String str = GetHtml.GetHtmlSelect("GetAddForm", "");


        response.getWriter().write(GetHtml.GetHtmlSelect("GetHead", "添加记录") +
                str + GetHtml.GetHtmlSelect("GetEnd", ""));
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String name = null;
        String id = null;
        String filePath = null;
        String sql = null;
        // 配置上传参数
        DiskFileItemFactory factory = new DiskFileItemFactory();
        // 设置内存临界值 - 超过后将产生临时文件并存储于临时目录中
        factory.setSizeThreshold(MEMORY_THRESHOLD);
        // 设置临时存储目录
        factory.setRepository(new File(System.getProperty("java.io.tmpdir")));
        ServletFileUpload upload = new ServletFileUpload(factory);
        // 设置最大文件上传值
        upload.setFileSizeMax(MAX_FILE_SIZE);
        // 设置最大请求值 (包含文件和表单数据)
        upload.setSizeMax(MAX_REQUEST_SIZE);
        // 中文处理
        upload.setHeaderEncoding("UTF-8");

        FileItem fileItem = null;
        try {
            // 解析请求的内容提取文件数据
            List<FileItem> formItems = upload.parseRequest(request);
            if (formItems != null && formItems.size() > 0) {
                // 迭代表单数据
                for (FileItem item : formItems) {
                    // 处理不在表单中的字段
                    if (!item.isFormField()) {
                        fileItem = item;
                    } else {
                        if (item.getFieldName().equals("name")) {
                            name = item.getString("UTF-8");
                        }
                        if (item.getFieldName().equals("id")) {
                            id = item.getString("UTF-8");
                        }
                    }
                }
                if (!Objects.equals(fileItem.getName(), "")) {
                    String fileName = new File(fileItem.getName()).getName();
                    filePath = DBtool.getDataPath() + "attachment/" + id + fileName;
                    File file = new File(filePath);
                    file.getParentFile().mkdirs();
                    fileItem.write(file);
                    sql = String.format(INSERT_TEMPLATE1, name, id, filePath);
                } else {
                    sql = String.format(INSERT_TEMPLATE2, name, id);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        String back = "";
        try {
            if (DBtool.ishave(id)) {
                back = "已有该id，不可重复";
            } else {
                DBtool.excute(sql);
                back = "添加成功";
            }
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        String html = GetHtml.GetHtmlSelect("GetHead", "添加记录") + "<h1 style=\"color:#edeff2a3\">" + back + "</h1>" + GetHtml.GetHtmlSelect("GetEnd", "");
        response.getWriter().write(html);
    }
}
