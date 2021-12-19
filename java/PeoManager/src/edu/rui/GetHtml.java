package edu.rui;

public class GetHtml {
    public static String GetHead() {
        return "<html>\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <title>web3</title>\n" +
                "</head>\n" +
                "<body>";
    }

    public static String GetEnd() {
        return "</body>\n" +
                "</html>";
    }

    public static String GetaddHead(String set) {
        return "<html>\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <title>PeoManager</title>\n" +
                "    <link href=\"../img/manager.svg\" rel=\"shortcut icon\">\n" +
                "<link href=\"../css/main.css\" type=\"text/css\" rel=\"stylesheet\">" +
                "<script src=\"../js/anime.min.js\" rel=\"script\"></script>" +
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
                "   <a href=\"Add\" class=\"mod\"><img width=\"30px\" src=\"../img/添加用户" +
                ".svg\">添加记录</a>\n" +
                "    <a href=\"Find\" class=\"mod\"><img width=\"30px\" src=\"../img/查找用户" +
                ".svg\">搜索记录</a>\n" +
                "    <a href=\"All\" class=\"mod\"><img width=\"30px\" src=\"../img/所有用户" +
                ".svg\">所有记录</a>\n" +
                "    <a href=\"Login\" class=\"mod\"><img width=\"30px\" src=\"../img/登录用户" +
                ".svg\">后台登录</a>\n" +
                "    <div id=\"formmod\">\n";
    }

    public static String GetaddEnd() {
        return "</div>\n" +
                "</div>\n" +
                "<script src=\"../js/animation.js\" rel=\"script\"></script>" +
                "<script type=\"text/javascript\" color=\"230,230,250\" opacity='0.7' zIndex=\"-1\" count=\"150\" " +
                "src=\"../js/canvas-nest.js\"></script>" +
                "</body>\n" +
                "</html>";
    }

    public static String GetallEnd() {
        return "</div>\n" +
                "</div>\n" +
                "<script src=\"../js/animation.js\" rel=\"script\"></script>" +
                "<script src=\"https://cdn.bootcdn.net/ajax/libs/jquery/3.6.0/jquery.js\"></script>" +
                "<script src=\"../js/waterflow.js\" rel=\"script\"></script>" +
                "<script type=\"text/javascript\" color=\"230,230,250\" opacity='0.7' zIndex=\"-1\" count=\"150\" " +
                "src=\"../js/canvas-nest.js\"></script>" +
                "</body>\n" +
                "</html>";
    }

    public static String GetindexEnd() {
        return "</div>\n" +
                "</div>\n" +
                "<script type=\"text/javascript\" color=\"230,230,250\" opacity='0.7' zIndex=\"-1\" count=\"150\" " +
                "src=\"../js/canvas-nest.js\"></script>" +
                "</body>\n" +
                "\"<script src=\"../js/browspy-browspy.js\"></script>\\n\"" +
                "</html>";
    }
}