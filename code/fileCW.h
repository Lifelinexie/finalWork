#ifndef FILECREATE_H
#define FILECREATE_H
//文件的绝对路径最大长度 
#define LEN  40
//创建以用户账号为名的txt文件和写入数据到文件中,返回1表示成功,0表示失败 
//传入用户结构体 
int CWFile(USER *user);

#endif
