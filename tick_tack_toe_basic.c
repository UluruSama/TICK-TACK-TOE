#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tick_tack_toe_basic.h"

//��ʼ����ֵ�����
void initialization(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    tick_tack_toe_phase[0][0] = tick_tack_toe_phase[0][2] = tick_tack_toe_phase[2][1] = 1;
    tick_tack_toe_phase[0][1] = tick_tack_toe_phase[2][0] = tick_tack_toe_phase[2][2] = 2;
    tick_tack_toe_phase[1][0] = tick_tack_toe_phase[1][1] = tick_tack_toe_phase[1][2] = 0;
}

//����ִ�ӡ����Ļ�ϵĺ���
void output_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int m, i;

    printf("     1   2   3 \n");                          //�������ӡ
    printf("    --- --- ---\n");
    for (m = 0; m < 3; m++)
        {
            switch (m)                                    //�������ӡ
            {
                case 0: printf(" A |");
                        break;
                case 1: printf(" B |");
                        break;
                case 2: printf(" C |");
                        break;
            }

            for (i = 0; i < 3; i++)
                switch (tick_tack_toe_phase[m][i])        //��ӡ����
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

//�ж�����Ƿ��ڴ˲��սᲢ����ʤ�����ĺ���
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

    if (row[0] == 1 || row[1] == 1 || row[2] == 1 || col[0] == 1 || col[1] == 1 || col[2] == 1 || diag[0] == 1 || diag[1] == 1)    //�ж�X���Ƿ��ʤ
        return 1;                                //����ֵ������һ����Ϸ���ֽ���
    else if (row[0] == 8 || row[1] == 8 || row[2] == 8 || col[0] == 8 || col[1] == 8 || col[2] == 8 || diag[0] == 8 || diag[1] == 8)  //�ж�O���Ƿ��ʤ
        return 2;                                   //����ֵ������һ����Ϸ���ֽ���
    else                        //X����O����δ��ʤ����Ϸδ����
        return 0;
}

//ʵ������ƶ����ӵĺ���
void receive_judge_move(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int i = -1;
    int x, y;
    int array_receive_judge_move_from[2], array_receive_judge_move_to[2];
    TICK_TACK_TOE m = 0;
    TICK_TACK_TOE temp;
    char order_select_piece[2];

    printf("Please select the piece you want to move. Your order must be in certain format like A2 or A2CCD (both mean A2).\n");
    while ((i == -1) || (m != 2))      //��ȡ�ƶ����ӵ���������Ϸ���
    {
        scanf("%s", order_select_piece);
        if (((order_select_piece[0] == 'A') || (order_select_piece[0] == 'B') || (order_select_piece[0] == 'C')) && ((order_select_piece[1] == '1') || (order_select_piece[1] == '2') || (order_select_piece[1] == '3')))  //�����ж���������Ƿ�Ϸ�
            i = 1;
        else
            i = -1;
        if (i == -1)                  //��������������ʱ�ķ���
            printf("What you input is not in a right format or beyond chessboard. Please enter your order again.\n");
        else
            {
                array_receive_judge_move_from[0] = (int) (order_select_piece[0] - 'A');          //���ڼ�¼��ҵ�����
                array_receive_judge_move_from[1] = (int) (order_select_piece[1] - '1');
                m = tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]];
                if (m == 0)
                    printf("What you want to move is not a piece. Please enter your order again.\n");
                if (m == 1)
                    printf("What you want to move is a piece belonging to the computer. Please input your order again.\n");
            }
    }
    i = -1;        //��ʼ���ж��ò���
    m = 0;
    printf("Please select the place you want to move to. Your order must be in certain format like A2 or A2CCD (both mean A2).\n");
    while ((i == -1) || (m != 0))         //��ȡ����ƶ����ӵ�ĳ������������Ϸ���
    {
        scanf("%s", order_select_piece);
        if (((order_select_piece[0] == 'A') || (order_select_piece[0] == 'B') || (order_select_piece[0] == 'C')) && ((order_select_piece[1] == '1') || (order_select_piece[1] == '2') || (order_select_piece[1] == '3')))  //�����ж���������Ƿ�Ϸ�
            i = 1;
        else
            i = -1;
        if (i == -1)             //����������ݲ��Ϸ�ʱ�ķ���
            printf("What you input is not in a right format or beyond chessboard. Please enter your order again.\n");
        else
        {
            array_receive_judge_move_to[0] = (int) (order_select_piece[0] - 'A');          //���ڼ�¼��ҵ�����
            array_receive_judge_move_to[1] = (int) (order_select_piece[1] - '1');
            m = tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]];
            if (m == 0)
            {
                x = array_receive_judge_move_to[0] - array_receive_judge_move_from[0];
                y = array_receive_judge_move_to[1] - array_receive_judge_move_from[1];
                if (!((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //�ж����ѡ���ƶ�����λ���Ƿ�Ϸ�
                {
                    i = -1;
                    printf("Your piece can't get to that place. Please enter your order again.\n");
                }
            }
            else
                printf("Another piece is at where you want to move your piece to. Please enter your order again.\n");
        }
    }
    while (getchar() != '\n')              //���Ļ��з�����ֹ��������������κ�������Ҫ��ȡ���������
        continue;
    temp = tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]];        //������������Ԫ�ص�ֵ���Ӷ�ʵ�������ƶ�
    tick_tack_toe_phase[array_receive_judge_move_to[0]][array_receive_judge_move_to[1]] = tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]];
    tick_tack_toe_phase[array_receive_judge_move_from[0]][array_receive_judge_move_from[1]] = temp;

    return;
}

