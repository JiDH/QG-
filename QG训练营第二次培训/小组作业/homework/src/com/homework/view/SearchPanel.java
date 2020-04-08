package com.homework.view;

import javax.swing.*;
import java.awt.*;

public class SearchPanel extends JPanel {
    private JLabel lab_title = new JLabel("修改历史");
    public JScrollPane jScrollPane = new JScrollPane();
    public JTable table;
    private JButton btn_return = new JButton("返回");
    private JButton btn_exit = new JButton("退出");

    public SearchPanel(){
        super();
        setLayout(null);
        setBackground(Color.lightGray);
        init();
        add(lab_title);
        add(jScrollPane);
        add(btn_return);
        add(btn_exit);
        jScrollPane.setVisible(true);
    }

    private void init() {
        lab_title.setSize(425, 150);
        lab_title.setFont(new Font("", 0, 25));
        lab_title.setLocation(208, -30);
        jScrollPane.setViewportView(table);
        jScrollPane.setBounds(8, 90, 492, 550);
        btn_return.setBounds(280,680,80,40);
        btn_exit.setBounds(150,680,80,40);
    }

    public void setTable(JTable table) {
        this.table = table;
    }

    public JButton getBtn_return() {
        return btn_return;
    }

    public JButton getBtn_exit() {
        return btn_exit;
    }
}
