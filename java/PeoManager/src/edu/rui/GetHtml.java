package edu.rui;

import com.googlecode.htmlcompressor.compressor.HtmlCompressor;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Objects;

public class GetHtml {
    private static GetHtml movingInvoke = new GetHtml(); // 创建MovingInvokeTest对象

    public static String GetHead(String set) {
        return "<html >\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <title>PeoManager</title>\n" +
                "    <link href=\"../resource/img/manager.svg\" rel=\"shortcut icon\">\n" +
                "<link href=\"../resource/css/main.css\" type=\"text/css\" rel=\"stylesheet\">" +
                "<script src=\"../resource/js/anime.min.js\" rel=\"script\"></script>" +
                "    <script>\n" +
                "    function checkcodeupdate() {\n" +
                "        document.getElementById(\"checkcodepic\").src = \".././CheckCodeBack\" + '?' + new Date();\n" +
                "    }\n" +
                "    </script>" +
                "</head>\n" +
                "<body>\n" +
                "<div id=\"tiltediv\">\n" +
                "    <h1 class=\"tilte\"><a href=\"Index\" style=\"color: aliceblue;" +
                "text-decoration: " +
                "none\">" +
                set + "</a></h1>\n" +
                "</div>\n" +
                "<div id=\"site\">\n" +
                "   <a href=\"Add\" class=\"mod\"><img width=\"30px\" src=\"../resource/img/添加用户.svg\">添加记录</a>\n" +
                "    <a href=\"Find\" class=\"mod\"><img width=\"30px\" src=\"../resource/img/查找用户.svg\">搜索记录</a>\n" +
                "    <a href=\"All\" class=\"mod\"><img width=\"30px\" src=\"../resource/img/所有用户.svg\">所有记录</a>\n" +
                "    <a href=\"Login\" class=\"mod\"><img width=\"30px\" src=\"../resource/img/登录用户.svg\">后台登录</a>\n" +
                "    <div id=\"formmod\">\n";
    }

    public static String GetEnd() {
        return "</div>\n" +
                "</div>\n" +
                "<script src=\"../resource/js/animation.js\" rel=\"script\"></script>" +
                "<script type=\"text/javascript\" color=\"230,230,250\" opacity='0.7' zIndex=\"-1\" count=\"150\" " +
                "src=\"../resource/js/canvas-nest.js\"></script>" +
                "<script src=\"https://cdn.bootcdn.net/ajax/libs/jquery/3.6.0/jquery.js\"></script>" +
                "<script src=\"../resource/js/main.js\" rel=\"script\"></script>" +
                "</body>\n" +
                "</html>";
    }

    public static String GetAddEnd() {
        return "</div>\n" +
                "</div>\n" +
                "<script src=\"../resource/js/animation.js\" rel=\"script\"></script>" +
                "<script src=\"https://cdn.bootcdn.net/ajax/libs/jquery/3.6.0/jquery.js\"></script>" +
                "<script src=\"../resource/js/waterflow.js\" rel=\"script\"></script>" +
                "<script src=\"../resource/js/main.js\" rel=\"script\"></script>" +
                "<script type=\"text/javascript\" color=\"230,230,250\" opacity='0.7' zIndex=\"-1\" count=\"150\" " +
                "src=\"../resource/js/canvas-nest.js\"></script>" +
                "</body>\n" +
                "</html>";
    }

    public static String GetIndexForm() {
        return "<div class=\"from one\">\n" +
                "            <table style=\"text-align: left;margin-left: 12px\">\n" +
                "                <tr>\n" +
                "                    <td>人员数据总量</td>\n" +
                "                    <td style=\"width:400px;text-align: right\">%s</td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>注册用户总量</td>\n" +
                "                    <td style=\"width:400px;text-align: right\">%s</td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>当前访问人数</td>\n" +
                "                    <td style=\"width:400px;text-align: right\">%s</td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </div>";
    }

    public static String GetAddForm() {
        return "<form method=\"post\" action=\"Add\"  class=\"one\" enctype=\"multipart/form-data\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"\" required>\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   value=\"\" required oninput=\"value=value.replace(/[^\\d]/g,'')\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        <input type=\"file\" name=\"attachment\" style=\"background-color: #566e3e00; color: aliceblue;" +
                "margin:20px 0 0 86px;\">\n" +
                "                        <input type=\"submit\" style=\"background-color: #4b5e87ad; color: aliceblue;margin:20px 0 0 30px;\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
    }

