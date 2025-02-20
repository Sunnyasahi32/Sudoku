#Makefile

# makefile for xxx

#### 頻繁に変更が必要なもの（複数人での開発用）
# 関数ごとにファイルを作り、作ったファイル.oをここに記述

#### 実装の関数群のオブジェクトファイル名 \ を書くと次の行も継続できる
# OBJECTS_A = instruction.o add_a_im.o \
#                   mov_a_im.o \
#                   in b bin2int.o \
#                   led2str.o

OBJECTS=$(OBJECTS_A) $(OBJECTS_B) $(OBJECT_C)
OBJECTS_A= creatBoard.o GenerateQ.o GenerateA.o 
OBJECTS_B= getUserInput.o drawboard.o isAllClear.o
OBJECTS_C= 

#### テストの関数群のオブジェクトファイル名 \ を書くと次の行も継続できる
TEST_OBJECTS=$(TEST_OBJECTS_A) $(TEST_OBJECTS_B) $(TEST_OBJECTS_C)
TEST_OBJECTS_A= testGenerateQ.o
TEST_OBJECTS_B= testCreateBoard.o 
TEST_OBJECTS_C= #testGenerateA.o 

# 最終実行ファイル(名前を修正したら .gitignore も修正すること)
TARGET=xxx

# テスト実行ファイル(名前を修正したら .gitignore も修正すること)
TEST_TARGET=testXxx


# curses / ncurses を使うか (どちらかを残す)
CURSES=on
#CURSES=off

#### 以下は変更する必要がないもの

# 最終実行ファイルの実名
TARGET_EXE=$(TARGET)$(EXE)
# ターゲット実行ファイルの実名
TEST_TARGET_EXE=$(TEST_TARGET)$(EXE)
# 実装のためのヘッダー(プロトタイム宣言、構造体宣言、定数定義を含む)
HEADER=$(TARGET).h
# 実装のメインファイル main 関数を含む
MAIN=$(TARGET).o
# テストのためのヘッダー(プロトタイム宣言)
TEST_HEADER=$(TEST_TARGET).h
# テストのメインファイル main 関数を含む
TEST_MAIN=$(TEST_TARGET).o
# テストに必要なファイル
TEST_COMMON=testCommon.o
# 必要な CFLAGS
CFLAGS=-Wall -g
# 必要なライブラリ
LIBS=-lncurses -lm
CHCP=

ifeq ($(OS),Windows_NT)
	CC=gcc
	RM=cmd.exe /C del
	EXE=.exe
	CHCP=chcp 65001
else
	RM=rm -f
	EXE=
endif

ifeq ($(CURSES),on)
	ifeq ($(OS),Windows_NT)
		CURSES_LIBS=PDCurses-3.9/wincon/pdcurses.a
	else
		CURSES_LIBS=-lncurses -lm
	endif
endif

exec: $(TARGET_EXE)
	$(CHCP)
	./$(TARGET_EXE)
test: $(TEST_TARGET_EXE)
	$(CHCP)
	./$?

$(TARGET_EXE): $(MAIN) $(OBJECTS) $(HEADER)
	$(CC) -o $@ $(CFLAGS) $(MAIN) $(OBJECTS) $(CURSES_LIBS) $(LIBS)

$(TEST_TARGET_EXE): $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(TEST_COMMON) $(HEADER) $(TEST_HEADER)
	$(CC) -o $@ $(CFLAGS) $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(TEST_COMMON) $(LIBS)

clean:
	$(RM) $(TARGET_EXE) $(TEST_TARGET_EXE) $(MAIN) $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(CURSES_LIBS) $(TEST_COMMON)
