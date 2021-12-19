package edu.rui;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class controller {

    @RequestMapping("/main.do")
    public ModelAndView index() {
        ModelAndView modelAndView = new ModelAndView("main.jsp");
        modelAndView.addObject("mianheadleft", "鸣之弦");
        return modelAndView;
    }

    @RequestMapping("/login.do")
    public ModelAndView login() {
        ModelAndView modelAndView = new ModelAndView();
        return modelAndView;
    }

    @RequestMapping("/checkcode.do")
    public void checkcode() {
    }
}
