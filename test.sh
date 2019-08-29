make re db
{ sleep 0.1; echo ; } &
{ sleep 0.1; echo ; } &
wait
ARG=`ruby -W0 -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
echo operation count :
ARG=`ruby -W0 -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
{ sleep 0; echo Sorted 3 random arguments; } &
wait

ARG=`ruby -W0 -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
echo operation count :
ARG=`ruby -W0 -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
{ sleep 0; echo Sorted 5 random arguments; } &
wait

ARG=`ruby -W0 -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
echo operation  count :
ARG=`ruby -W0 -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
{ sleep 0; echo Sorted 100 random arguments; } &
wait

ARG=`ruby -W0 -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
echo operation count :
ARG=`ruby -W0 -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
{ sleep 0; echo Sorted 500 random arguments; } &
wait

