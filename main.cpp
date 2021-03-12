#include "DxLib.h"
#include "Game.h"


int Scene = TitleLeady;
int EndFlag = 0;

char String[256] = "";
int InputHandle;

int Move_Tri = 0;	// Use Cursor Move
int PushArrow = 0;	// Use Check Hit Arrow
int PushEnter = 0;	// Use Check Hit Enter
int CheckPushQ;
int IntoGame;

int FontSize = 32;
int Count = 0;



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	InputHandle = MakeKeyInput(50, FALSE, FALSE, FALSE);
	SetActiveKeyInput(InputHandle);

	LPCSTR FontTitle = "Font/glyphabet_0.otf";
	AddFontResourceEx(FontTitle, FR_PRIVATE, NULL);


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE) && EndFlag == 0){


		switch (Scene){

		case TitleLeady:{
			ChangeFont("IngressGlyphabet", DX_CHARSET_DEFAULT);
			SetFontSize(64);

			Move_Tri = 0;
			PushArrow = 0;
			PushEnter = 0;

			Scene = Title;
			break;
		}

		case Title:{
			/*----- Title Print -----*/
			DrawFormatString( 0, 32, GetColor( 255, 255, 255), "A Human");
			DrawFormatString( 192, 96, GetColor(255, 255, 255), "One Life");

			DrawFormatString(64, 300, GetColor(255, 255, 255), "Start");
			DrawFormatString(64, 364, GetColor(255, 255, 255), "End");

			/*----- Cursor Move -----*/
			if ((CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_UP)) && (PushArrow == 0)){
				if (CheckHitKey(KEY_INPUT_DOWN)){
					if (Move_Tri == 0){
						Move_Tri = 1;
					}
					else{
						Move_Tri = 0;
					}
				}
				if (CheckHitKey(KEY_INPUT_UP)){
					if (Move_Tri == 0){
						Move_Tri = 1;
					}
					else{
						Move_Tri = 0;
					}
				}
				PushArrow = 1;
			}
			else if (!(CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_UP)) && (PushArrow == 1)){
				PushArrow = 0;
			}

			/*----- Cursor Print -----*/
			if (!Move_Tri){
				DrawFormatString(0, 300, GetColor(255, 255, 255), "O");
			}
			else{
				DrawFormatString(0, 364, GetColor(255, 255, 255), "O");
			}

			/*----- Scene Change -----*/
			if (CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 0)){
				PushEnter = 1;
			}
			else if (!CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 1)){
				if (Move_Tri == 0){
					Scene = SerialLeady;
				}
				else{
					Scene = EndLeady;
				}

				PushEnter = 0;
			}

			break;
		}

		case SerialLeady:{
			SetFontSize(32);

			InputHandle = MakeKeyInput(50, FALSE, FALSE, FALSE);
			SetActiveKeyInput(InputHandle);

			Move_Tri = 0;
			PushArrow = 0;
			PushEnter = 0;

			FontSize = 32;
			Count = 0;

			Scene = Serial;
			break;
		}

		case Serial:{
			/*----- Print String -----*/
			DrawFormatString(0, 0, GetColor(255, 255, 255), "Type for your name");
			DrawFormatString(0, 32, GetColor(255, 255, 255), "(Alphabet)");

			DrawKeyInputModeString(640, 480);
			DrawKeyInputString(0, 128, InputHandle);

			/*----- Input String -----*/
			if (CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 0)){
				PushEnter = 1;
			}
			else if (!CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 1)){
				GetKeyInputString(String, InputHandle);
				DeleteKeyInput(InputHandle);

				PushEnter = 0;
				Scene = CheckSerial;
			}

			break;
		}

		case CheckSerial:{
			/*----- Print String -----*/
			DrawFormatString(0, 0, GetColor(255, 255, 255), "This is your name?");

			SetFontSize(FontSize);
			DrawFormatString(64, 64, GetColor(255, 255, 255), "%s", String);

			SetFontSize(32);
			DrawFormatString(96, 364, GetColor(255, 255, 255), "Yes");
			DrawFormatString(448, 364, GetColor(255, 255, 255), "No");

			/*----- Cursor Move -----*/
			if ((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)) && (PushArrow == 0)){
				if (CheckHitKey(KEY_INPUT_LEFT)){
					if (Move_Tri == 0){
						Move_Tri = 1;
					}
					else{
						Move_Tri = 0;
					}
				}
				if (CheckHitKey(KEY_INPUT_RIGHT)){
					if (Move_Tri == 0){
						Move_Tri = 1;
					}
					else{
						Move_Tri = 0;
					}
				}
				PushArrow = 1;
			}
			else if (!(CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)) && (PushArrow == 1)){
				PushArrow = 0;
			}

			/*----- Cursor Print -----*/
			if (!Move_Tri){
				DrawFormatString(64, 364, GetColor(255, 255, 255), "O");
			}
			else{
				DrawFormatString(416, 364, GetColor(255, 255, 255), "O");
			}

			/*----- Scene Change -----*/
			if (CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 0)){
				PushEnter = 1;
			}
			else if (!CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 1)){
				if (Move_Tri == 0){
					Scene = GameMainLeady;
				}
				else{
					Scene = SerialLeady;
				}

				PushEnter = 0;
			}

			/*----- Expansion Font -----*/
			if (FontSize <= 256){
				if (Count == 3){
					FontSize++;
					Count = 0;
				}
				Count++;
			}

			break;
		}

		case GameMainLeady:{
			CheckPushQ = 0;
			IntoGame = 0;

			Scene = GameMain;
			break;
		}

		case GameMain:{
			if (IntoGame == 0){
				CheckPushQ = Game();
				IntoGame = 1;
			}

			if (CheckPushQ == -1){
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "けっかをただしくしゅとくできませんでし");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "た。");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "Enterキーでタイトルにもどります。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 0)){
					PushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (PushEnter == 1)){
					Scene = TitleLeady;
					PushEnter = 0;
				}
			}
			else{
				Scene = TitleLeady;
			}

			break;
		}

		case EndLeady:{

			Scene = End;
			break;
		}

		case End:{

			EndFlag = 1;
			break;
		}

		}

	}


	DxLib_End(); // DXライブラリ終了処理
	return 0;

}