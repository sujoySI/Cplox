add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"})
set_languages("c++23")

add_requires("fmt")

target("Cplox")
    set_kind("binary")
    add_includedirs("./include")
    add_packages("fmt")
    add_files("src/*.cpp")
target_end()