//ʵ�ּ�����ͼ��ƶ�����
void computer_low_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3])
{
    int computer_move_from_y[3];
    int computer_move_from_x[3];   //���������������ڼ�¼����������ӵ�λ��
    int computer_move_to_y[3];
    int computer_move_to_x[3];    //���������������ڼ�¼��������ӿ��ƶ��Ŀհ�����λ��
    int i, j, k, p;
    int x, y;
    int rand_move_1, rand_move_2;
    TICK_TACK_TOE temp;

    for (i = 0, k = 0, p =0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (tick_tack_toe_phase[i][j] == 1)          //��¼����������ӵ�λ��
            {
                computer_move_from_y[k] = i;
                computer_move_from_x[k] = j;
                k++;
            }
            if (tick_tack_toe_phase[i][j] == 0)          //��¼�հ�����λ��
            {
                computer_move_to_y[p] = i;
                computer_move_to_x[p] = j;
                p++;
            }
        }
    }
    rand_move_1 = rand() % 3;              //ʵ�����
    rand_move_2 = rand() % 3;
    for (i = 0; i < 3; i++)                //ʵ���ƶ�����
    {
        rand_move_1 = (rand_move_1 + i) % 3;
        for (j = 0; j < 3; j++)
        {
            rand_move_2 = (rand_move_2 + j) % 3;
            y = computer_move_from_y[rand_move_1] - computer_move_to_y[rand_move_2];
            x = computer_move_from_x[rand_move_1] - computer_move_to_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                temp = tick_tack_toe_phase[computer_move_to_y[rand_move_2]][computer_move_to_x[rand_move_2]];
                tick_tack_toe_phase[computer_move_to_y[rand_move_2]][computer_move_to_x[rand_move_2]] = tick_tack_toe_phase[computer_move_from_y[rand_move_1]][computer_move_from_x[rand_move_1]];
                tick_tack_toe_phase[computer_move_from_y[rand_move_1]][computer_move_from_x[rand_move_1]] = temp;   //������������Ԫ�ص�ֵ���Ӷ�ʵ�������ƶ�
                goto step_one;
            }
        }
    }
    step_one: ;

    return;
}

