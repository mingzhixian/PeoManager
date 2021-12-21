var now = 0;

window.onscroll = function () {
    var scrollTop = document.body.scrollTop;
    var scrollHeight = document.documentElement.scrollHeight;
    var windowsHeight = window.innerHeight;
    if (scrollHeight - scrollTop - windowsHeight < 80) {
        requesthtml();
    }
}

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
    var formmod = document.getElementById("formmod");
    var str = formmod.innerHTML;
    str = str + output;
    formmod.innerHTML = str;
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