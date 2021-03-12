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

	LPCSTR FontGame = "Font/FZ�J�^�J�^����.otf";
	AddFontResourceEx(FontGame, FR_PRIVATE, NULL);

	ChangeFont("FZ�J�^�J�^����", DX_CHARSET_DEFAULT);
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

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "�₠�A���߂��߂��ȁB");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���݂ɂ́A�������V�c�����ɂ�");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "�����Ă��炤�B");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 255, 255), "�������Ȃ������Ƃ͂ł��Ȃ��B");
				DrawFormatString(64, 64 + (32 * 4), GetColor(255, 255, 255), "���̂����̂Ƃт�ɂ����񂾂炷");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "���ɂ킩�邱�Ƃ��B");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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

				DrawFormatString(64, 64 + (32 * 0), GetColor(255, 255, 255), "�ق�A�������Ƃ��肾�낤�B");
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���ꂩ��̃V�c�����́A���݂̃W");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "���Z�C�����߂邶�イ�悤�Ȃ���");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 255, 255), "���B");
				DrawFormatString(64, 64 + (32 * 4), GetColor(255, 255, 255), "�悭���񂪂��Ă��炱�����Ă���");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "�������B");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "�����ǂ��߂����Ƃ́H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�����L�I�E�w����");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "���Ԃ�Ƀj�S���ȂǂȂ�");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���܂��Ă��邨�΂��������H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�`�R�N�����ǂ�������");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "�`�R�N������ق����Ă���");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "�V�c�P�̂Ȃ��ĂȂ��C�k���H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�A�C�������Ă����Ă�");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "�Q�C������������");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���߂��Ă��郋�[���́H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�܂������");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "��Ԃ����");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���イ���񂱂��ǂ��́H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�݂�ȂƃR�E�h�E���Ƃ���");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "�킪�݂�������");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
				DrawFormatString(64, 64 + (32 * 1), GetColor(255, 255, 255), "���Ԃ�̃R�C�r�g�́H");
				DrawFormatString(64, 64 + (32 * 2), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 3), GetColor(255, 0, 0), "�A�J"); DrawFormatString(128, 64 + (32 * 3), GetColor(255, 255, 255), "�A�C�e����������");
				DrawFormatString(64, 64 + (32 * 4), GetColor(0, 0, 255), "�A�I"); DrawFormatString(128, 64 + (32 * 4), GetColor(255, 255, 255), "�W�u���̂��������܂܂�");
				DrawFormatString(64, 64 + (32 * 5), GetColor(255, 255, 255), "");
				DrawFormatString(64, 64 + (32 * 6), GetColor(255, 255, 255), "Enter�L�[�������Ă����݂���");
				DrawFormatString(64, 64 + (32 * 7), GetColor(255, 255, 255), "���B");

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
					RFlag = 1; //���肦�Ȃ�
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
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�����ɂ��ǂ�������B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�����傤�̃v���C�ł���΂��邱�Ƃ͂�");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "���Ȃ��͂��Ȃ̂����B�B�B");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "���������傤�v���C�ł��̂��߂�ɂȂ�");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "���̂Ȃ�A�T�N�V���Ƀ������N�����˂���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�������B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "@Fare1216");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�ł͂�낵�����̂ށB");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 2:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�W�u���̂Ȃ��ɂ�������");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "���̂������Ă���悤���B");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "���߂��Ă��邱�Ƃɂ������Ă��A������");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�����Ƃ��������B");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�����A�R�R���̂ǂ����ł́A���Ԃ�̂���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "���悤�ɃR�E�h�E�������Ƃ������Ă���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "���ɂ������낢��B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 3:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A���߂��Ă��邱�Ƃɂ�");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�����āA�����������Ƃ��������悤���B");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�W�u���ɂ��^�j���ɂ��A����悤�ȃR�R��");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�ł������邱�Ƃ��ł���B");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�W�u���̂Ȃ��ɁA�䂸�邱�Ƃ̂ł��Ȃ���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�����Ȃ��̂������Ă���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "���܂��悤���ȁB");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 4:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A����ɂł�����悤�ȃR");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�R���ł�������悤���B");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�W�u���̂Ȃ��ɁA�䂸�邱�Ƃ̂ł��Ȃ���");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�����Ȃ��̂������Ă���B");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�����A�R�R���̂ǂ����ł́A�W�u���̂悭");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�����Ă��ꂸ�ɂ���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�݂�������܂�Ȃ��悤�ɁB");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 5:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�W�u���̂Ȃ��ɂ䂸�邱");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�Ƃ̂ł��Ȃ��������Ȃ��̂������Ă����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�����B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "���߂��Ă��邱�Ƃɂ������Ă��A�͂��");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "���邱�ƂȂ����������ăR�E�h�E���邱");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�Ƃ��������悤���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�܂��߂Ƃ����킯���ȁB");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 6:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�W�u���̂Ȃ��ɂ䂸�邱");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�Ƃ̂ł��Ȃ��������Ȃ��̂������Ă����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�����B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�W�u���̂��Ƃ��Ƃ������Ƃ���ƁA�܂��");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�����񂪂������������߁A�R���c���Ă���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�₷���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�܂��ɂ��킹��q�c���E�͂Ȃ��B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 7:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�W�u���̂Ȃ��ɂ䂸�邱");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�Ƃ̂ł��Ȃ��������Ȃ��̂������Ă����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�����B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�W�u���ɂ��^�j���ɂ��A����悤�ȃR�R��");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�ł������Ă��邽�߁A�܂�肩��V�����C");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "����₷���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�^�C�Z�c�ɂ������������ȃL���`�B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 8:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�W�u���̂Ȃ��ɂ䂸�邱");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�Ƃ̂ł��Ȃ��������Ȃ��̂������Ă����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�����B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "����͂����܂������̂ł���A�ق��̂���");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�Ă̂悤���������E�K����قǂ��B");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "���傡�B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 9:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A����ɂł�����悤�ȃR");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�R���ł�������悤���B");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "���߂��Ă��邱�Ƃɂ������Ă��A������");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�����Ƃ��������B");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�����A�R�R���̂ǂ����ł́A���Ԃ�̂���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "���悤�ɃR�E�h�E�������Ƃ������Ă���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "���ׂĂ̓G�S�B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 10:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255), "�ǂ���炫�݂́A����ɂł��A����悤��");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255), "�R�R���ł������邽�߁A�܂�肩��V����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255), "�C�����悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "���傤�ɂ������イ���悭�A�˂ɂ�");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "��肩��̂Ђ傤�����Ȃ��Ƃ������Ă�");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "���Ȃ��B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�ЂƂ�ł͂����Ȃ��B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 11:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A����ɂł��A����悤��");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�R�R���ł������邽�߁A�܂�肩��V����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�C�����悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "���߂��Ă��邱�Ƃɂ������Ă��A�͂��");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "���邱�ƂȂ����������ăR�E�h�E���邱");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�Ƃ��������悤���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�݂�Ȃ̂��߂̃R�E�h�E�B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 12:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A����ɂł��A����悤��");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�R�R���ł������邽�߁A�܂�肩��V����");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�C�����悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "���ׂĂ���������邱�Ƃ��ł���E�c����");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�c���́A�������̃j���Q���̂��ǂ����");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�Ȃ��Ă���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 13:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A���߂��Ă��邱�Ƃɂ�");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�����āA�͂�ς��邱�ƂȂ��R�E�h�E��");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�邱�Ƃ��ł���悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�܂�肪���������Ă��Ȃ��ƁA�ނ����");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�ł��������킹�悤�Ƃ��邽�߁A�����Ԃ�");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "��͂�������Ă���B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "�����������ǂ������B");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 14:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A�Ђ��傤�ɂ悭�Ԃ�����");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "��炢�̃j���Q���炵���V�R�E�����Ă���");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�������̂������Ƃ��Ă���݂ɂ̂܂�Ă�");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�������Ȃ��̂悭�̂ʂ܂́A������̂���");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "�ł��݂�����Ȃ��B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
				break;
			}

			case 15:{
				DrawFormatString(0, 32 * 0, GetColor(255, 255, 255),  "�₠�B");
				DrawFormatString(0, 32 * 1, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 2, GetColor(255, 255, 255),  "�ǂ���炫�݂́A���߂��Ă��邱�Ƃɂ�");
				DrawFormatString(0, 32 * 3, GetColor(255, 255, 255),  "�����āA�͂�ς��邱�ƂȂ��R�E�h�E��");
				DrawFormatString(0, 32 * 4, GetColor(255, 255, 255),  "�邱�Ƃ��ł���悤���B");
				DrawFormatString(0, 32 * 5, GetColor(255, 255, 255),  "�L�n���ɂ������Ă̓M������������������");
				DrawFormatString(0, 32 * 6, GetColor(255, 255, 255),  "�����̂������́A�܂��ɃW���E�W��������");
				DrawFormatString(0, 32 * 7, GetColor(255, 255, 255),  "������B");
				DrawFormatString(0, 32 * 8, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 9, GetColor(255, 255, 255),  "");
				DrawFormatString(0, 32 * 10, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 11, GetColor(255, 255, 255), "�܂��A���݂̂��Ƃ��������Ă��ꂽ�܂��B");
				DrawFormatString(0, 32 * 12, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 13, GetColor(255, 255, 255), "");
				DrawFormatString(0, 32 * 14, GetColor(255, 255, 255), "����΂��B");
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