package edu.swu.rui;

public class GetHtml {
    public static String GetHead() {
        return "<html>\n" +
                "<head>\n" +
                "    <meta charset=\"UTF-8\">\n" +
                "    <title>web2</title>\n" +
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
                "    <title>web2</title>\n" +
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
                "            margin: 50px auto auto auto;\n" +
                "            padding: 50px 0 50px 0;\n" +
                "            background-color: #35393b;\n" +
                "            border-radius: 40px;\n" +
                "            text-align: center;\n" +
                "        }\n" +
                "\n" +
                "        .mod {\n" +
                "            display: inline-block;\n" +
                "            width: 180px;\n" +
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
                "            height: 38px;\n" +
                "            border-radius: 4px;\n" +
                "            background-color: #181a1b;\n" +
                "            color: aliceblue;\n" +
                "        }\n" +
                "    </style>\n" +
                "</head>\n" +
                "<body>\n" +
                "<div style=\"text-align: center;margin-top: 50px\">\n" +
                "    <h1 style=\"font-size: 50px\"><a href=\"Index\" style=\"color: aliceblue;;text-decoration: " +
                "none\">" +
                set + "</a></h1>\n" +
                "</div>\n" +
                "<div class=\"site\">\n" +
                "    <a href=\"Add\" class=\"mod\">添加记录</a>\n" +
                "    <a href=\"Find\" class=\"mod\">搜索记录</a>\n" +
                "    <a href=\"All\" class=\"mod\">所有记录</a>\n" +
                "    <a href=\"Login\" class=\"mod\">后台登录</a>\n" +
                "    <div>\n";
    }

    public static String GetaddEnd() {
        return "</div>\n" +
                "</div>\n" +
                "</body>\n" +
                "</html>";
    }
}