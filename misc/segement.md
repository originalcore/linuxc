# 段错误的产生流程

1. 用户程序要访问的一个虚拟地址,经MMU检查无权访问.
2. MMU产生一个异常,CPU从用户模式切换到特权模式,跳转到内核代码中执行异常服务程序.
3. 内核把这个异常解释为段错误,把引发异常的进程终止掉.