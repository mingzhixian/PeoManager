var now = 0;

window.onscroll = function () {
    var scrollTop = document.body.scrollTop;
    var scrollHeight = document.documentElement.scrollHeight;
    var windowsHeight = window.innerHeight;
    if (scrollHeight - scrollTop - windowsHeight < 80) {
        now += 10;
        var url = "./All?ele=" + now;
        requesthtml(url, 1);
    }
}

function add() {
    var url = "./web/Add";
    requesthtml(url, 0);
}

function find() {
    var url = "./web/Find";
    requesthtml(url, 0);
}

function all() {
    var url = "./web/All";
    requesthtml(url, 0);
}

function update(id) {
    var url = "./web/Update?id=" + id;
    requesthtml(url, 0);
}

function login() {
    var url = "./web/Login";
    requesthtml(url, 0);
}

function loginpost() {
    var url = "./web/Login";
    var name = document.getElementsByName("name").values();
    var password = document.getElementsByName("id").values();
    requesthtmlpost2(url, 0, name, password);
}

function requesthtml(url, isadd) {
    $.ajax({
        url: url,
        type: "get",
        dataType: "html"
    }).done(function (output) {
        domupdate(output, isadd);
    }).fail(function (xhr, status) {
        console.log(status);
    });
}

function requesthtmlpost1(url, isadd, name, id) {
    $.ajax({
        url: url,
        type: "post",
        dataType: "html",
        data: {"name": name, "id": id},
    }).done(function (output) {
        domupdate(output, isadd);
    }).fail(function (xhr, status) {
        console.log(status);
    });
}

function requesthtmlpost2(url, isadd, name, password) {
    $.ajax({
        url: url,
        type: "post",
        dataType: "html",
        data: {"name": name, "password": password},
    }).done(function (output) {
        domupdate(output, isadd);
    }).fail(function (xhr, status) {
        console.log(status);
    });
}

//回调函数
function domupdate(output, isadd) {
    var formmod = document.getElementById("formmod");
    if (isadd === 1) {
        var str = formmod.innerHTML;
        output = str + output;
    }
    formmod.innerHTML = output;
}