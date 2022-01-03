package edu.rui;

public class Count {
    private String name;
    private String password;
    private int admin = 0;

    public Count(String name, String password, int admin) {
        this.name = name;
        this.password = password;
        this.admin = admin;
    }

    public Count(String name, String password) {
        this.name = name;
        this.password = password;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getAdmin() {
        return admin;
    }

    public void setAdmin(int admin) {
        this.admin = admin;
    }
}
