#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tick_tack_toe_basic.h"

//初始化棋局的数组
void initialization(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    tick_tack_toe_phase[0][0] = tick_tack_toe_phase[0][2] = tick_tack_toe_phase[2][1] = 1;
    tick_tack_toe_phase[0][1] = tick_tack_toe_phase[2][0] = tick_tack_toe_phase[2][2] = 2;
    tick_tack_toe_phase[1][0] = tick_tack_toe_phase[1][1] = tick_tack_toe_phase[1][2] = 0;
}

//将棋局打印到屏幕上的函数
void output_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int m, i;

    printf("     1   2   3 \n");                          //横坐标打印
    printf("    --- --- ---\n");
    for (m = 0; m < 3; m++)
        {
            switch (m)                                    //纵坐标打印
            {
                case 0: printf(" A |");
                        break;
                case 1: printf(" B |");
                        break;
                case 2: printf(" C |");
                        break;
            }

            for (i = 0; i < 3; i++)
                switch (tick_tack_toe_phase[m][i])        //打印棋子
                {
                    case 0: printf(" - |");
                            break;
                    case 1: printf(" X |");
                            break;
                    case 2: printf(" O |");
                            break;
                    default:;
                }
            printf("\n");
            printf("    --- --- ---\n");
        }

    return;
}

//判断棋局是否在此步终结并决出胜利方的函数
int judge_win(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int row[3], col[3], diag[2];
    int i;

    for (i = 0; i < 3; i++)
        row[i] = tick_tack_toe_phase[i][0] * tick_tack_toe_phase[i][1] * tick_tack_toe_phase[i][2];
    for (i = 0; i < 3; i++)
        col[i] = tick_tack_toe_phase[0][i] * tick_tack_toe_phase[1][i] * tick_tack_toe_phase[2][i];
    diag[0] = tick_tack_toe_phase[0][0] * tick_tack_toe_phase[1][1] * tick_tack_toe_phase[2][2];
    diag[1] = tick_tack_toe_phase[0][2] * tick_tack_toe_phase[1][1] * tick_tack_toe_phase[2][0];

    if (row[0] == 1 || row[1] == 1 || row[2] == 1 || col[0] == 1 || col[1] == 1 || col[2] == 1 || diag[0] == 1 || diag[1] == 1)    //判断X方是否获胜
        return 1;                                //返回值用于下一局游戏先手交换
    else if (row[0] == 8 || row[1] == 8 || row[2] == 8 || col[0] == 8 || col[1] == 8 || col[2] == 8 || diag[0] == 8 || diag[1] == 8)  //判断O方是否获胜
        return 2;                                   //返回值用于下一局游戏先手交换
    else                        //X方和O方均未获胜，游戏未结束
        return 0;
}

//实现玩家移动棋子的函数
void receive_judge_move(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int i = -1;
    int x, y;
    int array_receive_judge_move_from[2], array_receive_judge_move_to[2];
    TICK_TACK_TOE m = 0;
    TICK_TACK_TOE temp;
    char order_select_piece[2];

    printf("Please select the piece you want to move. Your order must be in certain format like A2 or A2CCD (both mean A2).\n");
    while ((i == -1) || (m != 2))      //获取移动棋子的命令并检测其合法性
    {
        scanf("%s", order_select_piece);
        if (((order_select_piece[0] == 'A') || (order_select_piece[0] == 'B') || (order_select_piece[0] == 'C')) && ((order_select_piece[1] == '1') || (order_select_piece[1] == '2') || (order_select_piece[1] == '3')))  //用于判断玩家命令是否合法
            i = 1;
        else
            i = -1;
        if (i == -1)                  //玩家输入错误内容时的反馈
            printf("What you input is not in a right format or beyond chessboard. Please enter your order again.\n");
        else
            {
                array_receive_judge_move_from[0] = (int) (order_select_piece[0] - 'A');          //用于记录玩家的命令
                array_receive_judge_move_from[1] = (int) (order_select_piece[1] - '1');
                m = tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]];
                if (m == 0)
                    printf("What you want to move is not a piece. Please enter your order again.\n");
                if (m == 1)
                    printf("What you want to move is a piece belonging to the computer. Please input your order again.\n");
            }
    }
    i = -1;        //初始化判断用参数
    m = 0;
    printf("Please select the place you want to move to. Your order must be in certain format like A2 or A2CCD (both mean A2).\n");
    while ((i == -1) || (m != 0))         //获取玩家移动棋子到某处的命令并检测其合法性
    {
        scanf("%s", order_select_piece);
        if (((order_select_piece[0] == 'A') || (order_select_piece[0] == 'B') || (order_select_piece[0] == 'C')) && ((order_select_piece[1] == '1') || (order_select_piece[1] == '2') || (order_select_piece[1] == '3')))  //用于判断玩家命令是否合法
            i = 1;
        else
            i = -1;
        if (i == -1)             //玩家输入内容不合法时的反馈
            printf("What you input is not in a right format or beyond chessboard. Please enter your order again.\n");
        else
        {
            array_receive_judge_move_to[0] = (int) (order_select_piece[0] - 'A');          //用于记录玩家的命令
            array_receive_judge_move_to[1] = (int) (order_select_piece[1] - '1');
            m = tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]];
            if (m == 0)
            {
                x = array_receive_judge_move_to[0] - array_receive_judge_move_from[0];
                y = array_receive_judge_move_to[1] - array_receive_judge_move_from[1];
                if (!((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //判断玩家选择移动到的位置是否合法
                {
                    i = -1;
                    printf("Your piece can't get to that place. Please enter your order again.\n");
                }
            }
            else
                printf("Another piece is at where you want to move your piece to. Please enter your order again.\n");
        }
    }
    while (getchar() != '\n')              //消耗换行符，防止其干扰主函数中任何其他需要获取输入的命令
        continue;
    temp = tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]];        //交换棋局数组的元素的值，从而实现棋子移动
    tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]] = tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]];
    tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]] = temp;

    return;
}

