var converter = new showdown.Converter({ tables: true });
var DirTop = 0;  //目录是否进入悬停状态
var ArtUrl = null;
var ComUrl = null;
//服务器后台地址
var CloudUrl = "http://150.158.81.132/Ablog/GetMd?ArtName=";

//从链接获取文章名
function getvl(key) {
    var reg = new RegExp("(^|&)" + key + "=([^&]*)(&|$)");
    var result = window.location.search.substr(1).match(reg);
    return result ? decodeURIComponent(result[2]) : null;
}

//初始化获取Url
function getUrl()
{
    var tilte=getvl("article");
    ArtUrl=CloudUrl+tilte+"&&Url=ArtUrl";
    ComUrl=CloudUrl+tilte+"&&Url=ComUrl";
    document.getElementById("Title").innerHTML=tilte;
}

//获取文章与评论
window.onload = function () {
    getUrl();
    $.ajax({
        url: ArtUrl,
        type: "get",
        dataType: "html"
    }).done(function (output) {
        ShowDown(output,"article");
    }).fail(function (xhr, status) {
        console.log(status);
    });
    $.ajax({
        url: ComUrl,
        type: "get",
        dataType: "html"
    }).done(function (output) {
        ShowDown(output,"comment");
    }).fail(function (xhr, status) {
        console.log(status);
    });
}

//解析md文件并展示
function ShowDown(output,dom) {
    var html = converter.makeHtml(output);
    document.getElementById(dom).innerHTML = html;
}

//检测目录是否到达顶部
function IsTop() {
    var scrollTop = document.body.scrollTop;
    var art = document.getElementById("article");
    var dir = document.getElementById("directory");
    if (art.getBoundingClientRect().top < 20 && DirTop === 0) {
        dir.style.position = "fixed";
        dir.style.top = "50px";
        DirTop = 1;
    }
    if (art.getBoundingClientRect().top > 20 && DirTop === 1) {
        dir.style.position = "relative";
        dir.style.top = "0";
        dir.style.right = "0";
        DirTop = 0;
    }
}

//使用 rAF（requestAnimationFrame）触发滚动事件
var ticking = false; // rAF 触发锁

//滚动监听
function onScroll() {
    if (!ticking) {
        requestAnimationFrame(realFun);
        ticking = true;
    }
}

function realFun() {
    IsTop();
    ticking = false;
}

// 滚动事件监听
window.addEventListener('scroll', onScroll, false);
