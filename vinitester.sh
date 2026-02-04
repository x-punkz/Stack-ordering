#!/bin/bash

LEAK_OK="All heap blocks were freed -- no leaks are possible"

run_test() {
    DESC="$1"
    CMD="$2"

    echo -n "$DESC: "
    OUT=$(eval "$CMD" 2>&1)
    echo "$OUT" | grep -q "Error" && ERR="ERR" || ERR="OK"

    LEAK=$(valgrind --leak-check=full --error-exitcode=42 $CMD >/dev/null 2>&1; echo $?)

    if [ "$LEAK" -eq 42 ]; then
        echo "✗ LEAK"
    else
        echo "✓"
    fi
}

run_no_output_test() {
    DESC="$1"
    CMD="$2"

    echo -n "$DESC: "
    OUT=$(eval "$CMD" 2>&1)
    if [ -z "$OUT" ]; then
        LEAK=$(valgrind --leak-check=full --error-exitcode=42 $CMD >/dev/null 2>&1; echo $?)
        [ "$LEAK" -eq 42 ] && echo "✗ LEAK" || echo "✓"
    else
        echo "✗"
    fi
}

echo "=========================================="
echo "    TESTE COMPLETO - PUSH_SWAP + LEAK"
echo "=========================================="
echo ""
echo "=== 1. TESTES DE ERRO + LEAK ==="
echo ""

run_test "Non-numeric (letters)" "./push_swap abc"
run_test "Non-numeric (mixed)" "./push_swap 1 2a 3"
run_test "Non-numeric (special)" "./push_swap 1 @ 3"
run_test "Duplicados (1 2 3 2)" "./push_swap 1 2 3 2"
run_test "Duplicados (0 0)" "./push_swap 0 0"
run_test "Duplicados (3 03)" "./push_swap 3 03"
run_test "INT > MAX" "./push_swap 2147483648"
run_test "INT < MIN" "./push_swap -2147483649"
run_test "Huge number" "./push_swap 999999999999999"
run_test "dog no meio" "./push_swap 1 3 dog 35"
run_test "Numero+letra" "./push_swap 1 2 67b778 5"
run_test "String com letra" "./push_swap \"12 4 54fhd\""
run_test "Duplo traco" "./push_swap 1 -- 45"

run_no_output_test "Empty string" "./push_swap \"\""
run_no_output_test "So espacos" "./push_swap \"   \""
run_no_output_test "No args" "./push_swap"

echo ""
echo "=== 2. IDENTITY TEST (sem output + sem leak) ==="
echo ""

run_no_output_test "Single" "./push_swap 42"
run_no_output_test "0 1 2" "./push_swap 0 1 2"
run_no_output_test "0..9" "./push_swap 0 1 2 3 4 5 6 7 8 9"

echo ""
echo "=== 3. CASOS VÁLIDOS + LEAK ==="
echo ""

run_test "Args mistos" "./push_swap 1 3 5 +9 20 -4 50 60 04 08"
run_test "String unica" "./push_swap \"3 4 6 8 9 74 -56 +495\""
run_test "INT_MAX" "./push_swap 2147483647 2 4"
run_test "INT_MIN" "./push_swap 99 -2147483648 23"
run_test "-9 e 9" "./push_swap \"95 99 -9 10 9\""

echo ""
echo "=== 4. 3 NUMEROS (<=3 ops + sem leak) ==="
echo ""

for i in {1..3}; do
    ARG=$(seq 0 2 | shuf | tr '\n' ' ')
    echo -n "Teste $i ($ARG): "
    OPS=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
    LEAK=$(valgrind --leak-check=full --error-exitcode=42 ./push_swap $ARG >/dev/null 2>&1; echo $?)
    if [ "$CHECK" = "OK" ] && [ "$OPS" -le 3 ] && [ "$LEAK" -ne 42 ]; then
        echo "✓ OK | Ops: $OPS"
    else
        echo "✗ FAIL | Ops: $OPS | $CHECK"
    fi
done

echo ""
echo "=== 5. 5 NUMEROS (<=12 ops + sem leak) ==="
echo ""

for i in {1..5}; do
    ARG=$(seq 0 4 | shuf | tr '\n' ' ')
    echo -n "Teste $i: "
    OPS=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
    LEAK=$(valgrind --leak-check=full --error-exitcode=42 ./push_swap $ARG >/dev/null 2>&1; echo $?)
    if [ "$CHECK" = "OK" ] && [ "$OPS" -le 12 ] && [ "$LEAK" -ne 42 ]; then
        echo "✓ OK | Ops: $OPS"
    else
        echo "✗ FAIL | Ops: $OPS | $CHECK"
    fi
done

echo ""
echo "=== 6. 100 NUMEROS (<=700 ops + sem leak) ==="
echo ""

for i in {1..3}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    echo -n "Teste $i: "
    OPS=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
    LEAK=$(valgrind --leak-check=full --error-exitcode=42 ./push_swap $ARG >/dev/null 2>&1; echo $?)
    if [ "$CHECK" = "OK" ] && [ "$OPS" -le 700 ] && [ "$LEAK" -ne 42 ]; then
        echo "✓ OK | Ops: $OPS"
    else
        echo "✗ FAIL | Ops: $OPS | $CHECK"
    fi
done

echo ""
echo "=== 7. 500 NUMEROS (<=5500 ops + sem leak) ==="
echo ""

for i in {1..2}; do
    ARG=$(seq 1 500 | shuf | tr '\n' ' ')
    echo -n "Teste $i: "
    OPS=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
    LEAK=$(valgrind --leak-check=full --error-exitcode=42 ./push_swap $ARG >/dev/null 2>&1; echo $?)
    if [ "$CHECK" = "OK" ] && [ "$OPS" -le 5500 ] && [ "$LEAK" -ne 42 ]; then
        echo "✓ OK | Ops: $OPS"
    else
        echo "✗ FAIL | Ops: $OPS | $CHECK"
    fi
done

echo ""
echo "=========================================="
echo "   TESTES + LEAK CHECK FINALIZADOS"
echo "=========================================="