//ʵ����ֹ��Ϸ����Ļ�ȡ����֤
int judge_player_order_end(void)
{
    char first_char;
    int player_order_end;

    if (((first_char = getchar()) == 'q') || (first_char == 'Q'))    //����������롰Q+.."��q+..�������
    {
        player_order_end = 0;
        if (getchar() != '\n')
        {
            while (getchar() != '\n')         //���Ļ��з�����ֹ�������������κ�������Ҫ��ȡ���������
                continue;
            player_order_end = 1;
        }
    }
    else       //������������������ݵ����
    {
        if (first_char == '\n')               //�������ֱ�����뻻�з������
            goto step_one;
        while (getchar() != '\n')             //���Ļ��з�����ֹ�������������κ�������Ҫ��ȡ���������
            continue;
        step_one: ;
        player_order_end = 1;
    }

    return player_order_end;
}

//ʵ�ּ�����м��ƶ����ӣ��������������������
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
            if (tick_tack_toe_phase[a][b] == 1)          //��¼����������ӵ�λ��
            {
                computer_piece_place_y[c] = a;
                computer_piece_place_x[c] = b;
                c++;
            }
            if (tick_tack_toe_phase[a][b] == 0)          //��¼�հ�����λ��
            {
                null_piece_place_y[d] = a;
                null_piece_place_x[d] = b;
                d++;
            }
            if (tick_tack_toe_phase[a][b] == 2)          //��¼��ҵ����ӵ�λ��
            {
                player_piece_place_y[e] = a;
                player_piece_place_x[e] = b;
                e++;
            }
        }
    }
    for (a = 0; a < 3; a++)                //��������
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end == 0)     //������ܻ�ʤ����������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else               //�����ʤ������ֹ����
                    goto step_1;
            }
        }
    }
    for (b = 0, c = 0; b < 3; b++)                //�������أ�һ�Σ������Ҫ���صĿհ����
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end != 0)            //��¼ģ�����ʤ��ʱ���漰�Ŀհ�����λ��
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
    for (a = 0; a < c; a++)             //�������أ����Σ�������Ӧ�հ���񲢷�ֹ�����µ�����
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    rand_move_1_1 = rand();       //ʵ�����
    rand_move_2_2 = rand();
    for (a = 0; a < c; a++)        //�������أ����Σ�����������η�����Ҫ���ص���񶼻�����������������ʱαװ��û�в��������ļ���
    {
        rand_move_1 = (rand_move_1_1 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = simu_player_win_null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_1], simu_player_win_null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //�������أ��ĶΣ�����������ص����
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                if (d == 1)               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //�������أ���Σ�������������ƶ�����������������ֵ����
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }

    step_1: ;

    return;
}

