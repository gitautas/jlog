project('jlog', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

lib_args = ['-DBUILDING_JLOG', '-fvisibility=default']

json = dependency('nlohmann_json')
fmt = dependency('fmt')

deps = [
  json,
  fmt,
]

shlib = shared_library('jlog', 'jlog.cpp',
  install : true,
  cpp_args : lib_args,
  gnu_symbol_visibility : 'default',
  dependencies : deps,
)

test_exe = executable('jlog_test', 'jlog_test.cpp',
  dependencies : deps,
  link_with : shlib)

test('jlog', test_exe)

# Make this library usable as a Meson subproject.
jlog_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('jlog.hpp', subdir : 'jlog')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'jlog',
  filebase : 'jlog',
  description : 'Structured JSON logging library',
  subdirs : 'jlog',
  libraries : shlib,
  version : '0.1',
)
