var now = 0;
var over = 0;

//新的scroll检测方法
//防抖函数
var timeout = null;

function antishake() {
    if (timeout !== null) clearTimeout(timeout);
    if (!over) {
        timeout = setTimeout(requesthtml, 300);
    } else {
        window.removeEventListener('scroll', onScroll);
    }
}

//检测是否到达底部
function IsBottom() {
    var scrollTop = document.body.scrollTop;
    var scrollHeight = document.documentElement.scrollHeight;
    var windowsHeight = window.innerHeight;
    if (scrollHeight - scrollTop - windowsHeight < 60) {
        antishake();
    }
}

//使用 rAF（requestAnimationFrame）触发滚动事件
var ticking = false; // rAF 触发锁

function onScroll() {
    if (!ticking) {
        requestAnimationFrame(realFun);
        ticking = true;
    }
}

function realFun() {
    IsBottom();
    ticking = false;
}

// 滚动事件监听
window.addEventListener('scroll', onScroll, false);

function requesthtml() {
    now += 10;
    if (GetUrlRelativePath() === "/PeoManager/web/Find") {
        var name = document.getElementById("findname").innerHTML;
        var id = document.getElementById("findid").innerHTML;
        $.ajax({
            url: "./Find",
            type: "post",
            data: {"name": name, "id": id, "ele": now},
            dataType: "html"
        }).done(function (output) {
            domupdate(output);
        }).fail(function (xhr, status) {
            console.log(status);
        });
    } else {
        $.ajax({
            url: "./All?ele=" + now,
            type: "get",
            dataType: "html"
        }).done(function (output) {
            domupdate(output);
        }).fail(function (xhr, status) {
            console.log(status);
        });
    }
}

//回调函数
function domupdate(output) {
    if (output === "") {
        over = 1;
    } else {
        var formmod = document.getElementById("formmod");
        var str = formmod.innerHTML;
        str = str + output;
        formmod.innerHTML = str;
    }
}

function GetUrlRelativePath() {
    var url = document.location.toString();
    var arrUrl = url.split("//");

    var start = arrUrl[1].indexOf("/");
    var relUrl = arrUrl[1].substring(start);//stop省略，截取从start开始到结尾的所有字符

    if (relUrl.indexOf("?") !== -1) {
        relUrl = relUrl.split("?")[0];
    }
    return relUrl;
}