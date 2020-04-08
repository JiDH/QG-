# 纪铎浩第二次小组作业



​		实现检测某目录是否存在文件，若不存在则创建包括多级目录的文件，若存在则更新指定行的内容，同时提供查询历史修改的选项，servlet实现文件下载由于未学，暂时没有完成。



---

### 文件说明

| 文件(夹)名                 | 文件说明           |
| -------------------------- | ------------------ |
| lib                        | 存放jar包          |
| src                        | 存放源码           |
| out                        | 编译后文件         |
| ReadMe                     | 说明文档           |
| file_history.sql           | 数据库文件         |
| src\com\homework\Main.java | 实现可视化主类     |
| src\com\homework\WriteFile | 黑框实现类         |
| src\com\homework\model     | 存放实体类         |
| src\com\homework\view      | 存放可视化相关源码 |
| src\com\homework\util      | 存放工具类源码     |

***

### 使用说明

##### 可视化

+ 导入数据库file_history
+ 在src\com\homework\util\DButil.java中将用户名和密码改为自己的用户名密码。
+ 运行Main.java

##### 黑框框

+ 运行WriteFile.java

##### 测试说明

根目录下的test.txt文件，已提前设置了1-1000的行号，相对路径为.\test.txt

---

### 程序漏洞

+ 文件不可过大
+ 切换至历史查看页面时会卡顿
+ 文件路径不可包含半角字符，当包含半角字符时不会新建文件也不会打开文件，但也不报错

----

### 存在问题

1. 没有解决半角字符问题。
2. 因为着急，分包不够规范。
3. 代码不够精简，且缺少注释。
