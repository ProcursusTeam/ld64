install_data(['ld-classic.1', 'unwinddump.1'],
             install_dir : get_option('mandir') / 'man1',
             rename : [ get_option('program-prefix') + 'ld-classic.1', get_option('program-prefix') + 'unwinddump.1' ] )

install_symlink(get_option('program-prefix') + 'ld64.1',
                pointing_to : get_option('program-prefix') + 'ld-classic.1',
                install_dir : get_option('mandir') / 'man1')
