#!/bin/bash

##############################################
# CONFIG
##############################################
PUSH_SWAP=./push_swap
CHECKER=./checker_linux   # ajuste se for checker_Mac
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all -q"

##############################################
# CORES
##############################################
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
NC="\033[0m"

##############################################
# FUNÇÕES AUX
##############################################
header() {
    echo -e "\n${YELLOW}========== $1 ==========${NC}"
}

ok() {
    echo -e "${GREEN}[OK]${NC} $1"
}

fail() {
    echo -e "${RED}[FAIL]${NC} $1"
}

run_test() {
    local args="$1"
    local output
    output=$($PUSH_SWAP $args 2>/dev/null | $CHECKER $args)
    if [ "$output" = "OK" ]; then
        ok "Args: $args"
    else
        fail "Args: $args"
    fi
}

##############################################
# TESTES BÁSICOS
##############################################
header "TESTES BÁSICOS"

run_test ""
run_test "42"
run_test "1 2"
run_test "2 1"
run_test "1 2 3"
run_test "3 2 1"

##############################################
# EDGE CASES
##############################################
header "EDGE CASES"

run_test "0"
run_test "-1"
run_test "0 -1 1"
run_test "2147483647"
run_test "-2147483648"
run_test "2147483647 -2147483648 0"

##############################################
# INPUT JÁ ORDENADO
##############################################
header "JÁ ORDENADO"

run_test "1 2 3 4 5"
run_test "-5 -4 -3 -2 -1 0"

##############################################
# INPUT REVERSO
##############################################
header "REVERSO"

run_test "5 4 3 2 1"
run_test "10 9 8 7 6 5 4 3 2 1"

##############################################
# DUPLICADOS (DEVE DAR ERROR)
##############################################
header "DUPLICADOS"

$PUSH_SWAP "1 1" 2>/dev/null && fail "Duplicados não detectados" || ok "Duplicados detectados"
$PUSH_SWAP "1 2 3 2" 2>/dev/null && fail "Duplicados não detectados" || ok "Duplicados detectados"

##############################################
# INPUT INVÁLIDO
##############################################
header "INPUT INVÁLIDO"

$PUSH_SWAP "a b c" 2>/dev/null && fail "Letras aceitas" || ok "Letras rejeitadas"
$PUSH_SWAP "1 2 +" 2>/dev/null && fail "Símbolos aceitos" || ok "Símbolos rejeitados"
$PUSH_SWAP "1 2 3 999999999999" 2>/dev/null && fail "Overflow aceito" || ok "Overflow rejeitado"

##############################################
# TESTES RANDOM
##############################################
header "TESTES RANDOM"

for i in 5 10 50 100
do
    ARG=$(shuf -i -1000:1000 -n $i | tr '\n' ' ')
    run_test "$ARG"
done

##############################################
# PERFORMANCE (NÚMERO DE MOVIMENTOS)
##############################################
header "PERFORMANCE"

ARG_100=$(shuf -i 1:100 -n 100 | tr '\n' ' ')
MOVES_100=$($PUSH_SWAP $ARG_100 | wc -l)
echo "100 números → $MOVES_100 movimentos"

ARG_500=$(shuf -i 1:500 -n 500 | tr '\n' ' ')
MOVES_500=$($PUSH_SWAP $ARG_500 | wc -l)
echo "500 números → $MOVES_500 movimentos"

##############################################
# TESTE DE LEAKS
##############################################
header "TESTE DE LEAKS (VALGRIND)"

$VALGRIND $PUSH_SWAP "3 2 1" >/dev/null && ok "Sem leaks (3 números)" || fail "Leak detectado"
$VALGRIND $PUSH_SWAP "$ARG_100" >/dev/null && ok "Sem leaks (100 números)" || fail "Leak detectado"

##############################################
# STRESS TEST
##############################################
header "STRESS TEST"

for i in {1..5}
do
    ARG=$(shuf -i -10000:10000 -n 500 | tr '\n' ' ')
    $PUSH_SWAP $ARG >/dev/null || fail "Crash no stress test"
done
ok "Stress test concluído"

##############################################
# FIM
##############################################
header "FIM DOS TESTES"

