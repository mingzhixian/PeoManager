<%--
  Created by IntelliJ IDEA.
  User: kic
  Date: 2021/12/20
  Time: 下午4:19
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
            document.getElementById("checkcodepic").src = "./CheckCodeBack" + '?' + new Date();
        }
    </script>
</head>
<body>
<div id="tiltediv">
    <h1 class="tilte"><a href="main.jsp" style="color: aliceblue;text-decoration: none">人员管理</a></h1>
</div>
<div id="site">
    <a onclick="add()" class="mod"><img width="30px" src="resource/img/添加用户.svg">添加记录</a>
    <a onclick="find()" class="mod"><img width="30px" src="resource/img/查找用户.svg">搜索记录</a>
    <a onclick="all()" class="mod"><img width="30px" src="resource/img/所有用户.svg">所有记录</a>
    <a onclick="login()" class="mod"><img width="30px" src="resource/img/登录用户.svg">后台登录</a>
    <div id="formmod">
    </div>
</div>
<script src="https://cdn.bootcdn.net/ajax/libs/jquery/3.6.0/jquery.js"></script>
<script src="resource/js/animation.js" rel="script"></script>
<script src="resource/js/Asynchronous.js" rel="script"></script>
<script type="text/javascript" color="230,230,250" opacity='0.7' zIndex="-1" count="150"
        src="resource/js/canvas-nest.js"></script>
</body>
</html>
