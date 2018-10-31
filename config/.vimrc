" -- 缩进 & 制表符
" -使 Vim 在创建新行的时候使用与上一行同样的缩进
set autoindent

" -创建新行时使用智能缩进，主要用于 C 语言一类的程序。通常，打开 smartindent 时也应该打开 autoindent
set smartindent

" -设置文件里的制表符 (TAB) 的宽度(以空格的数量表示)
set tabstop=4

" -设置移位操作 >> 或 << 的缩进长度(以空格的数量表示)
set shiftwidth=4


" -- 显示 & 格式化
" -设置行号
set number

" -当光标遍历文件时经过括号时，高亮标识匹配的括号
set showmatch


" -- 搜索
" -高亮搜索内容的所有匹配位置
set hlsearch


" -- 浏览 & 滚动
" -在 Vim 窗口底部显示一个永久状态栏，可以显示文件名、行号和列号等内容
set laststatus=2


" -- 其他选项
" -Vim包含一个增强功能，使得即使在文件关闭后也可以维护撤消历史记录，这意味着即使在保存、关闭和重新打开文件后，也可以撤消之前的更改。历史记录文件是使用 .un~ 扩展名保存的隐藏文件。
set undofile
