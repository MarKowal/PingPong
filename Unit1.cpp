//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong *PingPong;

int x = 5;
int y = 5;
int RedPoint = 0;
int BlackPoint = 0;
int springingNumbers = 0;

//---------------------------------------------------------------------------
__fastcall TPingPong::TPingPong(TComponent* Owner)
        : TForm(Owner)
{
        PingPong->Visible = false;
        Ball->Top = Background->Height/3;
        Ball->Left = Background->Width/2;
        RedPad->Top = Background->Height/3;
        RedPad->Left = Background->Width-Background->Width+15;
        BlackPad->Top = Background->Height/3;
        BlackPad->Left =  Background->Width-RedPad->Width-15;
        Score->Visible = false;
        SpringingNumber->Visible = false;
        RedScorePoint->Visible = false;
        BlackScorePoint->Visible = false;
        NextRound->Visible = false;
        QuitGame->Visible = true;
        MediaPlayer1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::TimerBallTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        //springing from Top
        if(Ball->Top-5 <= Background->Top) y = -y;

        //springing from Down
        if(Ball->Top-5 >= Background->Height-Ball->Height) y = -y;

        //lose RedPad
        if(Ball->Left+Ball->Width/2 <= RedPad->Left+RedPad->Width/5) {
                MediaPlayer1->Play();
                BlackPoint += 1;
                TimerBall->Enabled = false;
                NewGame->Visible = true;
                Score->Caption = "Score "+IntToStr(RedPoint)+" : "+IntToStr(BlackPoint);
                Score->Visible = true;
                SpringingNumber->Caption = "Springings "+IntToStr(springingNumbers);
                SpringingNumber->Visible = true;
                BlackScorePoint->Visible = true;
                NextRound->Visible = true;
                QuitGame->Visible = true;
                }     //ZAMIENIC NA JEDEN KOD !!!!!!!!!!

        //springing from RedPad
        if(Ball->Top+Ball->Height/2 >= RedPad->Top
                && Ball->Top+Ball->Height/2 <= RedPad->Top+RedPad->Height
                && Ball->Left+Ball->Width/2 <= RedPad->Left+RedPad->Width/2) {
                x = -x;
                springingNumbers = springingNumbers+1;}

        //lose BlackPad
        if(Ball->Left+Ball->Width/2 >= BlackPad->Left+BlackPad->Width*4/5) {
                MediaPlayer1->Play();
                RedPoint += 1;
                TimerBall->Enabled = false;
                NewGame->Visible = true;
                Score->Caption = "Score "+IntToStr(RedPoint)+" : "+IntToStr(BlackPoint);
                Score->Visible = true;
                SpringingNumber->Caption = "Springings "+IntToStr(springingNumbers);
                SpringingNumber->Visible = true;
                RedScorePoint->Visible = true;
                NextRound->Visible = true;
                QuitGame->Visible = true;
                }

        //springing from BlackPad
        if(Ball->Top+Ball->Height/2 >= BlackPad->Top
                && Ball->Top+Ball->Height/2 <= BlackPad->Top+BlackPad->Height
                && Ball->Left+Ball->Width/2 >= BlackPad->Left+BlackPad->Width/2) {
                x = -x;
                springingNumbers = springingNumbers+1;}
}
//---------------------------------------------------------------------------


void __fastcall TPingPong::RedUpTimer(TObject *Sender)
{
        if(RedPad->Top >= 5) RedPad->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::RedDownTimer(TObject *Sender)
{
        if(RedPad->Top+RedPad->Height <= Background->Height-5) {
                RedPad->Top += 10;}
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x41) RedUp->Enabled = true;
        if(Key == 0x5A) RedDown->Enabled = true;

        if(Key == VK_UP) BlackUp->Enabled = true;
        if(Key == VK_DOWN) BlackDown->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 0x41) RedUp->Enabled = false;
        if(Key == 0x5A) RedDown->Enabled = false;

        if(Key == VK_UP) BlackUp->Enabled = false;
        if(Key == VK_DOWN) BlackDown->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::BlackUpTimer(TObject *Sender)
{
        if(BlackPad->Top >= 5) BlackPad->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::BlackDownTimer(TObject *Sender)
{
        if(BlackPad->Top+BlackPad->Height <= Background->Height-5) {
                BlackPad->Top += 10;}
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::NewGameClick(TObject *Sender)
{
        NewGame->Visible = false;
        Title->Visible = false;
        Score->Visible = false;
        SpringingNumber->Visible = false;
        RedScorePoint->Visible = false;
        BlackScorePoint->Visible = false;
        NextRound->Visible = false;
        TimerBall->Enabled = true;
        Ball->Top = Background->Height/3;
        Ball->Left = Background->Width/2;
        RedPad->Top = Background->Height/3;
        RedPad->Left = Background->Width-Background->Width+15;
        BlackPad->Top = Background->Height/3;
        BlackPad->Left =  Background->Width-RedPad->Width-15;
        RedPoint = 0;
        BlackPoint = 0;
        springingNumbers = 0;
        QuitGame->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::NextRoundClick(TObject *Sender)
{
        NewGame->Visible = false;
        Title->Visible = false;
        Score->Visible = false;
        SpringingNumber->Visible = false;
        RedScorePoint->Visible = false;
        BlackScorePoint->Visible = false;
        NextRound->Visible = false;
        TimerBall->Enabled = true;
        Ball->Top = Background->Height/3;
        Ball->Left = Background->Width/2;
        RedPad->Top = Background->Height/3;
        RedPad->Left = Background->Width-Background->Width+15;
        BlackPad->Top = Background->Height/3;
        BlackPad->Left =  Background->Width-RedPad->Width-15;
        springingNumbers = 0;
        QuitGame->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::QuitGameClick(TObject *Sender)
{
        InitialWindow->Close();
        PingPong->Close();
}
//---------------------------------------------------------------------------



