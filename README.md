## chdns
*学校校园网不修改DNS无法更新下载软件，于是写了这个小脚本方便自己修改DNS*

  -  语法参考：
        - chdns \[dns 1\] \[dns 2\] 

  - 一些选项：
    - `-h` 帮助信息
    - `-google` 将dns修改为`8.8.8.8`和`8.8.4.4`
    - `-114dns` 将dns修改为`114.114.114.114`和`218.85.157.99`
    - `-show` 查看当前dns信息

## 注意
  - 修改的是NetworkManager创建的/etc/resolv.conf
  - 修改需要root权限，或者使用sudo， 不然会报块错误，不能写入

## 示例

<<<<<<< HEAD
```powershell
=======
```shell
>>>>>>> c9b30f5a2ed840508f9550fb76f28cf1e7882811
[arsia]$chdns -show
 Now file content(/etc/resolv.conf):
	#Change by chdns
	nameserver 8.8.8.8
	nameserver 8.8.4.4

[arsia]$sudo chdns -114dns
  Now file content(/etc/resolv.conf):
	#Change by chdns
	nameserver 8.8.8.8
	nameserver 8.8.4.4
	

  chdns: Do you want to change?(y or n):  
  
  chdns: Message( nameserver 114.114.114.114 nameserver 218.85.157.99)
  chdns: Succeccful!
```
