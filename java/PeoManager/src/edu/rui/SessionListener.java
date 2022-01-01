package edu.rui;

import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

@WebListener
public class SessionListener implements HttpSessionListener {
    static int count = 0;

    @Override
    public synchronized void sessionCreated(HttpSessionEvent se) {
        //过期时间与登录cookie过期时间相同
        se.getSession().setMaxInactiveInterval(60 * 20);
        count++;
    }

    @Override
    public synchronized void sessionDestroyed(HttpSessionEvent se) {
        count--;
    }

    public static int getCount() {
        if (count < 1) {
            //防止运行出错，只是展示作用不追究错误来处
            count = 1;
        }
        return count;
    }
}
