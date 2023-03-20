subdir('abstraction')
subdir('ld')
subdir('other')
subdir('custom')

conf_data = configuration_data()
conf_data.set('LD64_VERSION_NUM', meson.project_version())
conf_data.set('LD_PAGE_SIZE', '0x1000')
conf_data.set('BITCODE_XAR_VERSION', '"1.0"')

foreach arch : archs
  conf_data.set('SUPPORT_ARCH_@0@'.format(arch), 1)
endforeach

conf_data.set('ALL_SUPPORTED_ARCHS', '"@0@"'.format(' '.join(archs)))

if host_machine.system() != 'darwin'
  conf_data.set('MAXPATHLEN', 'PATH_MAX')
endif

configure_file(output : 'configure.h',
               configuration : conf_data)

incdirs += include_directories('.')
prunetrie_inc += include_directories('.')
