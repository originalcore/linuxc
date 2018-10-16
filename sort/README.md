# 排序算法

参考:GNU/Linux Application Programming

## 使用GCOV

编译时配置如下选项

	test-coverage
	profile-arcs

编译后将生成.gcno文件

	bubble_sort.gcno

正常运行应用程序后会生成.gcda文件

	./bubbleSort
	bubble_sort.gcda

执行gcov(可以带-b选项)生成.gcov文件

	gcov [-b] bubble_sort.c
	bubble_sort.c.gcov
