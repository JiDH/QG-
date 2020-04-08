/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50515
Source Host           : localhost:3306
Source Database       : file_history

Target Server Type    : MYSQL
Target Server Version : 50515
File Encoding         : 65001

Date: 2020-04-08 21:26:00
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for history
-- ----------------------------
DROP TABLE IF EXISTS `history`;
CREATE TABLE `history` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `path` varchar(255) DEFAULT NULL,
  `history` varchar(255) DEFAULT NULL,
  `line_number` int(12) DEFAULT NULL,
  `date` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of history
-- ----------------------------
INSERT INTO `history` VALUES ('1', './hello/a.txt', 'azzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz', '14', '2020-04-08 20:24:08');
INSERT INTO `history` VALUES ('2', './hello/a.txt', '1212', '360', '2020-04-08 21:09:01');
INSERT INTO `history` VALUES ('3', './hello/a.txt', '1231', '360', '2020-04-08 21:11:34');
INSERT INTO `history` VALUES ('4', './hello/a.txt', '121521嗄1', '360', '2020-04-08 21:11:52');
INSERT INTO `history` VALUES ('5', './hello/a.txt', '1阿是的5啊到发吖是vfe并前给(⊙﹏⊙)', '364', '2020-04-08 21:19:23');
