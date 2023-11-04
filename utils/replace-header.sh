#!/bin/sh
set -o nounset

main () {
    local source_path_wo_ext=${1-}
    local header_wo_ext
    test "$source_path_wo_ext" || return
    case ${source_path_wo_ext##*.} in
    c|h|'')
        source_path_wo_ext=${source_path_wo_ext%.*}
        ;;
    esac
    header_wo_ext=$(basename "$source_path_wo_ext")
    sed -e "/^\s*#include\s*\"$header_wo_ext.h\"\s*\$/{" \
        -e "r $source_path_wo_ext.h" \
        -e "d}" \
        "$source_path_wo_ext.c" |
        sed -e '/\s*#include\s*<lib\//d'
}

main "$@"
