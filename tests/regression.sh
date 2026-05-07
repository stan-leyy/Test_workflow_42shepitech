#!/bin/bash

SHELL=./42sh
PASS=0
FAIL=0

check() {
    local desc=$1
    local cmd=$2
    local expected=$3
    local result=$(echo "$cmd" | $SHELL 2>&1)

    if [ "$result" = "$expected" ]; then
        echo "✅ $desc"
        PASS=$((PASS + 1))
    else
        echo "❌ $desc"
        echo "   attendu : $expected"
        echo "   obtenu  : $result"
        FAIL=$((FAIL + 1))
    fi
}

check_contains "setenv" "setenv TEST hello ; env" "TEST=hello"
check "unsetenv" "unsetenv PATH" ""

check "cd tmp" "cd /tmp ; pwd" "/tmp"
check "pwd"         "pwd"           "$(pwd)"
check "env"         "env"           "$(env)"

check "ls"          "ls"            "$(ls)"

check "cmd inexistante"   "fakecommand"   "fakecommand: Command not found."
check "exit avec args"    "exit 42"       "exit: Expression Syntax."

check "ls ; pwd"    "ls ; pwd"      "$(ls)
$(pwd)"

check "ls | wc -l"  "ls | wc -l"   "$(ls | wc -l)"

check "&& succes"   "ls && pwd"     "$(ls)
$(pwd)"
check "&& echec"    "fakecommand && pwd"  "fakecommand: Command not found."

check "|| echec"    "fakecommand || pwd"  "fakecommand: Command not found.
$(pwd)"
check "|| succes"   "ls || pwd"     "$(ls)"

check "&& || combo" "fakecommand && ls || pwd" "fakecommand: Command not found.
$(pwd)"


check "single quote"        "echo 'hello world'"    "hello world"
check "single bloque dollar" "echo '\$HOME'"        "\$HOME"
check "double quote"        "echo \"hello world\""  "hello world"

check "echo dollar?"  "ls ; echo \$?"   "$(ls)
0"
check "alias Imanol 'cat Makefile'"
echo ""
echo "Résultat : $PASS passés, $FAIL échoués"
