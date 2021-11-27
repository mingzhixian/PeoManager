package edu.rui;

public class Count {
    private String name;
    private String password;

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

    @Override
    public String toString() {
        return "Peo{" +
                "name='" + name + '\'' +
                ", id='" + password + '\'' +
                '}';
    }
}
