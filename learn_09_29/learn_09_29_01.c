#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//关系模型的基本概念
// 五个基本操作
// 四个组合操作
// 并、交、叉、笛卡尔积
// 选择、投影、连接、除
// 
//SQL基本概念
//SQL语句
// 数据的定义
// 模式：CREAT SCHEAM <模式名>;
// 表：
// CREAT TABLE <表名>
// (
//  <列名称> <类型> [<完整性约束>],
//	<列名称> <类型> [<完整性约束>],
//  ……,
//  [<完整性约束>],
//	[PRIMARY KEY (<列名称>[,<列名称>])],
//  [FOREIGN KEY (<列名称>) REFERENCES <表名>(<列名称>)],
// );
// 
// ALTER TABLE <表名>
// [ADD <列名称> <类型>];
// [MODIFY <列名称> <类型>];
// [DROP <列名称> [CASCADE | RESTRIC]];
// [ADD <完整性约束>];
// 
// CERAT [UNIQUE] INDEX <索引名> ON <表名>(<列名称>);
// 
// 查询
// SELECT 输出，查询结果
// FROM 数据来源
// WHERE 筛选条件 ——AND | OR | NO | IN
// ORDER BY 结果排序（空值跟大头）——ASC升序|DESC降序
// 
// 聚合函数
// COUNT 计数
// 
// GROUP BY 先对表格分局分组（不可与WHERE同时使用）
// HAVING 筛选（GROUP BY时，代替WHERE）
// 
//
//