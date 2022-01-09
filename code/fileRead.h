#ifndef FILEREAD_H
#define FILEREAD_H
//文件的绝对路径最大长度 
#define LEN  40
//读取以用户账号为名的txt文件 返回1表示读取成功,0表示失败 
//传入用户结构体 
int readFile(USER *user);

#endif
