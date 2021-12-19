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
    $.ajax({
        url: "./All?ele=" + now,
        method: "GET",
        dataType: "html"
    }).done(function (output) {
        domupdate(output);
    }).fail(function (xhr, status) {
        console.log(status);
    });
}

//回调函数
function domupdate(output) {
    var formmod = document.getElementById("formmod");
    var str = formmod.innerHTML;
    str = str + output;
    formmod.innerHTML = str;
}