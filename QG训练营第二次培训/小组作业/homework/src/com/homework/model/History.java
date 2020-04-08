package com.homework.model;

public class History {
    private int id;
    private String path;
    private String history;
    private int number;
    private String date;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public String getHistory() {
        return history;
    }

    public void setHistory(String history) {
        this.history = history;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public History(int id, String path, String history, int number, String date) {
        this.id = id;
        this.path = path;
        this.history = history;
        this.number = number;
        this.date = date;
    }
}
