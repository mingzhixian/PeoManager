package edu.rui.text;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class main {
    @RequestMapping("/")
    public String one() {
        System.out.println("拦截");
        return "你好呀";
    }

    @RequestMapping("/404")
    public void error() {
        System.out.println("错误");
    }
}
