# getopt函数的使用

![command_line_componets](./command_line_componets.png)

```shell
optstring a:bc:d::e
-b -e 不接参数(右边没有分隔符)
-d 可接,也可以不接,参数不保存存在optarg中(左右两边都有分隔符)
-a -c 必须要接参数,参数保存在optarg中(右边有分隔符)

比较下面三个结果知道可选参数-d和不接参数-b,-e的区别
./a.out -bed
./a.out -dbe be作为里-d的参数
./a.out -deb be作为里-d的参数
```
