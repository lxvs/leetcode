#!/bin/sh
set -o nounset

main () {
    local description
    local header_path="build/version.h"
    get_description || return
    write_to_header || return
}

get_description () {
    local CLFAGS_LOCAL=${CFLAGS_LOCAL-}
    description=$(git describe --always --dirty)
    description=${description#v}
    while true
    do
        case $CLFAGS_LOCAL in
        *-DDEBUG*)
            description="$description (debug)"
            CLFAGS_LOCAL=`printf "%s" "$CLFAGS_LOCAL" | sed -e 's/-DDEBUG//g'`
            ;;
        *-fsanitize*)
            description="$description (ASan)"
            CLFAGS_LOCAL=`printf "%s" "$CLFAGS_LOCAL" | sed -e 's/-fsanitize//g'`
            ;;
        *-fdiagnostics-color=always*)
            description="$description (debugger)"
            CLFAGS_LOCAL=`printf "%s" "$CLFAGS_LOCAL" | sed -e 's/-fdiagnostics-color=always//g'`
            ;;
        *)
            break
            ;;
        esac
    done
    test "${DEBUG_FLAGS+1}" && description="$description (debug)"
    test "${ADDRESS_SANITIZER_FLAGS+1}" && description="$description (address sanitizer)"
    test "$description" || return
}

write_to_header () {
    local header_dir
    header_dir=$(dirname "$header_path") || return
    test -d "$header_dir" ||
        mkdir "$header_dir" ||
        return
    >"$header_path" printf "%s\n" \
        "#ifndef INCLUDED_VERSION_H_" \
        "#define INCLUDED_VERSION_H_" \
        "" \
        "#define EXEC_VERSION \"$description\"" \
        "" \
        "#endif  /* INCLUDED_VERSION_H_ */"
}

main "$@"
