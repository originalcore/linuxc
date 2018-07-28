shell adb forward tcp:4321 tcp:1234
target remote localhost:4321
set solib-absolute-prefix /androidsrc/out/target/product/rk3288/symbols
set solib-search-path /androidsrc/out/target/product/rk3288/symbols/system/lib
file /androidsrc/out/target/product/rk3288/system/xbin/astall
