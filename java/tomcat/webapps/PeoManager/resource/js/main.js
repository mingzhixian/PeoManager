function formSubmit(formid, select) {
    var form = $("#" + formid); //得到form对象
    var name = document.getElementsByName("name");
    var id = document.getElementsByName("id");
    if (name[0].value === "") {
        alert("姓名不能为空");
    } else if (id[0].value === "") {
        alert("id不能为空");
    } else {
        var tmpInput1 = $("<input type='text' style='display: none' name='select' value='" + select + "'/>");
        var tmpInput2 = $("<input type='text' style='display: none' name='preid' value='" + formid + "'/>");
        form.append(tmpInput1);
        form.append(tmpInput2);
        form.submit();
    }
}