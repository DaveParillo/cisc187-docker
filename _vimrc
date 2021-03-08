" uncomment if vim-pathogen installed
" see https://github.com/tpope/vim-pathogen
" execute pathogen#infect()

" other plugin URLS:
" https://github.com/tpope/vim-commentary
" https://github.com/tpope/vim-fugitive
" https://github.com/vhdirk/vim-cmake

if has('autocmd')
  filetype plugin indent on
endif
if has('syntax') && !exists('g:syntax_on')
  syntax enable
endif

set nocompatible

set nobackup
set tabstop=2
set shiftwidth=2
set expandtab
set autoindent
set backspace=indent,eol,start
set complete-=i
set smarttab

set nrformats-=octal

set autowrite            " Write the file if I navigate to a different buffer
set autoread             " Reload the file if it changes outside of vim
set autochdir            " Change directory to the current buffer when opening files.

" a workable colorscheme for buffy inside git bash
colorscheme slate

" Override the name of the base colorscheme with the name of this custom one
" let g:colors_name = "wheat"
" hi clear Comment
" hi Comment ctermfg=187 

" ease running cmake CTest from a src directory
function! s:CTest(stepNum)
  execute '!cd ../build; test/step'. a:stepNum
endfunction

command! -nargs=1 Test call s:CTest(<f-args>)
command Steps :!cd ../build; /bin/ls -1 test/step*

" Change default comment string for Commentary plugin
autocmd FileType c,cpp,cs,java setlocal commentstring=//\ %s
autocmd FileType cmake setlocal commentstring=\#\ %s

:let mapleader = " "

" show an indicator if over 80 columns wide
highlight ColorColumn ctermbg=magenta
call matchadd('ColorColumn', '\%81v', 100)

" disable arrow keys: pedantic
" noremap <Up>    <Nop>
" noremap <Down>  <Nop>
" noremap <Left>  <Nop>
" noremap <Right> <Nop>

set laststatus=2
set ruler
set wildmenu

if !&scrolloff
  set scrolloff=1
endif
if !&sidescrolloff
  set sidescrolloff=5
endif
set display+=lastline

if &listchars ==# 'eol:$'
  set listchars=tab:>\ ,trail:-,extends:>,precedes:<,nbsp:+
endif

if v:version > 703 || v:version == 703 && has("patch541")
  " Delete comment character when joining commented lines
  set formatoptions+=j
endif

if has('path_extra')
  setglobal tags-=./tags tags-=./tags; tags^=./tags;
endif

if &history < 1000
  set history=1000
endif
if &tabpagemax < 50
  set tabpagemax=50
endif
if !empty(&viminfo)
  set viminfo^=!
endif
set sessionoptions-=options
set viewoptions-=options

" Allow color schemes to do bright colors without forcing bold.
if &t_Co == 8 && $TERM !~# '^linux\|^Eterm'
  set t_Co=16
endif

" Load matchit.vim, but only if the user hasn't installed a newer version.
if !exists('g:loaded_matchit') && findfile('plugin/matchit.vim', &rtp) ==# ''
  runtime! macros/matchit.vim
endif


" resize split windows by a % of current size
nnoremap <silent> <Leader>= :exe "resize " . (winheight(0) * 3/2)<CR>
nnoremap <silent> <Leader>- :exe "resize " . (winheight(0) * 2/3)<CR>
nnoremap <silent> <Leader>. :exe "vertical resize " . (winwidth(0) * 3/2)<CR>
nnoremap <silent> <Leader>, :exe "vertical resize " . (winwidth(0) * 2/3)<CR>
" move between splits
nnoremap <Leader>h <C-w>h
nnoremap <Leader>j <C-w>j
nnoremap <Leader>k <C-w>k
nnoremap <Leader>l <C-w>l
nnoremap <Leader>= <C-w>=

" netrw preferences
let g:netrw_liststyle = 3          " tree style

let g:netrw_browse_split = 4       " Open selected file in previous window
let g:netrw_preview = 1            " split vertically
let g:netrw_altv = 1               " file with :vsplit to the right of the browser.

" prefer vertical orientation when using :diffsplit
set diffopt+=vertical
" started In Diff-Mode set diffexpr (plugin not loaded yet)
if &diff
  let &diffexpr='EnhancedDiff#Diff("git diff", "--diff-algorithm=patience")'
endif

" clang-format integration
" map <C-K>f :pyf /var2/lopt/llvm/tools/clang/tools/clang-format/clang-format.py<cr>
" imap <C-K>f :pyf /var2/lopt/llvm/tools/clang/tools/clang-format/clang-format.py<cr>

" vim:set ft=vim et sw=2:


