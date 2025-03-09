# 
# Makefile
# 

# 编译器
CC				= gcc
CXX				= g++
STRIP			= strip

# 编译选项
CFLAG			= -O -fsanitize=address
CXXFLAG			= -O -std=c++11 -fsanitize=address
LDFLAG			= -lm -fsanitize=address

# 产物及产物路径
BIN				= app
BUILD_DIR		= ./build
BUILD_OBJ_DIR	= $(BUILD_DIR)/obj
BUILD_BIN_DIR	= $(BUILD_DIR)/bin

# 源文件
MSRC			+= ./app/src/main.cpp
# ASRCS
CXXSRCS			+= ./components/string/src/myString.cpp
CXXSRCS			+= ./components/inherit/src/inherit.cpp
CXXSRCS			+= ./components/singleton/src/singleton.cpp

# 头文件路径
CFLAG			+= -I./app/inc
CXXFLAG			+= -I./app/inc
CXXFLAG			+= -I./components/string/inc
CXXFLAG			+= -I./components/template/inc
CXXFLAG			+= -I./components/inherit/inc
CXXFLAG			+= -I./components/singleton/inc
CXXFLAG			+= -I./components/decorator/inc

# 第三方软件
# include ./lvgl/lvgl.mk
# LDFLAG			+=

# 产物处理
OBJTEXT			= .o
AOBJS			= $(ASRCS:.S=$(OBJTEXT))
COBJS			= $(CSRCS:.c=$(OBJTEXT))
CXXOBJS			= $(CXXSRCS:.cpp=$(OBJTEXT))
MOBJS			= $(MSRC:.cpp=$(OBJTEXT))

SRCS			= $(ASRCS) $(CSRCS) $(CXXSRCS) $(MSRC)
OBJS			= $(AOBJS) $(COBJS) $(CXXOBJS) $(MOBJS)
TARGET			= $(addprefix $(BUILD_OBJ_DIR)/, $(patsubst ./%, %, $(OBJS)))

# 产物生成关系
al:default

$(BUILD_OBJ_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@
	@echo "CC $<"

$(BUILD_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@
	@echo "CC $<"

$(BUILD_OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAG) -c $< -o $@
	@echo "CXX $<"

default: $(TARGET)
	@mkdir -p $(BUILD_BIN_DIR)
	@$(CXX) -o $(BUILD_BIN_DIR)/$(BIN) $(TARGET) $(LDFLAG)
	@$(STRIP) --strip-debug $(BUILD_BIN_DIR)/$(BIN)

clean:
	rm -rf $(BUILD_DIR) $(BUILD_BIN_DIR)$(BIN)

print:
	@echo "--------------------"
	@echo $(CSRCS)
	@echo "--------------------"
	@echo $(CXXSRCS)
	@echo "--------------------"
	@echo $(TARGET)
	@echo "--------------------"
	@echo $(BUILD_OBJ_DIR)