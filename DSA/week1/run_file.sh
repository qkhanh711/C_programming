#!/usr/bin/env bash
# Cách dùng:  bash run.sh <source.c> [extra compiler flags]

set -e                          # dừng nếu có lỗi

if [ $# -lt 1 ]; then
    echo "Usage: $0 <source.c> [extra gcc flags]" >&2
    exit 1
fi

SRC="$1"                        # file nguồn
shift                           # bỏ tham số đầu, phần còn lại là FLAGS (nếu có)

if [[ ! -f "$SRC" ]]; then
    echo "File '$SRC' not found!" >&2
    exit 1
fi

BIN="${SRC%.c}"                 # tên nhị phân = tên file, bỏ .c
CC=gcc
CFLAGS="-std=c11 -Wall -Wextra -O2 $*"  # thêm FLAGS do người dùng nhập

echo "🔧 Compiling $SRC → $BIN"
$CC $CFLAGS "$SRC" -o "$BIN"

echo "�� Running ./$BIN"
./"$BIN"