//ʵ�ּ�����߼��ƶ����ӣ����׷�������׽�����
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
            if (tick_tack_toe_phase[a][b] == 1)          //��¼����������ӵ�λ��
            {
                computer_piece_place_y[c] = a;
                computer_piece_place_x[c] = b;
                c++;
            }
            if (tick_tack_toe_phase[a][b] == 0)          //��¼�հ�����λ��
            {
                null_piece_place_y[d] = a;
                null_piece_place_x[d] = b;
                d++;
            }
            if (tick_tack_toe_phase[a][b] == 2)          //��¼��ҵ����ӵ�λ��
            {
                player_piece_place_y[e] = a;
                player_piece_place_x[e] = b;
                e++;
            }
        }
    }
    for (a = 0; a < 3; a++)                //���׽�����һ�Σ�����������һ��ֱ�ӻ��ʤ�������
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end == 0)     //������ܻ�ʤ����������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else               //�����ʤ������ֹ����
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)             //���׽��������Σ�����������һ�ֻ��ʤ������������ų�����ֱ�ӻ�ʤ�����ڶԷ���һ��ʧ�ܵ��������������ٵó�������һ�ֻ�ʤ����ֵļ�����Է���һ�ֻ�ʤ����ֵļ��ϵĽ���Ϊ�ռ�
    {
        for (b = 0; b < 3; b++)
        {
            y = computer_piece_place_y[a] - null_piece_place_y[b];
            x = computer_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                if (!(judge_cause_win_a_side(tick_tack_toe_phase, 1, 2)))
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], computer_piece_place_y[a], computer_piece_place_x[a]);
                else
                    goto step_1;
            }
        }
    }
    for (b = 0, c = 0; b < 3; b++)                //���׷��أ�һ�Σ���⼱����Ҫ���صĿհ���񣨵�һ��������
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                judge_end = judge_win(tick_tack_toe_phase);
                if (judge_end != 0)            //��¼ģ�����ʤ��ʱ���漰�Ŀհ�����λ��
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
    for (b = 0, d = 0; b < 3; b++)                //���׷��أ����Σ������ܻᵼ�¶����ڵڶ��ֻ�ʤ�Ŀհ���񣨵ڶ���������
    {
        for (a = 0; a < 3; a++)
        {
            y = player_piece_place_y[a] - null_piece_place_y[b];
            x = player_piece_place_x[a] - null_piece_place_x[b];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[b], null_piece_place_x[b], player_piece_place_y[a], player_piece_place_x[a]);
                if (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1))            //��¼ģ�����ʤ��ʱ���漰�Ŀհ�����λ��
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
    //�����Դ���������Ҫ���صĿհ���������Լ��޷����ص������Ϊ�˱��գ�������������������������ڱ��˺�������
    for (a = 0; a < c; a++)             //���׷��أ����Σ����ؼ�����Ҫ���ص���񲢷�ֹ������һ��͵ڶ�������
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if ((d == 1) || (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1)))               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    for (a = 0; a < c; a++)             //���׷��أ��ĶΣ�������Ӧ�հ���񲢷�ֹ������һ������
    {
        rand_move_3 = (rand_move_3_3 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_3], simu_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    rand_move_1_1 = rand();       //ʵ�����
    rand_move_2_2 = rand();
    for (a = 0; a < c; a++)        //���׷��أ���Σ�����������η�����Ҫ���ص���񶼻������һ���������������ʱαװ��û�в�����Ӧ�����ļ���
    {
        rand_move_1 = (rand_move_1_1 + a) % c;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = simu_player_win_null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = simu_player_win_null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_player_win_null_piece_place_y[rand_move_1], simu_player_win_null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    for (a = 0; a < d; a++)             //���׷��أ����Σ���϶Է��ں����ֻ��ʤ�����ڷ���ʱ��ֹ�����µ�����
    {
        rand_move_3 = (rand_move_3_3 + a) % d;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_1_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_1_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if ((d == 1) || (judge_cause_win_a_side(tick_tack_toe_phase, 2, 1)))               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    for (a = 0; a < d; a++)             //���׷��أ��߶Σ��޷���Ϸ��ضԷ��ں����ֻ��ʤ��ʱ�����ڶ���������αװ��δ������Ӧ�����ļ���
    {
        rand_move_3 = (rand_move_3_3 + a) % d;
        for (b = 0; b < 3; b++)
        {
            rand_move_4 = (rand_move_4_4 + b) % 3;
            y = simu_1_player_win_null_piece_place_y[rand_move_3] - computer_piece_place_y[rand_move_4];
            x = simu_1_player_win_null_piece_place_x[rand_move_3] - computer_piece_place_x[rand_move_4];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                if (d == 1)               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, simu_1_player_win_null_piece_place_y[rand_move_3], simu_1_player_win_null_piece_place_x[rand_move_3], computer_piece_place_y[rand_move_4], computer_piece_place_x[rand_move_4]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //���׷��أ��˶Σ�����������ص����
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                d = judge_cause_flaw(tick_tack_toe_phase, player_piece_place_y, player_piece_place_x, computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                if (d == 1)               //������������������
                    exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                else                    //������������������ֹʣ�ಽ��
                    goto step_1;
            }
        }
    }
    for (a = 0; a < 3; a++)        //���׷��أ��ŶΣ�������������ƶ�����������������ֵ�������������������������֣��������������Ӧ���룩
    {
        rand_move_1 = (rand_move_1_1 + a) % 3;
        for (b = 0; b < 3; b++)
        {
            rand_move_2 = (rand_move_2_2 + b) % 3;
            y = null_piece_place_y[rand_move_1] - computer_piece_place_y[rand_move_2];
            x = null_piece_place_x[rand_move_1] - computer_piece_place_x[rand_move_2];
            if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
            {
                exchange_tick_tack_toe_phase(tick_tack_toe_phase, null_piece_place_y[rand_move_1], null_piece_place_x[rand_move_1], computer_piece_place_y[rand_move_2], computer_piece_place_x[rand_move_2]);
                goto step_1;
            }
        }
    }
    step_1:;

    return;
}

//��ȡ���ѡ�����Ϸ�Ѷ�
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



//���º�����Ӧ���������б�����
//���º�����Ӧ���������б�����

//����������ָ��λ�õ�����
void exchange_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE y, TICK_TACK_TOE x, TICK_TACK_TOE yy, TICK_TACK_TOE xx)
{
    TICK_TACK_TOE temp;

    temp = tick_tack_toe_phase[y][x];
    tick_tack_toe_phase[y][x] = tick_tack_toe_phase[yy][xx];
    tick_tack_toe_phase[yy][xx] = temp;

    return;
}

//�ж��ж��Ƿ������������������������Ľ����ĺ���
int judge_cause_flaw(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE player_piece_place_y[], TICK_TACK_TOE player_piece_place_x[], TICK_TACK_TOE judge_piece_place_y, TICK_TACK_TOE judge_piece_place_x)
{
    int a, x, y;
    int judge_end, d;

    for (a = 0; a < 3; a++)             //�жϴ˷����Ƿ������µ�����
    {
        y = player_piece_place_y[a] - judge_piece_place_y;
        x = player_piece_place_x[a] - judge_piece_place_x;
        if (((((x == 1) || (x == -1)) && (y == 0)) || (((y == 1) || (y == -1)) && (x == 0)) || ((x * y == 1) ||(x * y == -1))))  //ѡ���Ϸ����ƶ���ʽ
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

//�����ж��Ƿ��Ǳ�ʤ��ֵĺ���
int judge_cause_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE a, TICK_TACK_TOE b)
{
    int k, i, j;
    int c = 0;
    int judge_win_a_side_array[7];

    judge_win_a_side_array[0] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][2] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[2][0] == 0));
    judge_win_a_side_array[1] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[2][0] == 0));
    judge_win_a_side_array[2] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[0][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][0] == 0) && (tick_tack_toe_phase[2][0] == 0));
    judge_win_a_side_array[3] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[1][0] == 0));
    judge_win_a_side_array[4] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][1] == b) && (tick_tack_toe_phase[1][0] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[0][2] == 0) && (tick_tack_toe_phase[2][0] == 0));
    judge_win_a_side_array[5] = ((tick_tack_toe_phase[1][1] == a) && (tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[1][0] == b) && (tick_tack_toe_phase[2][0] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[0][1] == 0) && (tick_tack_toe_phase[0][2] == 0));
    judge_win_a_side_array[6] = ((tick_tack_toe_phase[1][2] == a) && (tick_tack_toe_phase[0][1] == a) && (tick_tack_toe_phase[2][1] == a) && (tick_tack_toe_phase[0][2] == b) && (tick_tack_toe_phase[1][1] == b) && (tick_tack_toe_phase[2][2] == b) && (tick_tack_toe_phase[0][0] == 0) && (tick_tack_toe_phase[1][0] == 0) && (tick_tack_toe_phase[2][0] == 0));
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 4; i++)
        {
            if (judge_win_a_side_array[k])
            {
                c = 1;
                goto step_1;
            }
            flip_upside_down_phase(tick_tack_toe_phase);   //�����ж���ת�������ķ�ת����
            if (judge_win_a_side_array[k])
            {
                flip_upside_down_phase(tick_tack_toe_phase);  //������ת����
                c = 1;
                goto step_1;
            }
            flip_upside_down_phase(tick_tack_toe_phase);      //������ת����
            retate_anticlockwise_phase(tick_tack_toe_phase);   //Ϊ��һ��ѭ������ת
        }
    }

    step_1:;
    for (j = 0; j < 4 - i; j++)                 //����ֵ����黹ԭ���ж�ǰ
        retate_anticlockwise_phase(tick_tack_toe_phase);

    return c;
}

//������ת��ֵĺ���
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

//�������·�ת��ֵĺ���
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
