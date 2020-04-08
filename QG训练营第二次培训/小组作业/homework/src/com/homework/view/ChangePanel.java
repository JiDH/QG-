package com.homework.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class ChangePanel extends JPanel {

    private JLabel lab_title = new JLabel("文件修改");
    private JLabel lab_path = new JLabel("文件路径:");
    private JTextField path_text; //路径输入框
    private JLabel lab_message = new JLabel("修改内容:");
    private JTextField message_text; //内容输入框
    private JLabel lab_line = new JLabel("行数:");
    private JTextField line_text; //行数输入框
    private JButton btn_search = new JButton("历史");
    private JButton btn_change = new JButton("修改");


    public ChangePanel() {
        super();
        init();
        setBackground(Color.lightGray);
        add(lab_path);
        add(lab_message);
        add(path_text);
        add(message_text);
        add(btn_search);
        add(btn_change);
        add(lab_title);
        add(lab_line);
        add(line_text);
        setLayout(null);
    }

    private void init() {
        lab_title.setSize(425, 150);
        lab_title.setFont(new Font("", 0, 25));
        lab_title.setLocation(208, -30);
        lab_path.setSize(200, 100);
        lab_path.setLocation(110, 50);

        path_text = new JTextField();
        path_text.setSize(190, 30);
        path_text.setLocation(190, 85);

        lab_message.setSize(200, 100);
        lab_message.setLocation(110, 100);

        message_text = new JTextField();
        message_text.setSize(190, 30);
        message_text.setLocation(190, 135);

        lab_line.setSize(200, 100);
        lab_line.setLocation(125, 150);

        line_text = new JTextField();
        line_text.setSize(190, 30);
        line_text.setLocation(190, 185);

        btn_search.setSize(80, 40);
        btn_change.setLocation(280, 250);
        btn_change.setSize(80, 40);
        btn_search.setLocation(150, 250);

        line_text.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                String key = "0123456789" + (char) 8;
                if (key.indexOf(e.getKeyChar()) < 0) {
                    e.consume();

                }
            }
        });
    }

    public JTextField getPath_text() {
        return path_text;
    }

    public void setPath_text(JTextField path_text) {
        this.path_text = path_text;
    }

    public JTextField getMessage_text() {
        return message_text;
    }

    public void setMessage_text(JTextField message_text) {
        this.message_text = message_text;
    }

    public JTextField getLine_text() {
        return line_text;
    }

    public void setLine_text(JTextField line_text) {
        this.line_text = line_text;
    }

    public JButton getBtn_search() {
        return btn_search;
    }

    public void setBtn_search(JButton btn_search) {
        this.btn_search = btn_search;
    }

    public JButton getBtn_change() {
        return btn_change;
    }

    public void setBtn_change(JButton btn_change) {
        this.btn_change = btn_change;
    }

    public void keyTyped(KeyEvent e) {
        String key = "0123456789" + (char) 8;
        if (key.indexOf(e.getKeyChar()) < 0) {
            e.consume();
        }
    }
}
