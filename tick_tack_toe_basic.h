#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//将棋盘上格子的三种情况映射成数字，并用创建一个相应的自定义型
typedef enum {T3N, T3X, T3O} TICK_TACK_TOE;

//初始化棋局的数组
void initialization(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//将棋局打印到屏幕上的函数
void output_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//判断棋局是否在此步终结并决出胜利方的函数
int judge_win(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//实现玩家移动棋子的函数
void receive_judge_move(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//实现计算机低级移动棋子
void computer_low_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//实现终止游戏命令的获取及验证
int judge_player_order_end(void);

//实现计算机中级移动棋子（初步防守与初步进攻）
void computer_middle_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//实现计算机高级移动棋子（进阶防守与进阶进攻）
void computer_high_move_piece(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//获取玩家选择的游戏难度
char get_difficulty_level(void);




//以下函数不应在主函数中被调用
//以下函数不应在主函数中被调用

//交换棋盘中指定位置的棋子
void exchange_tick_tack_toe_phase(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE y, TICK_TACK_TOE x, TICK_TACK_TOE yy, TICK_TACK_TOE xx);

//判断行动是否会产生破绽并撤销产生破绽的交换的函数
int judge_cause_flaw(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE player_piece_place_y[], TICK_TACK_TOE player_piece_place_x[], TICK_TACK_TOE judge_piece_place_y, TICK_TACK_TOE judge_piece_place_x);

//用于判断是否是必胜棋局的函数
int judge_cause_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], TICK_TACK_TOE a, TICK_TACK_TOE b);

//用于旋转棋局
void retate_anticlockwise_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//用于翻转棋局
void flip_upside_down_phase(TICK_TACK_TOE tick_tack_toe_phase[][3]);

//用于返回棋局情况的函数
int judge_win_a_side(TICK_TACK_TOE tick_tack_toe_phase[][3], int k, TICK_TACK_TOE a, TICK_TACK_TOE b);
