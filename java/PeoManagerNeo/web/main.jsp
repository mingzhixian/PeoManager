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
    <meta charset="UTF-8">
    <title>PeoManager</title>
    <link href="resource/img/manager.svg" rel="shortcut icon">
    <link href="resource/css/main.css" type="text/css" rel="stylesheet">
    <script src="resource/js/anime.min.js" rel="script"></script>
    <script>
        function checkcodeupdate() {
            document.getElementById("checkcodepic").src = ".././CheckCodeBack" + '?' + new Date();
        }
    </script>
</head>
<body>
<div style="text-align: center;margin-top: 50px">
    <h1 style="font-size: 50px"><a href="Index" style="color: aliceblue;text-decoration: none">后台登录</a></h1>
</div>
<div id="site">
    <a href="/" class="mod"><img width="30px" src="../img/添加用户.svg">添加记录</a>
    <a href="Find" class="mod"><img width="30px" src="../img/查找用户.svg">搜索记录</a>
    <a href="All" class="mod"><img width="30px" src="../img/所有用户.svg">所有记录</a>
    <a href="Login" class="mod"><img width="30px" src="../img/登录用户.svg">后台登录</a>
</div>
<script src="resource/js/animation.js" rel="script"></script>
<script type="text/javascript" color="230,230,250" opacity='0.7' zIndex="-1" count="150"
        src="resource/js/canvas-nest.js"></script>
</body>
</html>