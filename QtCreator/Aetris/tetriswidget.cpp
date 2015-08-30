#include <QTimerEvent>
#include <QPainter>
#include <QKeyEvent>
#include "tetriswidget.h"

//定義圖案代碼和邊界
//田字
int item1[4][4]=
{
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
 //右L
 int item2[4][4]=
 {
     {0,1,0,0},
     {0,1,0,0},
     {0,1,1,0},
     {0,0,0,0}
 };
 //左L
 int item3[4][4]=
 {
     {0,0,1,0},
     {0,0,1,0},
     {0,1,1,0},
     {0,0,0,0}
 };
 //右S
 int item4[4][4]=
 {
     {0,1,0,0},
     {0,1,1,0},
     {0,0,1,0},
     {0,0,0,0}
 };
 //左S
 int item5[4][4]=
 {
     {0,0,1,0},
     {0,1,1,0},
     {0,1,0,0},
     {0,0,0,0}
 };
 //山形
 int item6[4][4]=
 {
     {0,0,0,0},
     {0,0,1,0},
     {0,1,1,1},
     {0,0,0,0}
 };
 //長條
 int item7[4][4]=
 {
     {0,0,1,0},
     {0,0,1,0},
     {0,0,1,0},
     {0,0,1,0}
 };

 void TetrisWidget::GetBorder(int block[4][4],Border &border)
 {
     //計算上下左右邊界
     for(int i=0;i<4;i++)
         for(int j=0;j<4;j++)
             if(block[i][j]==1)
             {
                 border.dbound=i;
                 break; //直到計算到最後一行有1
              }
      for(int i=3;i>=0;i--)
          for(int j=0;j<4;j++)
              if(block[i][j]==1)
              {
                  border.ubound=i;
                  break;
              }
      for(int j=0;j<4;j++)
          for(int i=0;i<4;i++)
              if(block[i][j]==1)
              {
                  border.rbound=j;
                  break;
              }
      for(int j=3;j>=0;j--)
          for(int i=0;i<4;i++)
              if(block[i][j]==1)
              {
                  border.lbound=j;
                  break;
              }
  //    qDebug()<<cur_border.ubound<<cur_border.dbound<<cur_border.lbound<<cur_border.rbound;
  }


 void TetrisWidget::paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);
     //畫遊戲場景邊框
     painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
     painter.drawRect(MARGIN,MARGIN,AREA_COL*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE);
     //畫方塊預告
     painter.setBrush(QBrush(Qt::blue,Qt::SolidPattern));
     for(int i=0;i<4;i++)
         for(int j=0;j<4;j++)
             if(next_block[i][j]==1)
                 painter.drawRect(MARGIN*3+AREA_COL*BLOCK_SIZE+j*BLOCK_SIZE,MARGIN+i*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
     //繪製得分
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial",14));
     painter.drawText(QRect(MARGIN*3+AREA_COL*BLOCK_SIZE,MARGIN*2+4*BLOCK_SIZE,BLOCK_SIZE*4,BLOCK_SIZE*4),Qt::AlignCenter,"score: "+QString::number(score));


     //繪製下落方塊和穩定方塊,注意方塊邊線的顏色是根據setPen來的，默認黑色
     for(int i=0;i<AREA_ROW;i++)
         for(int j=0;j<AREA_COL;j++)
         {
             //繪製活動方塊
             if(game_area[i][j]==1)
             {
                 painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                 painter.drawRect(j*BLOCK_SIZE+MARGIN,i*BLOCK_SIZE+MARGIN,BLOCK_SIZE,BLOCK_SIZE);
             }
             //繪製穩定方塊
             else if(game_area[i][j]==2)
             {
                 painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
                 painter.drawRect(j*BLOCK_SIZE+MARGIN,i*BLOCK_SIZE+MARGIN,BLOCK_SIZE,BLOCK_SIZE);
             }
         }
 }

// void TetrisWidget::timerEvent(QTimerEvent *event)
// {
//     //方塊下落
//     if(event->timerId()==game_timer)
//         BlockMove(DOWN);
//     //刷新畫面
//     if(event->timerId()==paint_timer)
//         update();
// }


// void TetrisWidget::keyPressEvent(QKeyEvent *event)
// {
//     switch(event->key())
//     {
//     case Qt::Key_Up:
//         BlockMove(UP);
//         break;
//     case Qt::Key_Down:
//         BlockMove(DOWN);
//         break;
//     case Qt::Key_Left:
//         BlockMove(LEFT);
//         break;
//     case Qt::Key_Right:
//         BlockMove(RIGHT);
//         break;
//     case Qt::Key_Space:
//         BlockMove(SPACE);
//         break;
//     default:
//         break;
//     }
// }