//实现计算机低级移动棋子
void computer_low_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int computer_move_from_y[3];
    int computer_move_from_x[3];   //联合两个数组用于记录计算机的棋子的位置
    int computer_move_to_y[3];
    int computer_move_to_x[3];    //联合两个数组用于记录计算机棋子可移动的空白棋格的位置
    int i, j, k, p;
    int x, y;
    int rand_move_1, rand_move_2;
    TICK_TACK_TOE temp;

    for (i = 0, k = 0, p =0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (tick_tack_toe_phase[i][j] == 1)          //记录计算机的棋子的位置
            {
                computer_move_from_y[k] = i;
                computer_move_from_x[k] = j;
                k++;
            }
            if (tick_tack_toe_phase[i][j] == 0)          //记录空白棋格的位置
            {
                computer_move_to_y[p] = i;
                computer_move_to_x[p] = j;
                p++;
            }
        }
    }
    rand_move_1 = rand() % 3;              //实现随机
    rand_move_2 = rand() % 3;
    for (i = 0; i < 3; i++)                //实现移动棋子
    {
        rand_move_1 = (rand_move_1 + i) % 3;
        for (j = 0; j < 3; j++)
        {
            rand_move_2 = (rand_move_2 + j) % 3;
            y = computer_move_from_y[rand_move_1] - computer_move_to_y[rand_move_2];
            x = computer_move_from_x[rand_move_1] - computer_move_to_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                temp = tick_tack_toe_phase[computer_move_to_y[rand_move_2]][computer_move_to_x[rand_move_2]];
                tick_tack_toe_phase[computer_move_to_y[rand_move_2]][computer_move_to_x[rand_move_2]] = tick_tack_toe_phase[computer_move_from_y[rand_move_1]][computer_move_from_x[rand_move_1]];
                tick_tack_toe_phase[computer_move_from_y[rand_move_1]][computer_move_from_x[rand_move_1]] = temp;   //交换棋局数组的元素的值，从而实现棋子移动
                goto step_one;
            }
        }
    }
    step_one: ;

    return;
}

//实现终止游戏命令的获取及验证
int judge_player_order_end(void)
{
    char first_char;
    int player_order_end;

    if (((first_char = getchar()) == 'q') || (first_char == 'Q'))    //处理玩家输入“Q+.."或”q+..“的情况
    {
        player_order_end = 0;
        if (getchar() != '\n')
        {
            while (getchar() != '\n')         //消耗换行符，防止干扰主函数中任何其他需要获取输入的命令
                continue;
            player_order_end = 1;
        }
    }
    else       //处理玩家输入其他内容的情况
    {
        if (first_char == '\n')               //处理玩家直接输入换行符的情况
            goto step_one;
        while (getchar() != '\n')             //消耗换行符，防止干扰主函数中任何其他需要获取输入的命令
            continue;
        step_one: ;
        player_order_end = 1;
    }

    return player_order_end;
}

