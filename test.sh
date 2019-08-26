make re db

{ sleep 0.1; echo ; } &
{ sleep 0.1; echo ; } &
wait

ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
{ sleep 0; echo Sorted 3 random arguments; } &
{ sleep 1; echo ; } &
wait

ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
{ sleep 0; echo Sorted 5 random arguments; } &
{ sleep 1; echo ; } &
wait

ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
{ sleep 0; echo Sorted 100 random arguments; } &
{ sleep 1; echo ; } &
wait

ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
{ sleep 0; echo Sorted 500 random arguments; } &
{ sleep 1; echo ; } &
wait

