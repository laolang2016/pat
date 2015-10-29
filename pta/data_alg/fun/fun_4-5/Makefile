# 默认的可执行文件的名字
PROGRAM=
program=

# 判断是否指定可执行程序的名称
ifdef name
PROGRAM=${name}
else
PROGRAM+=hello
endif

program=$(strip ${PROGRAM})

# C编译器
CC=gcc

# C编译选项
CFLAGS=-Wall

LIBS=

# 删除命令
RM=rm -rf

# 源文件列表
srcs=$(wildcard *.c)

# .o文件列表
objs=$(patsubst %.c,%.o,${srcs})

# 默认的目标，生成可执行程序
all:${program}

${program}:${objs}
	${CC} -o $@ ${LIBS} $^

.PHONY:exec clean rebuild list mytest
# 执行
exec:${program}
	./${program}
# 清理
clean:
	-${RM} ${objs}
	-${RM} ${program}
# 重新编译
rebuild:clean ${program}

# 输出源文件列表，.o文件列表，以及可执行程序的名称
list:
	@echo ${srcs}
	@echo ${objs}
	@echo ${program}
mytest:
	@echo ${message}
	@echo ${LIBS}
