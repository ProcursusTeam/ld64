project('ld64', ['cpp', 'c'],
  version : '711',
  default_options : ['warning_level=3',
                     'cpp_std=gnu++17'])

archs = get_option('supported-archs')

srcs = []
unwinddumpsrcs = []
incdirs = []
subdir('src')

srcs += custom_target(
  'compile_stubs.h',
  output : 'compile_stubs.h',
  input : 'compile_stubs',
  command : [find_program('src/custom/create_header.sh'), '@INPUT@', '@OUTPUT@', 'compile_stubs'])

incdirs += include_directories('EXTERNAL_HEADERS')

llvm_dep = dependency('llvm', modules : ['lto'])

ld = executable('ld64', srcs,
  include_directories : incdirs,
  link_args: ['-lxar', '-ltapi'],
  dependencies: llvm_dep.partial_dependency(includes : true),
  install : true)

unwinddump = executable('unwinddump', unwinddumpsrcs,
  include_directories : incdirs,
  install : true)
