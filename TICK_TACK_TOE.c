#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../library_code/tick_tack_toe_basic.h"

int main()
{
    TICK_TACK_TOE tick_tack_toe_phase[3][3];
    int judge_end = 0;
    int judge_first_move;
    int player_order_end = 1;
    char difficulty_level;

    srand((int) time(NULL));
    judge_first_move = rand() % 2;
    printf("You are the O side.\n");
    while(player_order_end)
    {
        difficulty_level = get_difficulty_level();
        initialization(tick_tack_toe_phase);
        output_tick_tack_toe_phase(tick_tack_toe_phase);
        if (judge_first_move == 1)
            while (!judge_end)          //计算机先手
            {
                printf("Computer's turn:\n");
                if (difficulty_level == 'B')
                    computer_middle_move_piece(tick_tack_toe_phase);
                else if (difficulty_level == 'C')
                    computer_high_move_piece(tick_tack_toe_phase);
                else
                    computer_low_move_piece(tick_tack_toe_phase);
                judge_end = judge_win(tick_tack_toe_phase);
                output_tick_tack_toe_phase(tick_tack_toe_phase);
                if (judge_end != 0)
                    goto step_one;
                printf("Player's turn:\n");
                receive_judge_move(tick_tack_toe_phase);
                output_tick_tack_toe_phase(tick_tack_toe_phase);
                judge_end = judge_win(tick_tack_toe_phase);
                step_one: ;
            }
        else                            //玩家先手
            while (!judge_end)
            {
                printf("Player's turn:\n");
                receive_judge_move(tick_tack_toe_phase);
                output_tick_tack_toe_phase(tick_tack_toe_phase);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end != 0)
                    goto step_two;
                printf("Computer's turn:\n");
                if (difficulty_level == 'B')
                    computer_middle_move_piece(tick_tack_toe_phase);
                else if (difficulty_level == 'C')
                    computer_high_move_piece(tick_tack_toe_phase);
                else
                    computer_low_move_piece(tick_tack_toe_phase);
                judge_end = judge_win(tick_tack_toe_phase);
                output_tick_tack_toe_phase(tick_tack_toe_phase);
                step_two: ;
            }
        judge_first_move = judge_end - 1;      //先手交换
        judge_end = 0;      //为下一局游戏初始化结束判断参数
        printf("Only enter \"q\" or \"Q\" to can you quit the game. Otherwise you will start a new turn.\n");     //判断是否结束游戏
        printf("Please enter your order:\n");
        player_order_end = judge_player_order_end();
        if (player_order_end)
            printf("You start a new turn.\n");
        else
            printf("You end the game.\n");
    }

    return 0;
}