//实现计算机中级移动棋子（初步防守与初步进攻）
void computer_middle_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    TICK_TACK_TOE computer_piece_place_x[3], computer_piece_place_y[3], player_piece_place_x[3], player_piece_place_y[3], null_piece_place_x[3], null_piece_place_y[3];
    int a, b, c, d, e;
    int x, y;
    int judge_end;
    TICK_TACK_TOE simu_player_win_null_piece_place_y[3], simu_player_win_null_piece_place_x[3];
    int rand_move_1, rand_move_2, rand_move_1_1, rand_move_2_2;
    int rand_move_3, rand_move_4, rand_move_3_3, rand_move_4_4;

    for (a = 0, c = 0, d =0, e = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            if (tick_tack_toe_phase[a][b] == 1)          //记录计算机的棋子的位置
            {
                computer_piece_place_y[c] = a;
                computer_piece_place_x[c] = b;
                c++;
            }
            if (tick_tack_toe_phase[a][b] == 0)          //记录空白棋格的位置
            {
                null_piece_place_y[d] = a;
                null_piece_place_x[d] = b;
                d++;
            }
            if (tick_tack_toe_phase[a][b] == 2)          //记录玩家的棋子的位置
            {
                player_piece_place_y[e] = a;
                player_piece_place_x[e] = b;
                e++;
            }
        }
    }
    for (a = 0; a < 3; a++)                //初步进攻
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end == 0)     //如果不能获胜，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else               //如果获胜，则终止函数
                    goto step_1;
            }
        }
    }
    for (b = 0, c = 0; b < 3; b++)                //初步防守，一段，检测需要防守的空白棋格
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end != 0)            //记录模拟玩家胜利时所涉及的空白棋格的位置
                {
                    simu_player_win_null_piece_place_y[c] = null_piece_place_y[b];
                    simu_player_win_null_piece_place_x[c] = null_piece_place_x[b];
                    c++;
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                    break;
                }
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
            }
        }
    }
    rand_move_3_3 = rand();
    rand_move_4_4 = rand();
    for (a = 0; a < c; a++)             //初步防守，二段，防守相应空白棋格并防止产生新的破绽
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    rand_move_1_1 = rand();       //实现随机
    rand_move_2_2 = rand();
    for (a = 0; a < c; a++)        //初步防守，三段，处理无论如何防守需要防守的棋格都会产生破绽的情况，此时伪装成没有产生破绽的假象
    {
        rand_move_1 = (rand_move_1_1 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = simu_player_win_null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_1], simu_player_win_null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //初步防守，四段，处理无需防守的情况
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                if (d == 1)               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //初步防守，五段，处理无论如何移动都会产生破绽的死局的情况
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }

    step_1: ;

    return;
}

