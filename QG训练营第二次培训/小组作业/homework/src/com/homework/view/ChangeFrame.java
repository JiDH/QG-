package com.homework.view;

import com.homework.model.History;
import com.homework.model.Msg;
import com.homework.util.CheckEmpty;
import com.homework.util.ToWriteFile;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.io.File;
import java.util.List;


public class ChangeFrame extends JFrame {
    private ChangePanel changePanel = new ChangePanel();
    private SearchPanel searchPanel = new SearchPanel();

    public ChangeFrame() {
        //设置标题
        super("文件修改");
        //设置窗口尺寸
        setSize(512, 384);
        //setSize(2048,768);
        //设置居中
        setLocationRelativeTo(null);
        //窗体尺寸不可修改
        setResizable(false);
        //关闭窗体即结束进程
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().add(changePanel);
        changePanel.getBtn_search().addActionListener(this::actionSearch);
        changePanel.getBtn_change().addActionListener(this::actionChange);
        searchPanel.getBtn_return().addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setSize(512, 384);
                searchPanel.setVisible(false);
                changePanel.setVisible(true);
                setLocationRelativeTo(null);
            }
        });
        searchPanel.getBtn_exit().addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "退出成功", null, JOptionPane.INFORMATION_MESSAGE, null);
                System.exit(0);
            }
        });
    }

    public void actionSearch(ActionEvent e) {
        setSize(512, 768);
        setLocationRelativeTo(null);
        changePanel.setVisible(false);
        getContentPane().add(searchPanel);
        searchPanel.setVisible(true);
        String[] columnsName = {"路径", "修改内容", "行数", "修改时间"};
        Object[][] data;
        List<History> historyList;
        try {
            historyList = ToWriteFile.Find();
            //将list集合解析为JTable显示的数据模型
            int num = historyList.size();
            data = new Object[num][4];
            for (int i = 0; i < num; i++) {
                data[i][0] = historyList.get(i).getPath();
                data[i][1] = historyList.get(i).getHistory();
                data[i][2] = historyList.get(i).getNumber();
                data[i][3] = historyList.get(i).getDate();
            }
            searchPanel.setTable(new JTable(data, columnsName));
            searchPanel.table.setModel(new DefaultTableModel(data, columnsName));
            searchPanel.table.add(searchPanel.jScrollPane);
            searchPanel.add(searchPanel.jScrollPane);
            searchPanel.jScrollPane.setViewportView(searchPanel.table);
            searchPanel.jScrollPane.setVisible(true);
        } catch (Exception ec) {
            ec.printStackTrace();
        }
    }

    public void actionChange(ActionEvent e) {
        int line;
        String path = changePanel.getPath_text().getText();
        String message = changePanel.getMessage_text().getText();
        String lines = changePanel.getLine_text().getText();
        if (!CheckEmpty.isEmpty(path) || !CheckEmpty.isEmpty(message) || !CheckEmpty.isEmpty(lines)) {
            try {
                line = Integer.parseInt(lines);
                Msg msg = ToWriteFile.insertText(message, new File(path), line - 1, path);
                if (msg.isFlag()) {
                    JOptionPane.showMessageDialog(null, msg.getMessage(), null, JOptionPane.INFORMATION_MESSAGE, null);
                } else {
                    JOptionPane.showMessageDialog(null, msg.getMessage(), null, JOptionPane.ERROR_MESSAGE, null);
                }
            } catch (NumberFormatException ex) {
                ex.printStackTrace();
            }
            changePanel.getPath_text().setText("");
            changePanel.getLine_text().setText("");
            changePanel.getMessage_text().setText("");
        } else {
            JOptionPane.showMessageDialog(null, "不可留空", null, JOptionPane.ERROR_MESSAGE, null);
        }
    }

}
