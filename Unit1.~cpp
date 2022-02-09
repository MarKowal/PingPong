//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        //spring from Top
        if(Ball->Top <= Background->Top) y = -y;
        //spring from Down
        if(Ball->Top >= Background->Height-Ball->Height) y = -y;

        //lose RedPad
        if(Ball->Left <= RedPad->Left+RedPad->Width-80) {
              TimerBall->Enabled = false;}



        //if (Ball->Top > RedPad->Top &&
       // Ball->Top < (Background->Height - (RedPad->Top + RedPad->Height))))
        //                        x=-x;




        //lose BlackPad
        if(Ball->Left > BlackPad->Left+85) {
                TimerBall->Enabled = false;}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RedUpTimer(TObject *Sender)
{
        if(RedPad->Top >= 5) RedPad->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RedDownTimer(TObject *Sender)
{
        if(RedPad->Top+RedPad->Height <= Background->Height-5) {
                RedPad->Top += 10;}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x41) RedUp->Enabled = true;
        if(Key == 0x5A) RedDown->Enabled = true;

        if(Key == VK_UP) BlackUp->Enabled = true;
        if(Key == VK_DOWN) BlackDown->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x41) RedUp->Enabled = false;
        if(Key == 0x5A) RedDown->Enabled = false;

        if(Key == VK_UP) BlackUp->Enabled = false;
        if(Key == VK_DOWN) BlackDown->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlackUpTimer(TObject *Sender)
{
        if(BlackPad->Top >= 5) BlackPad->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlackDownTimer(TObject *Sender)
{
        if(BlackPad->Top+BlackPad->Height <= Background->Height-5) {
                BlackPad->Top += 10;}
}
//---------------------------------------------------------------------------