//实现计算机高级移动棋子（进阶防守与进阶进攻）
void computer_high_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    TICK_TACK_TOE computer_piece_place_x[3], computer_piece_place_y[3], player_piece_place_x[3], player_piece_place_y[3], null_piece_place_x[3], null_piece_place_y[3];
    int a, b, c, d, e;
    int x, y;
    int judge_end;
    TICK_TACK_TOE simu_player_win_null_piece_place_y[3], simu_player_win_null_piece_place_x[3];
    TICK_TACK_TOE simu_1_player_win_null_piece_place_y[3], simu_1_player_win_null_piece_place_x[3];
    int rand_move_1, rand_move_2, rand_move_1_1, rand_move_2_2;
    int rand_move_3, rand_move_4, rand_move_3_3, rand_move_4_4;


    for (a = 0, c = 0, d =0, e = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            if (tick_tack_toe_phase[a][b] == 1)          //记录计算机的棋子的位置
            {
                computer_piece_place_y[c] = a;
                computer_piece_place_x[c] = b;
                c++;
            }
            if (tick_tack_toe_phase[a][b] == 0)          //记录空白棋格的位置
            {
                null_piece_place_y[d] = a;
                null_piece_place_x[d] = b;
                d++;
            }
            if (tick_tack_toe_phase[a][b] == 2)          //记录玩家的棋子的位置
            {
                player_piece_place_y[e] = a;
                player_piece_place_x[e] = b;
                e++;
            }
        }
    }
    for (a = 0; a < 3; a++)                //进阶进攻，一段，处理能在这一手直接获得胜利的情况
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end == 0)     //如果不能获胜，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else               //如果获胜，则终止函数
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)             //进阶进攻，二段，处理能在下一手获得胜利的情况（已排除可以直接获胜或导致在对方下一手失败的情况），不难穷举得出己方下一手获胜的棋局的集合与对方下一手获胜的棋局的集合的交集为空集
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                if (!(judge_cause_win_a_side(tick_tack_toe_phase, 1, 2)))
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else
                    goto step_1;
            }
        }
    }
    for (b = 0, c = 0; b < 3; b++)                //进阶防守，一段，检测急切需要防守的空白棋格（第一类破绽）
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end != 0)            //记录模拟玩家胜利时所涉及的空白棋格的位置
                {
                    simu_player_win_null_piece_place_y[c] = null_piece_place_y[b];
                    simu_player_win_null_piece_place_x[c] = null_piece_place_x[b];
                    c++;
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                    break;
                }
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
            }
        }
    }
    for (b = 0, d = 0; b < 3; b++)                //进阶防守，二段，检测可能会导致对手在第二手获胜的空白棋格（第二类破绽）
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                if (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1))            //记录模拟玩家胜利时所涉及的空白棋格的位置
                {
                    simu_1_player_win_null_piece_place_y[d] = null_piece_place_y[b];
                    simu_1_player_win_null_piece_place_x[d] = null_piece_place_x[b];
                    d++;
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                    break;
                }
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
            }
        }
    }
    rand_move_3_3 = rand();
    rand_move_4_4 = rand();
    //保留对存在两处需要防守的空白棋格的情况以及无法防守的情况是为了保险，尽管理论上这种情况并不会在被此函数遇到
    for (a = 0; a < c; a++)             //进阶防守，三段，防守急切需要防守的棋格并防止产生第一类和第二类破绽
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if ((d == 1) || (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1)))               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    for (a = 0; a < c; a++)             //进阶防守，四段，防守相应空白棋格并防止产生第一类破绽
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    rand_move_1_1 = rand();       //实现随机
    rand_move_2_2 = rand();
    for (a = 0; a < c; a++)        //进阶防守，五段，处理无论如何防守需要防守的棋格都会产生第一类破绽的情况，此时伪装出没有产生相应破绽的假象
    {
        rand_move_1 = (rand_move_1_1 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = simu_player_win_null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_1], simu_player_win_null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    for (a = 0; a < d; a++)             //进阶防守，六段，阻断对方在后两手获得胜利并在防守时防止产生新的破绽
    {
        rand_move_3 = (rand_move_3_3 + a) % d;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_1_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_1_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if ((d == 1) || (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1)))               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    for (a = 0; a < d; a++)             //进阶防守，七段，无法阻断防守对方在后两手获得胜利时产生第二类破绽，伪装出未产生相应破绽的假象
    {
        rand_move_3 = (rand_move_3_3 + a) % d;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_1_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_1_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //进阶防守，八段，处理无需防守的情况
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                if (d == 1)               //产生破绽，则撤销交换
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                else                    //若无破绽产生，则终止剩余步骤
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //进阶防守，九段，处理无论如何移动都会产生破绽的死局的情况（理论上这种情况不会出现，保险起见保留相应代码）
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    step_1:;

    return;
}

//获取玩家选择的游戏难度
char get_difficulty_level(void)
{
    char difficulty_level;

    printf("Please select difficulty level for the following turn.\nFor example, you can input \"A\" or \"ABD\" to select the EASY level.\n");
    printf("   LEVEL       CODE\n");
    printf("   EASY          A \n");
    printf("   NORMAL        B \n");
    printf("   DIFFICULT     C \n");
    scanf("%c", &difficulty_level);
    while (((difficulty_level != 'A') && (difficulty_level != 'B') && (difficulty_level != 'C')))
    {
        if ((difficulty_level != 'A') && (difficulty_level != 'B') && (difficulty_level != 'C'))
            printf("What you input doesn't begin with \"A\", \"B\" or \"C\". Please input your order again.\n");
        scanf("%c", &difficulty_level);
        while (getchar() != '\n')
            continue;
    }

    return difficulty_level;
}



//以下函数不应在主函数中被调用
//以下函数不应在主函数中被调用

//交换棋盘中指定位置的棋子
void exchange_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE y, TICK_TACK_TOE x, TICK_TACK_TOE yy, TICK_TACK_TOE xx)
{
    TICK_TACK_TOE temp;

    temp = tick_tack_toe_phase[y][x];
    tick_tack_toe_phase[y][x] = tick_tack_toe_phase[yy][xx];
    tick_tack_toe_phase[yy][xx] = temp;

    return;
}

