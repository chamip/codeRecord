#!/usr/bin/bash
:<<!
echo "Hello, world!"

# 变量和=之间不能有空格
myUrl="https://google.com"
echo ${myUrl}

# 只读变量不能修改，否则报错
#readonly myUrl
myUrl="https://baidu.com"
echo ${myUrl}

# 删除，不能删除只读变量
unset myUrl
echo "-----"
echo ${myUrl}
echo
echo "-----"

for skill in Ada Coffe Action Java; do
	echo "I am good at ${skill}Script"
done
!
# 获取字符串长度
string="abcdefg"
echo ${#string}
echo ${#string[0]}
