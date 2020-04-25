rm -f map.cub
touch map.cub
printf "R 800 800\n\
NO ./textures/xpm/bluestone.xpm\n\
SO ./textures/xpm/colorstone.xpm\n\
WE ./textures/xpm/greystone.xpm\n\
EA ./textures/xpm/mossy.xpm\n\
S ./textures/xpm/barrel.xpm\n\
F 136,66,29\nC 242,255,255\n" >> map.cub
I=1
J=1
PLAYER=0
MIN=5
MAX=200
DIFF=$(($MAX-$MIN+1))
HEIGHT=$(($(($RANDOM%$DIFF))+$MIN))
LENGTH=$(($(($RANDOM%$DIFF))+$MIN))
DIR=$(($RANDOM%4))
while [ $I -le $HEIGHT ]
do
    let "J = 1"
    while [ $J -le $LENGTH ]
    do
        if [ $J -eq 1 ] || [ $J -eq $LENGTH ] || [ $I -eq 1 ] || [ $I -eq $HEIGHT ]
        then
            printf "1" >> map.cub #ligne / colonne de 1
        elif [ $PLAYER -eq 0 ] && [[ ( $(($RANDOM%5000)) -eq 50 ) || ( $I -eq $(( HEIGHT - 1 ))  &&  $J -eq $(( LENGTH - 1 )) ) ]]
        then
            if [ $DIR -eq 0 ]
            then
                printf "N" >> map.cub
            elif [ $DIR -eq 1 ]
            then
                printf "S" >> map.cub
            elif [ $DIR -eq 2 ]
            then
                printf "W" >> map.cub
            else
                printf "E" >> map.cub
            fi
            let "PLAYER = 1"
        elif [ $(($RANDOM%5)) -eq 1 ]
        then
            printf "1" >> map.cub
        elif [ $(($RANDOM%100)) -eq 1 ]
        then
            printf "2" >> map.cub
        else
            printf "0" >> map.cub
        fi
        let "J=J + 1"
    done
    printf "\n" >> map.cub
    let "I = I + 1"
done
