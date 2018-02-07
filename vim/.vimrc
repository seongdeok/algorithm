syntax on
set ts=4
set nu
set hlsearch
set nocompatible
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set paste
"colorscheme molokai
set t_Co=256
let g:molokai_original = 1
set autoindent
set cindent
set smartindent
set ignorecase
set backspace=eol,start,indent
set showmatch
filetype off

set rtp+=~/.vim/bundle/vundle/

call vundle#rc()
Bundle 'gmarik/vundle'
Bundle 'git://git.wincent.com/command-t.git'

filetype plugin indent on
call vundle#begin()
Plugin 'The-NERD-Tree'
Plugin 'AutoComplPop'
Plugin 'taglist-plus'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/syntastic'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'airblade/vim-gitgutter'
call vundle#end()

let g:airline#extensions#tabline#enabled = 1 " turn on buffer list
let g:airline_theme='hybrid'
set laststatus=2 " turn on bottom bar

let g:NERDTreeDirArrows=0
map <F2> :NERDTreeToggle<CR>

nmap <F3> <c-]>
nmap <F4> <c-t>
nmap <c-d> <dd>
noremap <TAB> <C-W>w


set csprg=/usr/bin/cscope
set csto=0
set cst
set nocsverb
if filereadable("./cscope.out")
	cs add cscope.out
else
	cs add /home/seongdeok.han/develop/Reprogram_UnitTest/0501/cscope.out
endif
set csverb



