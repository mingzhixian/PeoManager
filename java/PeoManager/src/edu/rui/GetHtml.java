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
                "</head>\n" +
                "    <style>\n" +
                "        * {\n" +
                "            box-sizing: border-box;\n" +
                "        }\n" +
                "\n" +
                "        body {\n" +
                "            background-color: #181a1b;\n" +
                "        }\n" +
                "\n" +
                "        .site {\n" +
                "            width: 1000px;\n" +
                "            margin: 50px auto 80px auto;\n" +
                "            padding: 50px 0 50px 0;\n" +
                "            background-color: #35393b;\n" +
                "            border-radius: 40px;\n" +
                "            text-align: center;\n" +
                "        }\n" +
                "\n" +
                "        .mod {\n" +
                "            display: inline-block;\n" +
                "            width: 198px;\n" +
                "            height: 60px;\n" +
                "            border-radius: 16px;\n" +
                "            background-color: #527a7a;\n" +
                "            margin: auto;\n" +
                "            font-size: 36px;\n" +
                "            padding-top: 6px;\n" +
                "            color: aliceblue;\n" +
                "            text-decoration: none;\n" +
                "        }\n" +
                "\n" +
                "        form {\n" +
                "            margin: 40px auto auto;\n" +
                "            width: 720px;\n" +
                "            padding: 30px 0 30px 36px;\n" +
                "            background-color: dimgrey;\n" +
                "            border-radius: 28px;\n" +
                "        }\n" +
                "\n" +
                "        td {\n" +
                "            display: inline-block;\n" +
                "            font-size: 34px;\n" +
                "            padding-right: 16px;\n" +
                "            color: aliceblue;\n" +
                "        }\n" +
                "\n" +
                "        input {\n" +
                "            display: inline-block;\n" +
                "            width: 222px;\n" +
                "            height: 40px;\n" +
                "            border-radius: 10px;\n" +
                "            background-color: #181a1b;\n" +
                "            color: aliceblue;\n" +
                "        }\n" +
                "    </style>\n" +
                "    <script>\n" +
                "    function checkcodeupdate() {\n" +
                "        document.getElementById(\"checkcodepic\").src = \".././CheckCodeBack\" + '?' + new Date();\n" +
                "    }\n" +
                "    </script>" +
                "</head>\n" +
                "<body>\n" +
                "<div style=\"text-align: center;margin-top: 50px\">\n" +
                "    <h1 style=\"font-size: 50px\"><a href=\"Index\" style=\"color: aliceblue;text-decoration: " +
                "none\">" +
                set + "</a></h1>\n" +
                "</div>\n" +
                "<div class=\"site\">\n" +
                "    <a href=\"Add\" class=\"mod\"><img width=\"30px\" src=\"../img/添加用户.svg\">添加记录</a>\n" +
                "    <a href=\"Find\" class=\"mod\"><img width=\"30px\" src=\"../img/查找用户.svg\">搜索记录</a>\n" +
                "    <a href=\"All\" class=\"mod\"><img width=\"30px\" src=\"../img/所有用户.svg\">所有记录</a>\n" +
                "    <a href=\"Login\" class=\"mod\"><img width=\"30px\" src=\"../img/登录用户.svg\">后台登录</a>\n" +
                "    <div>\n";
    }

    public static String GetaddEnd() {
        return "</div>\n" +
                "</div>\n" +
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