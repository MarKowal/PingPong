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

        //odbicie od gornej krawedzi
        if(Ball->Top <= Background->Top) y = -y;
        //odbicie od dolnej krawedzi
        if(Ball->Top >= Background->Height-Ball->Height) y = -y;

        //przegrana czerwona
        if(Ball->Left < RedPad->Left+RedPad->Width-130) {
                TimerBall->Enabled = false;
        }
         //przegrana czarna
        if(Ball->Left > BlackPad->Left+85) {
                TimerBall->Enabled = false;
        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RedUpTimer(TObject *Sender)
{
        RedPad->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RedDownTimer(TObject *Sender)
{
        RedPad->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //JAK ZROBI KLAIWSZ WIRTUALNY DLA A ORAZ Z???
}
//---------------------------------------------------------------------------