//判断行动是否会产生破绽并撤销产生破绽的交换的函数
int judge_cause_flaw(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE player_piece_place_y[], TICK_TACK_TOE player_piece_place_x[], TICK_TACK_TOE judge_piece_place_y, TICK_TACK_TOE judge_piece_place_x)
{
    int a, x, y;
    int judge_end, d;

    for (a = 0; a < 3; a++)             //判断此防守是否会产生新的破绽
    {
        y = player_piece_place_y[a] - judge_piece_place_y;
        x = player_piece_place_x[a] - judge_piece_place_x;
        if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //选出合法的移动方式
        {
            exchange_tick_tack_toe_phase(tick_tack_toe_phase, judge_piece_place_y, judge_piece_place_x, player_piece_place_y[a], player_piece_place_x[a]);
            judge_end = judge_win(tick_tack_toe_phase);
            if (judge_end != 0)
            {
                d = 1;
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, judge_piece_place_y, judge_piece_place_x, player_piece_place_y[a], player_piece_place_x[a]);
                break;
            }
            d = 0;
            exchange_tick_tack_toe_phase(tick_tack_toe_phase, judge_piece_place_y, judge_piece_place_x, player_piece_place_y[a], player_piece_place_x[a]);
        }
    }

    return d;
}

//用于判断是否是必胜棋局的函数
int judge_cause_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE a, TICK_TACK_TOE b)
{
    int k, i, j;
    int c = 0;

    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 4; i++)
        {
            if (judge_win_a_side(tick_tack_toe_phase, k, a, b))
            {
                c = 1;
                goto step_1;
            }
            flip_upside_down_phase(tick_tack_toe_phase);   //用于判定翻转后的情况的翻转操作
            if (judge_win_a_side(tick_tack_toe_phase, k, a, b))
            {
                flip_upside_down_phase(tick_tack_toe_phase);  //撤销翻转操作
                c = 1;
                goto step_1;
            }
            flip_upside_down_phase(tick_tack_toe_phase);      //撤销翻转操作
            retate_anticlockwise_phase(tick_tack_toe_phase);   //为下一次循环而旋转
        }
    }

    step_1:;
    for (j = 0; j < 4 - i; j++)                 //将棋局的数组还原至判定前
        retate_anticlockwise_phase(tick_tack_toe_phase);

    return c;
}

//用于旋转棋局的函数
void retate_anticlockwise_phase(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    TICK_TACK_TOE tick_tack_toe_phase_copy[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            tick_tack_toe_phase_copy[i][j] = tick_tack_toe_phase[i][j];
    }
    tick_tack_toe_phase[0][0] = tick_tack_toe_phase_copy[0][2];
    tick_tack_toe_phase[0][1] = tick_tack_toe_phase_copy[1][2];
    tick_tack_toe_phase[0][2] = tick_tack_toe_phase_copy[2][2];
    tick_tack_toe_phase[1][0] = tick_tack_toe_phase_copy[0][1];
    tick_tack_toe_phase[1][2] = tick_tack_toe_phase_copy[2][1];
    tick_tack_toe_phase[2][0] = tick_tack_toe_phase_copy[0][0];
    tick_tack_toe_phase[2][1] = tick_tack_toe_phase_copy[1][0];
    tick_tack_toe_phase[2][2] = tick_tack_toe_phase_copy[2][0];

    return;
}

//用于上下翻转棋局的函数
void flip_upside_down_phase(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    TICK_TACK_TOE tick_tack_toe_phase_copy[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            tick_tack_toe_phase_copy[i][j] = tick_tack_toe_phase[i][j];
    }
    tick_tack_toe_phase[0][0] = tick_tack_toe_phase_copy[2][0];
    tick_tack_toe_phase[0][1] = tick_tack_toe_phase_copy[2][1];
    tick_tack_toe_phase[0][2] = tick_tack_toe_phase_copy[2][2];
    tick_tack_toe_phase[2][0] = tick_tack_toe_phase_copy[0][0];
    tick_tack_toe_phase[2][1] = tick_tack_toe_phase_copy[0][1];
    tick_tack_toe_phase[2][2] = tick_tack_toe_phase_copy[0][2];

    return;
}

//用于返回棋局情况的函数
int judge_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], int k, TICK_TACK_TOE a, TICK_TACK_TOE b)
{
    int judge_win_a_side = 0;

    switch(k)
    {
    case 0:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][2] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[2][0] == 0));
        break;
    case 1:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[2][0] == 0));
        break;
    case 2:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][0] == 0) && (tick_tack_toe_phase[2][0] == 0));
        break;
    case 3:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[1][0] == 0));
        break;
    case 4:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == b) && (tick_tack_toe_phase[1][0] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[0][2] == 0) && (tick_tack_toe_phase[2][0] == 0));
        break;
    case 5:
        judge_win_a_side = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][0] == b) && (tick_tack_toe_phase[2][0] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[0][2] == 0));
        break;
    case 6:
        judge_win_a_side = ((tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[0][1] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][2] == b) && (tick_tack_toe_phase[1][1] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[1][0] == 0) && (tick_tack_toe_phase[2][0] == 0));
        break;
    }

    return judge_win_a_side;
}
