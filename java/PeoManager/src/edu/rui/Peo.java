package edu.rui;

public class Peo {
    private String name;
    private String id;
    private String filPath;

    public String getFilPath() {
        return filPath;
    }

    public void setFilPath(String filPath) {
        this.filPath = filPath;
    }

    public Peo(String name, String id, String filPath) {
        this.name = name;
        this.id = id;
        this.filPath = filPath;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return "Peo{" +
                "name='" + name + '\'' +
                ", id='" + id + '\'' +
                '}';
    }
}
