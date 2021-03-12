/*===== Scene =====*/
typedef enum{
	TitleLeady,
	Title,
	SerialLeady,
	Serial,
	CheckSerial,
	GameMainLeady,
	GameMain,
	EndLeady,
	End,
}eScene;

/*===== GameScene =====*/
typedef enum{
	RoadLeady,
	Road,
	RoadTwoLeady,
	RoadTwo,
	Qestion_OneLeady,
	Qestion_One,
	Qestion_TwoLeady,
	Qestion_Two,
	Qestion_ThreeLeady,
	Qestion_Three,
	Qestion_FourLeady,
	Qestion_Four,
	Qestion_FiveLeady,
	Qestion_Five,
	Qestion_SixLeady,
	Qestion_Six,
	ResaltLeady,
	Resalt,
}eGameScene;


/*----- main.cpp -----*/
int Game();


/*----- Choice.cpp -----*/
typedef struct{
	int belief; //êMîO
	int discipline; //ãKó•
	int compassion; //éúà§
	int desire; //ó~ñ]
}Status;

void MoveChara(int XLeft, int XRight, int YUp, int YDown);
void Graph();