    public static String GetAllFormOne() {
        return "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\" class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form></a>";
    }

    public static String GetAllForm() {
        return "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form></a>";
    }

    public static String GetFindFormOne() {
        return "<form method=\"post\" action=\"Find\"  class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" value=\"\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   value=\"\" oninput=\"value=value.replace(/[^\\d]/g,'')\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "                <tr>\n" +
                "                    <td><input type=\"submit\" style=\"background-color: #4b5e87ad; color: aliceblue;margin:20px 0 0 200px;" +
                "\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
    }

    public static String GetFindPostFormOne() {
        return "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\" class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form></a>";
    }

    public static String GetFindPostForm() {
        return "<a href=\"Update?id=%s\"><form method=\"post\" action=\"All\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td>\n" +
                "                        名字\n" +
                "                        <input type=\"text\" name=\"name\" disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                    <td>\n" +
                "                        学号\n" +
                "                        <input type=\"text\" name=\"id\"   disabled value=\"%s\">\n" +
                "                    </td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form></a>";
    }

    public static String GetLoginForm() {
        return "<form method=\"post\" action=\"Login\"  class=\"one\">\n" +
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
                "                    <td><input type=\"submit\" style=\"background-color: #566e3ede; color: aliceblue;margin:20px 0 0 200px;" +
                "\" value=\"登录或注册\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
    }

    public static String GetLoginOutForm() {
        return "<form method=\"post\" action=\"Login\"  class=\"one\">\n" +
                "            <table>\n" +
                "                <tr>\n" +
                "                    <td><input type=\"submit\" style=\"background-color: #9336369e; color: aliceblue;margin:20px 0 0 200px;" +
                "\" value=\"登出\"></td>\n" +
                "                </tr>\n" +
                "            </table>\n" +
                "        </form>";
    }

    public static String GetUpdateForm() {
        return "<form method=\"post\" action=\"Update\" class=\"one\" id=\"%s\">\n" +
                "    <table>\n" +
                "        <tr>\n" +
                "            <td>\n" +
                "                名字\n" +
                "                <input type=\"text\" name=\"name\" value=\"%s\">\n" +
                "            </td>\n" +
                "            <td>\n" +
                "                学号\n" +
                "                <input type=\"text\" name=\"id\"  value=\"%s\">\n" +
                "            </td>\n" +
                "        </tr>\n" +
                "        <tr>\n" +
                "            <td>\n" +
                "                <input type=\"button\" style=\"background-color: #4b5e87ad; color: aliceblue;margin:20px 0 0 86px;\" " +
                "value=\"修改\" onclick=\"formSubmit(%s ,'修改')\">\n" +
                "                <input type=\"button\" id=\"222020321072029\" style=\"background-color: #9336369e;  color: aliceblue;margin:20px " +
                "0 0 30px;\" value=\"删除\" onclick=\"formSubmit(%s ,'删除')\">\n" +
                "            </td>\n" +
                "        </tr>\n" +
                "    </table>\n" +
                "</form>";
    }

    public static String GetUpdateFormAttachment() {
        return "<form method=\"post\" action=\"Update\" class=\"one\" id=\"%s\">\n" +
                "    <table>\n" +
                "        <tr>\n" +
                "            <td>\n" +
                "                名字\n" +
                "                <input type=\"text\" name=\"name\" value=\"%s\">\n" +
                "            </td>\n" +
                "            <td>\n" +
                "                学号\n" +
                "                <input type=\"text\" name=\"id\"  value=\"%s\">\n" +
                "            </td>\n" +
                "        </tr>\n" +
                "        <tr>\n" +
                "            <td>\n" +
                "                <input type=\"button\" style=\"background-color: #4b5e87ad;  color: aliceblue;margin:20px 0 0 86px;\" " +
                "value=\"修改\" onclick=\"formSubmit(%s ,'修改')\">\n" +
                "                <input type=\"button\" id=\"222020321072029\" style=\"background-color: #9336369e; " +
                "color: aliceblue; margin:20px 0 0 30px;\" value=\"删除\" onclick=\"formSubmit(%s ,'删除')\">\n" +
                "            </td>\n" +
                "        </tr>\n" +
                "        <tr>\n" +
                "            <td>\n" +
                "                <a class=\"download\" href=\"Download?id=%s\">下载附件</a>" +
                "            </td>\n" +
                "        </tr>\n" +
                "    </table>\n" +
                "</form>";
    }

