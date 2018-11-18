"""""""""""""""""""""""""""""""""""""""
"      Skycoop Vim Base Settings      "
"""""""""""""""""""""""""""""""""""""""

set autoindent    " -使 Vim 在创建新行的时候使用与上一行同样的缩进
set smartindent   " -创建新行时使用智能缩进
set tabstop=4     " -设置文件里的制表符 (TAB) 的宽度(以空格的数量表示)
set shiftwidth=4  " -设置移位操作 >> 或 << 的缩进长度(以空格的数量表示)
set number        " -设置行号
syntax on         " 语法高亮
set cursorline    " 突出显示当前行
set ruler         "右下角显示光标位置的状态行
set hlsearch      " -高亮搜索内容的所有匹配位置
set laststatus=2  " -在 Vim 窗口底部显示一个永久状态栏，可以显示文件名、行号和列号等内容
set undofile      " -Vim包含一个增强功能，使得即使在文件关闭后也可以维护撤消历史记录，这意味着即使在保存、关闭和重新打开文件后，也可以撤消之前的更改。历史记录文件是使用 .un~ 扩展名保存的隐藏文件。
set mouse=a       " 打开鼠标功能
set fdm=marker    " 关闭vim折叠信息不会丢失
set nocompatible                " Enables us Vim specific features
set encoding=utf-8              " Set default encoding to UTF-8
set autoread                    " Automatically read changed files
set ttyfast                     " Indicate fast terminal conn for faster redraw
set ttymouse=xterm2             " Indicate terminal type for mouse codes
set ttyscroll=3                 " Speedup scrolling
set autoread                    " Automatically read changed files
set backspace=indent,eol,start  " Makes backspace key more powerful
set incsearch                   " Shows the match while typing
set noerrorbells                " No beeps
set showcmd                     " Show me what I'm typing
set noswapfile                  " Don't use swapfile
set nobackup                    " Don't create annoying backup files
set splitright                  " Vertical windows should be split to right
set splitbelow                  " Horizontal windows should split to bottom
set autowrite                   " Automatically save before :next, :make etc.
set fileformats=unix,dos,mac    " Prefer Unix over Windows over OS 9 formats
set noshowmatch                 " Do not show matching brackets by flickering
set ignorecase                  " Search case insensitive...
set smartcase                   " ... but not it begins with upper case
set completeopt=longest,menu    "让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)


""""""""""""""""""""""
" hotkey Settings
""""""""""""""""""""""

set pastetoggle=<F2> " 按F2 进入粘贴模式

""""""""""""""""""""""
" fuction
""""""""""""""""""""""
if version >= 603
    set helplang=cn
    set encoding=utf-8
endif

