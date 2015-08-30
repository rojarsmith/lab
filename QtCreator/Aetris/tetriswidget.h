#ifndef TETRISWIDGET
#define TETRISWIDGET

#include <QWidget>

//場景數據
const int BLOCK_SIZE=25; //單個方塊單元的邊長
const int MARGIN=5 ; //場景邊距
const int AREA_ROW=20; //場景行數
const int AREA_COL=12; //場景列數

//方向
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

//定義邊界
struct Border
{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

//坐標
struct block_point
{
    int pos_x;
    int pos_y;
    //    block_point(int x,int y):pos_x(x),pos_y(y){}
};

namespace Ui {
class TetrisWidget;
}

class TetrisWidget : public QWidget
{
    Q_OBJECT

public:
    void InitGame(); //初始化
    void StartGame(); //開始遊戲
    void GameOver(); //遊戲結束

    void ResetBlock(); //重置方塊
    void BlockMove(Direction dir); //方塊變動
    void BlockRotate(int block[4][4]); //方塊旋轉
    void CreateBlock(int block[4][4],int block_id); //產生方塊
    void GetBorder(int block[4][4],Border &border); //計算邊界
    void ConvertStable(int x,int y); //轉換為穩定方塊
    bool IsCollide(int x,int y,Direction dir); //判斷是否會碰撞

public:
    explicit TetrisWidget(QWidget *parent = 0);
    ~TetrisWidget();

    virtual void paintEvent(QPaintEvent *event); //場景刷新
    virtual void timerEvent(QTimerEvent *event); //定時器事件
    virtual void keyPressEvent(QKeyEvent *event); //鍵盤響應

private:
    Ui::TetrisWidget *ui;

private:
    int game_area[AREA_ROW][AREA_COL]; //場景區域，1表示活動的方塊，2表示穩定的方塊，0表示空
    block_point block_pos; //當前方塊坐標
    int cur_block[4][4]; //當前方塊形狀
    Border cur_border; //當前方塊邊界
    int next_block[4][4]; //下一個方塊形狀
    int score;  //遊戲分數
    int game_timer; //方塊下落計時器
    int paint_timer; //渲染刷新計時器
    int speed_ms; //下落時間間隔
    int refresh_ms; //刷新時間間隔
};

#endif // TETRISWIDGET