    public static String GetUsetFormHead() {
        return "<form class=\"one\" method=\"post\" action=\"Uset\">\n" +
                "            <table style=\"text-align: left;margin-left: 12px\">";
    }

    public static String GetUsetFormBody() {
        return "<tr>\n" +
                "                    <td>%s</td>\n" +
                "                    <td style=\"width:400px;text-align: right\"><input name=\"%s\" " +
                "type=\"checkbox\" " +
                "value=\"1\"></td>\n" +
                "                </tr>";
    }

    public static String GetUsetFormBodyChecked() {
        return "<tr>\n" +
                "                    <td>%s</td>\n" +
                "                    <td style=\"width:400px;text-align: right\"><input name=\"%s\" " +
                "type=\"checkbox\" " +
                "value=\"1\" checked ='checked'></td>\n" +
                "                </tr>";
    }

    public static String GetUsetFormEnd() {
        return "<tr>\n" +
                "                    <td><input type=\"submit\"></td>\n" +
                "                </tr></table>\n" +
                "        </form>";
    }

    public static String GetHtmlSelect(String select, String str) {
        String html = null;
        html = movingInvoke.GetStrMethod(select, str);
        return ZipHtml(html);
    }

    private String GetStrMethod(String select, String str) {
        Method method = null;
        String html = null;
        try {
            if (!Objects.equals(str, "")) {
                method = movingInvoke.getClass().getMethod(select, Class.forName("java.lang.String"));
                html = (String) method.invoke(movingInvoke, str);
            } else {
                method = movingInvoke.getClass().getMethod(select);
                html = (String) method.invoke(movingInvoke);
            }
        } catch (NoSuchMethodException | InvocationTargetException | IllegalAccessException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return html;
    }

    private static String ZipHtml(String html) {
        HtmlCompressor compressor = new HtmlCompressor();

        compressor.setEnabled(true);                   // 如果false，则关闭所有压缩（默认值为true）
        compressor.setRemoveComments(true);            // 如果false保留HTML注释（默认值为true）
        compressor.setRemoveMultiSpaces(true);         // 如果false保留多个空格字符（默认值为true）
        compressor.setRemoveIntertagSpaces(true);      // 删除iter标记空白字符
        compressor.setRemoveQuotes(true);              // 删除不必要的标记属性引号
        compressor.setSimpleDoctype(true);             // 简化现有doctype
        compressor.setRemoveScriptAttributes(true);    // 从script标签中移除可选属性
        compressor.setRemoveStyleAttributes(true);     // 从style标签中移除可选属性
        compressor.setRemoveLinkAttributes(true);      // 从link标签中移除可选属性
        compressor.setRemoveFormAttributes(true);      // 从form标签中移除可选属性
        compressor.setRemoveInputAttributes(true);     // 从input标签中移除可选属性
        compressor.setSimpleBooleanAttributes(true);   // 从布尔标签属性中移除值
        compressor.setRemoveJavaScriptProtocol(true);  // 从内联事件处理程序中删除“javascript:”
        compressor.setRemoveHttpProtocol(true);        // 将“http://”替换为“//”内部标记属性
        compressor.setRemoveHttpsProtocol(true);       // 将“https://”替换为“//”内部标记属性
        compressor.setPreserveLineBreaks(false);        // 保留原始换行符
        compressor.setRemoveSurroundingSpaces("br,p"); // 删除提供的标记周围的空格
        compressor.setCompressCss(true);               // 压缩内联css
        compressor.setCompressJavaScript(true);        // 压缩内联js
        compressor.setYuiCssLineBreak(80);             // Yahoo YUI压缩机的换行参数
        compressor.setYuiJsDisableOptimizations(true); // 禁用Yahoo YUI压缩器的优化参数
        compressor.setYuiJsLineBreak(-1);              // Yahoo YUI压缩机的换行参数
        compressor.setYuiJsNoMunge(true);              //--nomunge param for Yahoo YUI Compressor
        compressor.setYuiJsPreserveAllSemiColons(true);// 为Yahoo YUI Compressor保留半参数

        return compressor.compress(html);
    }
}