#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//�������ϸ��ӵ��������ӳ������֣����ô���һ����Ӧ���Զ�����
typedef enum {T3N, T3X, T3O} TICK_TACK_TOE;

//��ʼ����ֵ�����
void initialization(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//����ִ�ӡ����Ļ�ϵĺ���
void output_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//�ж�����Ƿ��ڴ˲��սᲢ����ʤ�����ĺ���
int judge_win(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//ʵ������ƶ����ӵĺ���
void receive_judge_move(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//ʵ�ּ�����ͼ��ƶ�����
void computer_low_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//ʵ����ֹ��Ϸ����Ļ�ȡ����֤
int judge_player_order_end(void);

//ʵ�ּ�����м��ƶ����ӣ��������������������
void computer_middle_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//ʵ�ּ�����߼��ƶ����ӣ����׷�������׽�����
void computer_high_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//��ȡ���ѡ�����Ϸ�Ѷ�
char get_difficulty_level(void);




//���º�����Ӧ���������б�����
//���º�����Ӧ���������б�����

//����������ָ��λ�õ�����
void exchange_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE y, TICK_TACK_TOE x, TICK_TACK_TOE yy, TICK_TACK_TOE xx);

//�ж��ж��Ƿ������������������������Ľ����ĺ���
int judge_cause_flaw(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE player_piece_place_y[], TICK_TACK_TOE player_piece_place_x[], TICK_TACK_TOE judge_piece_place_y, TICK_TACK_TOE judge_piece_place_x);

//�����ж��Ƿ��Ǳ�ʤ��ֵĺ���
int judge_cause_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE a, TICK_TACK_TOE b);

//������ת���
void retate_anticlockwise_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//���ڷ�ת���
void flip_upside_down_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);
