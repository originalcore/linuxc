# BASE64

## 原理

- 标准base64只有64个字符(英文大小写、数字和+、/)以及用作后缀等号

- base64是把3个字节变成4个可打印字符,所以base64编码后的字符串一定能被4整除(不算用作后缀的等号)

- 等号一定用作后缀,且数目一定是0个,1个或2个.这是因为如果原文长度不能被3整除,base64要在后面添加\0凑齐3n位.为了正确还原,添加了几个\0就加上几个等号.显然添加等号的数目只能是0,1或2

- 严格来说base64不能算是一种加密,只能说是编码转换.使用base64的初衷是为了方便把含有不可见字符串的信息用可见字符串表示出来,以便复制粘贴