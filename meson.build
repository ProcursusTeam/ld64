project('ld64', ['cpp', 'c'],
  version : '711',
  default_options : ['warning_level=3',
                     'cpp_std=gnu++17'])

archs = get_option('supported-archs')

srcs = []
unwinddumpsrcs = []
incdirs = []
subdir('src')
subdir('doc')
subdir('EXTERNAL_HEADERS')

srcs += custom_target(
  'compile_stubs.h',
  output : 'compile_stubs.h',
  input : 'compile_stubs',
  command : [find_program('src/custom/create_header.sh'), '@INPUT@', '@OUTPUT@', 'compile_stubs'])

llvm = dependency('llvm', modules : ['lto'])
blocks = dependency('blocks')

libs = ['-lxar', '-ltapi']
deps = [llvm.partial_dependency(includes : true, compile_args : true), blocks]

if host_machine.system() != 'darwin'
  openssl = dependency('openssl')
  deps += openssl # For corecrypto and CommonCrypto compat
endif

if host_machine.system() == 'freebsd'
  libs += '-lexecinfo' # For backtrace()
endif

ld64 = executable(get_option('program-prefix') + 'ld64', srcs,
  include_directories : incdirs,
  link_args: libs,
  dependencies: deps,
  install : true)

install_symlink(get_option('program-prefix') + 'ld', pointing_to : get_option('program-prefix') + 'ld64', install_dir : get_option('bindir'))

unwinddump = executable(get_option('program-prefix') + 'unwinddump', unwinddumpsrcs,
  include_directories : incdirs,
  install : true)
