//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TPingPong : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TTimer *TimerBall;
        TImage *RedPad;
        TImage *Ball;
        TImage *BlackPad;
        TTimer *RedUp;
        TTimer *RedDown;
        TTimer *BlackUp;
        TTimer *BlackDown;
        TButton *NewGame;
        TLabel *Title;
        TLabel *Score;
        TLabel *SpringingNumber;
        TLabel *RedScorePoint;
        TLabel *BlackScorePoint;
        TButton *NextRound;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall RedUpTimer(TObject *Sender);
        void __fastcall RedDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BlackUpTimer(TObject *Sender);
        void __fastcall BlackDownTimer(TObject *Sender);
        void __fastcall NewGameClick(TObject *Sender);
        void __fastcall NextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPong *PingPong;
//---------------------------------------------------------------------------
#endif
 