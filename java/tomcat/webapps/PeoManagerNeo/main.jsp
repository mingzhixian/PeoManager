<%--
  Created by IntelliJ IDEA.
  User: kic
  Date: 2021/12/19
  Time: 下午3:49
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>PeoManagerNeo</title>
    <link href="resource/img/manager.svg" rel="shortcut icon">
    <link href="resource/css/main.css" rel="stylesheet">
    <script src="resource/js/anime.min.js"></script>
</head>
<body>
<div class="mod">
    <div id="mainhead">
        <div id="mianheadleft">
            ${mianheadleft}
            <img id="mianheadright" src="resource/img/登出.svg">
        </div>
    </div>
    <div id="mainbody">
        <div class="opentionmod">查看所有</div>
        <div class="opentionmod">搜索学生</div>
        <br>
        <div class="opentionmod">录入成绩</div>
        <div class="opentionmod">录入学生</div>
    </div>
</div>
</body>
<script src="resource/js/animation.js" rel=\"script\"></script>
</html>
