#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//��ϵģ�͵Ļ�������
// �����������
// �ĸ���ϲ���
// ���������桢�ѿ�����
// ѡ��ͶӰ�����ӡ���
// 
//SQL��������
//SQL���
// ���ݵĶ���
// ģʽ��CREAT SCHEAM <ģʽ��>;
// ��
// CREAT TABLE <����>
// (
//  <������> <����> [<������Լ��>],
//	<������> <����> [<������Լ��>],
//  ����,
//  [<������Լ��>],
//	[PRIMARY KEY (<������>[,<������>])],
//  [FOREIGN KEY (<������>) REFERENCES <����>(<������>)],
// );
// 
// ALTER TABLE <����>
// [ADD <������> <����>];
// [MODIFY <������> <����>];
// [DROP <������> [CASCADE | RESTRIC]];
// [ADD <������Լ��>];
// 
// CERAT [UNIQUE] INDEX <������> ON <����>(<������>);
// 
// ��ѯ
// SELECT �������ѯ���
// FROM ������Դ
// WHERE ɸѡ���� ����AND | OR | NO | IN
// ORDER BY ������򣨿�ֵ����ͷ������ASC����|DESC����
// 
// �ۺϺ���
// COUNT ����
// 
// GROUP BY �ȶԱ��־ַ��飨������WHEREͬʱʹ�ã�
// HAVING ɸѡ��GROUP BYʱ������WHERE��
// 
//
//