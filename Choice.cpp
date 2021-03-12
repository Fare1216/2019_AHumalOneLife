#include "DxLib.h"
#include "Game.h"


int chara[12];
int door;
int fire;
int back;

int CharaX;
int CharaY;
int direction;
int dplus = 0;
int ccount = 0;

int TFlag;
int GPushEnter;


int Game(){
	Graph();

	LPCSTR FontGame = "Font/FZカタカタかな.otf";
	AddFontResourceEx(FontGame, FR_PRIVATE, NULL);

	ChangeFont("FZカタカタかな", DX_CHARSET_DEFAULT);
	SetFontSize(32);

	Status person;
	person.belief = 0;
	person.compassion = 0;
	person.desire = 0;
	person.discipline = 0;

	int GScene = RoadLeady;

	int RFlag = 0;
	int GEndFlag = 0;
	int PushQ = -1;


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !CheckHitKey(KEY_INPUT_Q) && GEndFlag == 0){
		DrawGraph(0, 0, back, FALSE);

		switch (GScene){

		case RoadLeady:{
			CharaX = 320-32;
			CharaY = 480-32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Road;
			break;
		}

		case Road:{
			/*----- Graph Draw -----*/
			DrawGraph(320 - 96, 64 * 0, fire, TRUE); DrawGraph(320 - 64, 64 * 0, fire, TRUE); DrawGraph(320 - 32, 64 * 0, door, TRUE); DrawGraph(320 + 32, 64 * 0, fire, TRUE); DrawGraph(320 + 64, 64 * 0, fire, TRUE);
			DrawGraph(320 - 96, 64 * 1, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 1, fire, TRUE);
			DrawGraph(320 - 96, 64 * 2, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 2, fire, TRUE);
			DrawGraph(320 - 96, 64 * 3, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 3, fire, TRUE);
			DrawGraph(320 - 96, 64 * 4, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 4, fire, TRUE);
			DrawGraph(320 - 96, 64 * 5, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 5, fire, TRUE);
			DrawGraph(320 - 96, 64 * 6, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 6, fire, TRUE);
			DrawGraph(320 - 96, 64 * 7, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 7, fire, TRUE);
			DrawGraph(320 - 96, 64 * 8, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 8, fire, TRUE);

			DrawBox(320-32, 64, 320+32, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(320 - 32, 64, 320 + 32, 96, GetColor(64, 0, 0), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 240) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "やあ、おめざめかな。");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "きみには、いくつかシツモンにこ");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "たえてもらう。");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 255, 255), "こたえなおすことはできない。");
				DrawFormatString(64, 64 + (32 * 4), GetColor(255, 255, 255), "このさきのとびらにすすんだらす");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "ぐにわかることだ。");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(320 - 64, 320 + 64, 64, 480);
			}

			if (((320 - 32) < CharaX) && (CharaX <= 320) && (CharaY <= 64)){
				GScene = RoadTwoLeady;
			}

			break;
		}

		case RoadTwoLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = RoadTwo;
			break;
		}

		case RoadTwo:{
			/*----- Graph Draw -----*/
			DrawGraph(320 - 96, 64 * 0, fire, TRUE); DrawGraph(320 - 64, 64 * 0, fire, TRUE); DrawGraph(320 - 32, 64 * 0, door, TRUE); DrawGraph(320 + 32, 64 * 0, fire, TRUE); DrawGraph(320 + 64, 64 * 0, fire, TRUE);
			DrawGraph(320 - 96, 64 * 1, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 1, fire, TRUE);
			DrawGraph(320 - 96, 64 * 2, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 2, fire, TRUE);
			DrawGraph(320 - 96, 64 * 3, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 3, fire, TRUE);
			DrawGraph(320 - 96, 64 * 4, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 4, fire, TRUE);
			DrawGraph(320 - 96, 64 * 5, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 5, fire, TRUE);
			DrawGraph(320 - 96, 64 * 6, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 6, fire, TRUE);
			DrawGraph(320 - 96, 64 * 7, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 7, fire, TRUE);
			DrawGraph(320 - 96, 64 * 8, fire, TRUE);                                                                                                                            DrawGraph(320 + 64, 64 * 8, fire, TRUE);

			DrawBox(320 - 32, 64, 320 + 32, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(320 - 32, 64, 320 + 32, 96, GetColor(64, 0, 0), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 240) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "ほら、いったとおりだろう。");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "これからのシツモンは、きみのジ");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "ンセイをきめるじゅうようなもの");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 255, 255), "だ。");
				DrawFormatString(64, 64 + (32 * 4), GetColor(255, 255, 255), "よくかんがえてからこたえていく");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "がいい。");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(320 - 64, 320 + 64, 64, 480);
			}

			if (((320 - 32) < CharaX) && (CharaX <= 320) && (CharaY <= 64)){
				GScene = Qestion_OneLeady;
			}

			break;
		}

		case Qestion_OneLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_One;
			break;
		}

		case Qestion_One:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q1");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "いちどきめたことは？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "リンキオウヘンに");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "じぶんにニゴンなどない");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.desire++;
				GScene = Qestion_TwoLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.belief++;
				GScene = Qestion_TwoLeady;
			}

			break;
		}

		case Qestion_TwoLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_Two;

			break;
		}

		case Qestion_Two:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q2");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "こまっているおばあちゃんを？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "チコクだけどたすける");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "チコクだからほおっておく");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.compassion++;
				GScene = Qestion_ThreeLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.discipline++;
				GScene = Qestion_ThreeLeady;
			}

			break;
		}

		case Qestion_ThreeLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_Three;

			break;
		}

		case Qestion_Three:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q3");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "シツケのなってないイヌを？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "アイをもってそだてる");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "ゲイをおしえこむ");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.compassion++;
				GScene = Qestion_FourLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.belief++;
				GScene = Qestion_FourLeady;
			}

			break;
		}

		case Qestion_FourLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_Four;

			break;
		}

		case Qestion_Four:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q4");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "きめられているルールは？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "まもるもの");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "やぶるもの");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.discipline++;
				GScene = Qestion_FiveLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.desire++;
				GScene = Qestion_FiveLeady;
			}

			break;
		}

		case Qestion_FiveLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_Five;

			break;
		}

		case Qestion_Five:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q5");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "しゅうだんこうどうは？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "みんなとコウドウをともに");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "わがみちをいく");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.discipline++;
				GScene = Qestion_SixLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.belief++;
				GScene = Qestion_SixLeady;
			}

			break;
		}

		case Qestion_SixLeady:{
			CharaX = 320 - 32;
			CharaY = 480 - 32;
			direction = 10;

			TFlag = 0;
			GPushEnter = 0;

			GScene = Qestion_Six;

			break;
		}

		case Qestion_Six:{
			/*----- Graph Draw -----*/
			DrawGraph(32 * 3, 64 * 0, fire, TRUE); DrawGraph(32 * 4, 64 * 0, fire, TRUE); DrawGraph(32 * 5, 64 * 0, fire, TRUE); DrawGraph(32 * 6, 64 * 0, door, TRUE); DrawGraph(32 * 8, 64 * 0, fire, TRUE); DrawGraph(32 * 9, 64 * 0, fire, TRUE);  DrawGraph(32 * 10, 64 * 0, fire, TRUE); DrawGraph(32 * 11, 64 * 0, fire, TRUE); DrawGraph(32 * 12, 64 * 0, door, TRUE); DrawGraph(32 * 14, 64 * 0, fire, TRUE); DrawGraph(32 * 15, 64 * 0, fire, TRUE); DrawGraph(32 * 16, 64 * 0, fire, TRUE);
			DrawGraph(32 * 3, 64 * 1, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 1, fire, TRUE);
			DrawGraph(32 * 3, 64 * 2, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 2, fire, TRUE);
			DrawGraph(32 * 3, 64 * 3, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 3, fire, TRUE);
			DrawGraph(32 * 3, 64 * 4, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 4, fire, TRUE);
			DrawGraph(32 * 3, 64 * 5, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 5, fire, TRUE);
			DrawGraph(32 * 3, 64 * 6, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 6, fire, TRUE);
			DrawGraph(32 * 3, 64 * 7, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 7, fire, TRUE);
			DrawGraph(32 * 3, 64 * 8, fire, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                             DrawGraph(32 * 16, 64 * 8, fire, TRUE);

			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(255, 0, 0), TRUE);
			DrawBox(32 * 6, 64, 32 * 8, 96, GetColor(64, 0, 0), FALSE);

			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 255), TRUE);
			DrawBox(32 * 12, 64, 32 * 14, 96, GetColor(0, 0, 64), FALSE);

			DrawGraph(CharaX, CharaY, chara[direction + dplus], TRUE);

			if ((CharaY == 288) && (TFlag == 0)){
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(0, 0, 0), TRUE);
				DrawBox(64, 64, 640 - 64, 480 - 64, GetColor(255, 255, 255), FALSE);

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "Q6");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "じぶんのコイビトは？");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "アカ"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "アイテをたいせつに");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "アオ"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "ジブンのおもうがままに");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enterキーをおしてすすみたま");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "え。");

				/*----- Scene Change -----*/
				if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
					TFlag = 1;
					GPushEnter = 1;
				}
				else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
					GPushEnter = 0;
				}
			}
			else{
				MoveChara(32 * 4, 32 * 16, 64, 480);
			}

			if (((32 * 6) < CharaX) && (CharaX <= (32 * 7)) && (CharaY <= 64)){
				person.compassion++;
				GScene = ResaltLeady;
			}
			if (((32 * 12) < CharaX) && (CharaX <= (32 * 13)) && (CharaY <= 64)){
				person.desire++;
				GScene = ResaltLeady;
			}

			break;
		}

		case ResaltLeady:{
			TFlag = 0;
			GPushEnter = 0;

			if ((person.belief >= person.compassion) && (person.belief >= person.desire) && (person.belief >= person.discipline)){
				if (person.belief == person.compassion == person.desire == person.discipline){
					RFlag = 1; //ありえない
				}
				else if (person.belief == person.desire == person.discipline){
					RFlag = 2;
				}
				else if (person.belief == person.compassion == person.discipline){
					RFlag = 3;
				}
				else if (person.belief == person.compassion == person.desire){
					RFlag = 4;
				}
				else if (person.belief == person.discipline){
					RFlag = 5;
				}
				else if (person.belief == person.desire){
					RFlag = 6;
				}
				else if (person.belief == person.compassion){
					RFlag = 7;
				}
				else{
					RFlag = 8;
				}
			}
			else if ((person.compassion >= person.desire) && (person.compassion >= person.discipline)){
				if (person.compassion == person.desire == person.discipline){
					RFlag = 9;
				}
				else if (person.compassion == person.desire){
					RFlag = 10;
				}
				else if (person.compassion == person.discipline){
					RFlag = 11;
				}
				else{
					RFlag = 12;
				}
			}
			else if ((person.desire >= person.discipline)){
				if (person.desire == person.discipline){
					RFlag = 13;
				}
				else{
					RFlag = 14;
				}
			}
			else{
				RFlag = 15;
			}
			

			GScene = Resalt;
			break;
		}

		case Resalt:{
			DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
			DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), FALSE);

			switch (RFlag){

			case 1:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "ここにたどりついたか。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "つうじょうのプレイであればくることはで");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "きないはずなのだが。。。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "もしつうじょうプレイでこのがめんになっ");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "たのなら、サクシャにレンラクをおねがい");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "したい。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "@Fare1216");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "ではよろしくたのむ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 2:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ジブンのなかにたしかな");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "ものをもっているようだ。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "きめられていることにたいしても、したが");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "うことがおおい。");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "ただ、ココロのどこかでは、じぶんのおも");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "うようにコウドウしたいとおもっている。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "じつにおもしろいよ。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 3:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、きめられていることにた");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "いして、したがうことがおおいようだ。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "ジブンにもタニンにも、かんようなココロ");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "でせっすることができる。");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "ジブンのなかに、ゆずることのできないた");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "しかなものももっている。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "あまいようだな。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 4:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、だれにでもかんようなコ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "コロでせっするようだ。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "ジブンのなかに、ゆずることのできないた");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "しかなものをもっている。");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "ただ、ココロのどこかでは、ジブンのよく");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "をすてきれずにいる。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "みちをあやまらないように。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 5:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ジブンのなかにゆずるこ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "とのできないたしかなものをもっているよ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "うだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "きめられていることにたいしても、はんぱ");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "つすることなくしたがってコウドウするこ");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "とがおおいようだ。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "まじめというわけだな。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 6:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ジブンのなかにゆずるこ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "とのできないたしかなものをもっているよ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "うだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "ジブンのことをとおそうとすると、まわり");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "をかんがえずうごくため、コリツしていき");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "やすい。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "まわりにあわせるヒツヨウはない。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 7:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ジブンのなかにゆずるこ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "とのできないたしかなものをもっているよ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "うだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "ジブンにもタニンにも、かんようなココロ");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "でせっしているため、まわりからシンライ");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "されやすい。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "タイセツにおもうたしかなキモチ。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 8:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ジブンのなかにゆずるこ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "とのできないたしかなものをもっているよ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "うだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "それはすさまじいものであり、ほかのすべ");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "てのようそをリョウガするほどだ。");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "っょぃ。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 9:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、だれにでもかんようなコ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "コロでせっするようだ。");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "きめられていることにたいしても、したが");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "うことがおおい。");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "ただ、ココロのどこかでは、じぶんのおも");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "うようにコウドウしたいとおもっている。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "すべてはエゴ。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 10:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255), "どうやらきみは、だれにでも、かんような");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255), "ココロでせっするため、まわりからシンラ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255), "イされるようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "しょうにんよっきゅうがつよく、つねにま");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "わりからのひょうかがないとおちついてい");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "られない。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "ひとりではいられない。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 11:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、だれにでも、かんような");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "ココロでせっするため、まわりからシンラ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "イされるようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "きめられていることにたいしても、はんぱ");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "つすることなくしたがってコウドウするこ");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "とがおおいようだ。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "みんなのためのコウドウ。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 12:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、だれにでも、かんような");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "ココロでせっするため、まわりからシンラ");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "イされるようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "すべてをうけいれることができるウツワは");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "ツワは、おおくのニンゲンのよりどころに");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "なっている。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 13:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、きめられていることにた");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "いして、はんぱつすることなくコウドウす");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "ることができるようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "まわりがしたがっていないと、むりやりに");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "でもしたがわせようとするため、いちぶか");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "らはおそれられている。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "いきすぎたどくさい。");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 14:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、ひじょうによくぶかくほ");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "んらいのニンゲンらしいシコウをしている");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "ようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "そこをのぞこうとしてもやみにのまれてい");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "くそこなしのよくのぬまは、いくらのぞん");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "でもみたされない。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			case 15:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "やあ。");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "どうやらきみは、きめられていることにた");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "いして、はんぱつすることなくコウドウす");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "ることができるようだ。");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "キハンにたいしてはギモンをもたずしたが");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "うそのすがたは、まさにジュウジュンだと");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "いえる。");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "また、きみのことをきかせてくれたまえ。");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "さらばだ。");
				break;
			}

			}

			/*----- Scene Change -----*/
			if (CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 0)){
				GPushEnter = 1;
			}
			else if (!CheckHitKey(KEY_INPUT_RETURN) && (GPushEnter == 1)){
				PushQ = 0;
				GEndFlag = 1;

				GPushEnter = 0;
			}

			break;
		}

		}

	}

	return PushQ;
}


void MoveChara(int XLeft, int XRight, int YUp, int YDown){
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_DOWN)){
			if (CheckHitKey(KEY_INPUT_LEFT)){
				if (XLeft < CharaX){
					CharaX--;
				}
				direction = 4;
			}
			if (CheckHitKey(KEY_INPUT_RIGHT)){
				if ((CharaX + 32) < XRight){
					CharaX++;
				}
				direction = 7;
			}
			if (CheckHitKey(KEY_INPUT_UP)){
				if (YUp < CharaY){
					CharaY--;
				}
				direction = 10;
			}
			if (CheckHitKey(KEY_INPUT_DOWN)){
				if ((CharaY + 32) < YDown){
					CharaY++;
				}
				direction = 1;
			}
			ccount++;
	}
	else{
		ccount = 0;
	}

	switch ((ccount / 8) % 4){
	case 0: dplus = 0; break;
	case 1: dplus = 1; break;
	case 2: dplus = 0; break;
	case 3: dplus = -1; break;
	}
}

void Graph(){
	LoadDivGraph("Graph/chara.png", 12, 3, 4, 32, 32, chara);
	door = LoadGraph("Graph/door.png");
	fire = LoadGraph("Graph/fire.png");
	back = LoadGraph("Graph/back.png");
}