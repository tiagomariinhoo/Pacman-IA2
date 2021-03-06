#include <allegro.h>
#include <bits/stdc++.h>
//#include <time.h>
//#include <stdio.h>
//#include <stdlib.h>
#define MAX_X 555
#define MAX_Y 515
#define MIN_XY 15
//#define VELOCIDADE 10 //quanto menor, mais r�pido
//#define VELOCIDADE_FANTASMA 7
#define VELOCIDADE_SPRITE 100
//#define ATT_QUADRANTE 1000
#define DIREITA 0
#define ESQUERDA 1
#define CIMA 2
#define BAIXO 3

using namespace std;

typedef struct ghost{
    int x;
    int y;
    int xp;
    int yp;

    int direcao;
    int direcao_anterior;
    int fraco;
    BITMAP *sprite_atual;
    BITMAP *sprites[4];

    friend bool operator==(const struct ghost& l, const struct ghost& r){
        return (l.x == r.x) && (l.y == r.y);
    }
} Fantasma;

typedef struct comida{
    int x;
    int y;
    int desenhar;
}Comida;

vector<Fantasma> cromossomos;

volatile int exit_programa = FALSE; //Tambem pode ser while(!exit_program) ali no while, ao inv�s de !key[KEY_ESC]
void fecha_programa() {exit_programa=TRUE;}
int trilho(int x,int y){
    //y = -y;
    //ANDAR NAS CORDENADAS X

    if(x==MAX_X){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || y==245 || (y<=141 && y>=MIN_XY))
            return 1;
    }

    else if(x==512){
        if((y<=460 && y>=410))
            return 1;
    }

    else if(x==450){
        if((y<=460 && y>=MIN_XY))
            return 1;
    }

    else if(x==385){
        if((y<=460 && y>=410) || (y<=353 && y>=194) || (y<=141 && y>=90))
            return 1;
    }

    else if(x==318){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || (y<=194 && y>=141) || (y<=90 && y>=MIN_XY))
            return 1;
    }

    else if(x==257){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || (y<=194 && y>=141) || (y<=90 && y>=MIN_XY))
            return 1;
    }

    else if(x==187){
        if((y<=460 && y>=410) || (y<=353 && y>=194) || (y<=141 && y>=90))
            return 1;
    }

    else if(x==123){
        if((y<=460 && y>=MIN_XY))
            return 1;
    }

    else if(x==61){
        if((y<=460 && y>=410))
            return 1;
    }

    else if(x==MIN_XY){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || y==245 || (y<=141 && y>=MIN_XY))
            return 1;
    }

    //ANDAR NAS CORDENADAS Y

    if(y==MAX_Y){
        if(x<=MAX_X && x>=MIN_XY)
            return 1;
    }
    else if(y==460){
        if((x<=MAX_X && x>=450) || (x<=385 && x>=318) || (x<=257 && x>=187) || (x<=123 && x>=MIN_XY))
            return 1;
    }
    else if(y==410){
        if((x<=MAX_X && x>=512) || (x<=450 && x>=123) || (x<=61 && x>=MIN_XY))
            return 1;
    }
    else if(y==353){
        if((x<=MAX_X && x>=318) || (x<=257 && x>=MIN_XY) || (x<=61 && x>=MIN_XY))
            return 1;
    }

    else if(y==300){
        if((x<=385 && x>=187))
            return 1;
    }

    else if(y==248){
        if((x<=MAX_X && x>=385) ||(x<=187 && x>=MIN_XY) )
            return 1;
    }

    else if(y==194){
        if((x<=385 && x>=187))
            return 1;
    }

    else if(y==141){
        if((x<=MAX_X && x>=450) || (x<=385 && x>=318) || (x<=257 && x>=187)|| (x<=123 && x>=MIN_XY))
            return 1;
    }

    else if(y==90){
        if((x<=MAX_X && x>=MIN_XY))
            return 1;
    }

    else if(y==MIN_XY){
        if((x<=MAX_X && x>=318) || (x<=257 && x>=MIN_XY))
            return 1;
    }

    return 0;
}
void setarPixelComidas (Comida * comidas){
    comidas[0].x = 15;
    comidas[0].y = 520;
    comidas[0].desenhar=1;
    comidas[1].x = 45;
    comidas[1].y = 520;
    comidas[1].desenhar=1;
    comidas[2].x = 75;
    comidas[2].y = 520;
    comidas[2].desenhar=1;
    comidas[3].x = 105;
    comidas[3].y = 520;
    comidas[3].desenhar=1;
    comidas[4].x = 135;
    comidas[4].y = 520;
    comidas[4].desenhar=1;
    comidas[5].x = 165;
    comidas[5].y = 520;
    comidas[5].desenhar=1;
    comidas[6].x = 195;
    comidas[6].y = 520;
    comidas[6].desenhar=1;
    comidas[7].x = 225;
    comidas[7].y = 520;
    comidas[7].desenhar=1;
    comidas[8].x = 255;
    comidas[8].y = 520;
    comidas[8].desenhar=1;
    comidas[9].x = 285;
    comidas[9].y = 520;
    comidas[9].desenhar=1;
    comidas[10].x = 315;
    comidas[10].y = 520;
    comidas[10].desenhar=1;
    comidas[11].x = 345;
    comidas[11].y = 520;
    comidas[11].desenhar=1;
    comidas[12].x = 375;
    comidas[12].y = 520;
    comidas[12].desenhar=1;
    comidas[13].x = 405;
    comidas[13].y = 520;
    comidas[13].desenhar=1;
    comidas[14].x = 435;
    comidas[14].y = 520;
    comidas[14].desenhar=1;
    comidas[15].x = 465;
    comidas[15].y = 520;
    comidas[15].desenhar=1;
    comidas[16].x = 495;
    comidas[16].y = 520;
    comidas[16].desenhar=1;
    comidas[17].x = 525;
    comidas[17].y = 520;
    comidas[17].desenhar=1;
    comidas[18].x = 555;
    comidas[18].y = 520;
    comidas[18].desenhar=1;
    comidas[19].x = 0;
    comidas[19].y = 0;
    comidas[19].desenhar=0;
    comidas[20].x = 450;
    comidas[20].y = 45;
    comidas[20].desenhar=1;
    comidas[21].x = 450;
    comidas[21].y = 75;
    comidas[21].desenhar=1;
    comidas[22].x = 450;
    comidas[22].y = 105;
    comidas[22].desenhar=1;
    comidas[23].x = 450;
    comidas[23].y = 135;
    comidas[23].desenhar=1;
    comidas[24].x = 450;
    comidas[24].y = 165;
    comidas[24].desenhar=1;
    comidas[25].x = 450;
    comidas[25].y = 195;
    comidas[25].desenhar=1;
    comidas[26].x = 450;
    comidas[26].y = 225;
    comidas[26].desenhar=1;
    comidas[27].x = 450;
    comidas[27].y = 255;
    comidas[27].desenhar=1;
    comidas[28].x = 450;
    comidas[28].y = 285;
    comidas[28].desenhar=1;
    comidas[29].x = 450;
    comidas[29].y = 315;
    comidas[29].desenhar=1;
    comidas[30].x = 450;
    comidas[30].y = 345;
    comidas[30].desenhar=1;
    comidas[31].x = 450;
    comidas[31].y = 375;
    comidas[31].desenhar=1;
    comidas[32].x = 450;
    comidas[32].y = 405;
    comidas[32].desenhar=1;
    comidas[33].x = 450;
    comidas[33].y = 435;
    comidas[33].desenhar=1;
    comidas[34].x = 450;
    comidas[34].y = 470;
    comidas[34].desenhar=1;
    comidas[35].x = 0;
    comidas[35].y = 0;
    comidas[35].desenhar=0;
    comidas[36].x = 123;
    comidas[36].y = 45;
    comidas[36].desenhar=1;
    comidas[37].x = 123;
    comidas[37].y = 75;
    comidas[37].desenhar=1;
    comidas[38].x = 123;
    comidas[38].y = 105;
    comidas[38].desenhar=1;
    comidas[39].x = 123;
    comidas[39].y = 135;
    comidas[39].desenhar=1;
    comidas[40].x = 123;
    comidas[40].y = 165;
    comidas[40].desenhar=1;
    comidas[41].x = 123;
    comidas[41].y = 195;
    comidas[41].desenhar=1;
    comidas[42].x = 123;
    comidas[42].y = 225;
    comidas[42].desenhar=1;
    comidas[43].x = 123;
    comidas[43].y = 255;
    comidas[43].desenhar=1;
    comidas[44].x = 123;
    comidas[44].y = 285;
    comidas[44].desenhar=1;
    comidas[45].x = 123;
    comidas[45].y = 315;
    comidas[45].desenhar=1;
    comidas[46].x = 123;
    comidas[46].y = 345;
    comidas[46].desenhar=1;
    comidas[47].x = 123;
    comidas[47].y = 375;
    comidas[47].desenhar=1;
    comidas[48].x = 123;
    comidas[48].y = 405;
    comidas[48].desenhar=1;
    comidas[49].x = 123;
    comidas[49].y = 437;
    comidas[49].desenhar=1;
    comidas[50].x = 123;
    comidas[50].y = 470;
    comidas[50].desenhar=1;
    comidas[51].x = 15;
    comidas[51].y = 92;
    comidas[51].desenhar=1;
    comidas[52].x = 52;
    comidas[52].y = 92;
    comidas[52].desenhar=1;
    comidas[53].x = 90;
    comidas[53].y = 92;
    comidas[53].desenhar=1;
    comidas[54].x = 0;
    comidas[54].y = 0;
    comidas[54].desenhar=0;
    comidas[55].x = 0;
    comidas[55].y = 0;
    comidas[55].desenhar=0;
    comidas[56].x = 158;
    comidas[56].y = 92;
    comidas[56].desenhar=1;
    comidas[57].x = 190;
    comidas[57].y = 92;
    comidas[57].desenhar=1;
    comidas[58].x = 222;
    comidas[58].y = 92;
    comidas[58].desenhar=1;
    comidas[59].x = 255;
    comidas[59].y = 92;
    comidas[59].desenhar=1;
    comidas[60].x = 285;
    comidas[60].y = 92;
    comidas[60].desenhar=1;
    comidas[61].x = 315;
    comidas[61].y = 92;
    comidas[61].desenhar=1;
    comidas[62].x = 345;
    comidas[62].y = 92;
    comidas[62].desenhar=1;
    comidas[63].x = 375;
    comidas[63].y = 92;
    comidas[63].desenhar=1;
    comidas[64].x = 403;
    comidas[64].y = 92;
    comidas[64].desenhar=1;
    comidas[65].x = 428;
    comidas[65].y = 92;
    comidas[65].desenhar=1;
    comidas[66].x = 0;
    comidas[66].y = 0;
    comidas[66].desenhar=0;
    comidas[67].x = 480;
    comidas[67].y = 92;
    comidas[67].desenhar=1;
    comidas[68].x = 518;
    comidas[68].y = 92;
    comidas[68].desenhar=1;
    comidas[69].x = 555;
    comidas[69].y = 92;
    comidas[69].desenhar=1;
    comidas[70].x = 153;
    comidas[70].y = 415;
    comidas[70].desenhar=1;
    comidas[71].x = 183;
    comidas[71].y = 415;
    comidas[71].desenhar=1;
    comidas[72].x = 213;
    comidas[72].y = 415;
    comidas[72].desenhar=1;
    comidas[73].x = 243;
    comidas[73].y = 415;
    comidas[73].desenhar=1;
    comidas[74].x = 273;
    comidas[74].y = 415;
    comidas[74].desenhar=1;
    comidas[75].x = 303;
    comidas[75].y = 415;
    comidas[75].desenhar=1;
    comidas[76].x = 333;
    comidas[76].y = 415;
    comidas[76].desenhar=1;
    comidas[77].x = 363;
    comidas[77].y = 415;
    comidas[77].desenhar=1;
    comidas[78].x = 393;
    comidas[78].y = 415;
    comidas[78].desenhar=1;
    comidas[79].x = 423;
    comidas[79].y = 415;
    comidas[79].desenhar=1;
    comidas[80].x = 15;
    comidas[80].y = 360;
    comidas[80].desenhar=1;
    comidas[81].x = 52;
    comidas[81].y = 360;
    comidas[81].desenhar=1;
    comidas[82].x = 90;
    comidas[82].y = 360;
    comidas[82].desenhar=1;
    comidas[83].x = 0;
    comidas[83].y = 0;
    comidas[83].desenhar=0;
    comidas[84].x = 0;
    comidas[84].y = 0;
    comidas[84].desenhar=0;
    comidas[85].x = 157;
    comidas[85].y = 360;
    comidas[85].desenhar=1;
    comidas[86].x = 187;
    comidas[86].y = 360;
    comidas[86].desenhar=1;
    comidas[87].x = 220;
    comidas[87].y = 360;
    comidas[87].desenhar=1;
    comidas[88].x = 257;
    comidas[88].y = 360;
    comidas[88].desenhar=1;
    comidas[89].x = 325;
    comidas[89].y = 360;
    comidas[89].desenhar=1;
    comidas[90].x = 355;
    comidas[90].y = 360;
    comidas[90].desenhar=1;
    comidas[91].x = 388;
    comidas[91].y = 360;
    comidas[91].desenhar=1;
    comidas[92].x = 418;
    comidas[92].y = 360;
    comidas[92].desenhar=1;
    comidas[93].x = 0;
    comidas[93].y = 0;
    comidas[93].desenhar=0;
    comidas[94].x = 0;
    comidas[94].y = 0;
    comidas[94].desenhar=0;
    comidas[95].x = 480;
    comidas[95].y = 360;
    comidas[95].desenhar=1;
    comidas[96].x = 518;
    comidas[96].y = 360;
    comidas[96].desenhar=1;
    comidas[97].x = 555;
    comidas[97].y = 360;
    comidas[97].desenhar=1;
    comidas[98].x = 318;
    comidas[98].y = 20;
    comidas[98].desenhar=1;
    comidas[99].x = 348;
    comidas[99].y = 20;
    comidas[99].desenhar=1;
    comidas[100].x = 378;
    comidas[100].y = 20;
    comidas[100].desenhar=1;
    comidas[101].x = 408;
    comidas[101].y = 20;
    comidas[101].desenhar=1;
    comidas[102].x = 438;
    comidas[102].y = 20;
    comidas[102].desenhar=1;
    comidas[103].x = 468;
    comidas[103].y = 20;
    comidas[103].desenhar=1;
    comidas[104].x = 498;
    comidas[104].y = 20;
    comidas[104].desenhar=1;
    comidas[105].x = 528;
    comidas[105].y = 20;
    comidas[105].desenhar=1;
    comidas[106].x = 555;
    comidas[106].y = 20;
    comidas[106].desenhar=1;
    comidas[107].x = 187;
    comidas[107].y = 204;
    comidas[107].desenhar=1;
    comidas[108].x = 217;
    comidas[108].y = 204;
    comidas[108].desenhar=1;
    comidas[109].x = 247;
    comidas[109].y = 204;
    comidas[109].desenhar=1;
    comidas[110].x = 277;
    comidas[110].y = 204;
    comidas[110].desenhar=1;
    comidas[111].x = 307;
    comidas[111].y = 204;
    comidas[111].desenhar=1;
    comidas[112].x = 337;
    comidas[112].y = 204;
    comidas[112].desenhar=1;
    comidas[113].x = 364;
    comidas[113].y = 204;
    comidas[113].desenhar=1;
    comidas[114].x = 390;
    comidas[114].y = 204;
    comidas[114].desenhar=1;
    comidas[115].x = 187;
    comidas[115].y = 310;
    comidas[115].desenhar=1;
    comidas[116].x = 187;
    comidas[116].y = 310;
    comidas[116].desenhar=1;
    comidas[117].x = 217;
    comidas[117].y = 310;
    comidas[117].desenhar=1;
    comidas[118].x = 247;
    comidas[118].y = 310;
    comidas[118].desenhar=1;
    comidas[119].x = 277;
    comidas[119].y = 310;
    comidas[119].desenhar=1;
    comidas[120].x = 307;
    comidas[120].y = 310;
    comidas[120].desenhar=1;
    comidas[121].x = 337;
    comidas[121].y = 310;
    comidas[121].desenhar=1;
    comidas[122].x = 365;
    comidas[122].y = 310;
    comidas[122].desenhar=1;
    comidas[123].x = 390;
    comidas[123].y = 310;
    comidas[123].desenhar=1;
    comidas[124].x = 15;
    comidas[124].y = 20;
    comidas[124].desenhar=1;
    comidas[125].x = 45;
    comidas[125].y = 20;
    comidas[125].desenhar=1;
    comidas[126].x = 75;
    comidas[126].y = 20;
    comidas[126].desenhar=1;
    comidas[127].x = 105;
    comidas[127].y = 20;
    comidas[127].desenhar=1;
    comidas[128].x = 135;
    comidas[128].y = 20;
    comidas[128].desenhar=1;
    comidas[129].x = 165;
    comidas[129].y = 20;
    comidas[129].desenhar=1;
    comidas[130].x = 195;
    comidas[130].y = 20;
    comidas[130].desenhar=1;
    comidas[131].x = 225;
    comidas[131].y = 20;
    comidas[131].desenhar=1;
    comidas[132].x = 255;
    comidas[132].y = 20;
    comidas[132].desenhar=1;
    comidas[133].x = 555;
    comidas[133].y = 151;
    comidas[133].desenhar=1;
    comidas[134].x = 518;
    comidas[134].y = 151;
    comidas[134].desenhar=1;
    comidas[135].x = 480;
    comidas[135].y = 151;
    comidas[135].desenhar=1;
    comidas[136].x = 555;
    comidas[136].y = 122;
    comidas[136].desenhar=1;
    comidas[137].x = 555;
    comidas[137].y = 55;
    comidas[137].desenhar=1;
    comidas[138].x = 318;
    comidas[138].y = 55;
    comidas[138].desenhar=1;
    comidas[139].x = 255;
    comidas[139].y = 55;
    comidas[139].desenhar=1;
    comidas[140].x = 15;
    comidas[140].y = 55;
    comidas[140].desenhar=1;
    comidas[141].x = 15;
    comidas[141].y = 151;
    comidas[141].desenhar=1;
    comidas[142].x = 52;
    comidas[142].y = 151;
    comidas[142].desenhar=1;
    comidas[143].x = 90;
    comidas[143].y = 151;
    comidas[143].desenhar=1;
    comidas[144].x = 15;
    comidas[144].y = 122;
    comidas[144].desenhar=1;
    comidas[145].x = 480;
    comidas[145].y = 470;
    comidas[145].desenhar=1;
    comidas[146].x = 518;
    comidas[146].y = 470;
    comidas[146].desenhar=1;
    comidas[147].x = 555;
    comidas[147].y = 470;
    comidas[147].desenhar=1;
    comidas[148].x = 555;
    comidas[148].y = 495;
    comidas[148].desenhar=1;
    comidas[149].x = 555;
    comidas[149].y = 258;
    comidas[149].desenhar=1;
    comidas[150].x = 518;
    comidas[150].y = 258;
    comidas[150].desenhar=1;
    comidas[151].x = 480;
    comidas[151].y = 258;
    comidas[151].desenhar=1;
    comidas[152].x = 420;
    comidas[152].y = 258;
    comidas[152].desenhar=1;
    comidas[153].x = 390;
    comidas[153].y = 258;
    comidas[153].desenhar=1;
    comidas[154].x = 15;
    comidas[154].y = 258;
    comidas[154].desenhar=1;
    comidas[155].x = 52;
    comidas[155].y = 258;
    comidas[155].desenhar=1;
    comidas[156].x = 90;
    comidas[156].y = 258;
    comidas[156].desenhar=1;
    comidas[157].x = 155;
    comidas[157].y = 258;
    comidas[157].desenhar=1;
    comidas[158].x = 187;
    comidas[158].y = 258;
    comidas[158].desenhar=1;
    comidas[159].x = 257;
    comidas[159].y = 385;
    comidas[159].desenhar=1;
    comidas[160].x = 555;
    comidas[160].y = 388;
    comidas[160].desenhar=1;
    comidas[161].x = 555;
    comidas[161].y = 415;
    comidas[161].desenhar=1;
    comidas[162].x = 518;
    comidas[162].y = 415;
    comidas[162].desenhar=1;
    comidas[163].x = 518;
    comidas[163].y = 443;
    comidas[163].desenhar=1;
    comidas[164].x = 325;
    comidas[164].y = 388;
    comidas[164].desenhar=1;
    comidas[165].x = 393;
    comidas[165].y = 443;
    comidas[165].desenhar=1;
    comidas[166].x = 187;
    comidas[166].y = 443;
    comidas[166].desenhar=1;
    comidas[167].x = 61;
    comidas[167].y = 443;
    comidas[167].desenhar=1;
    comidas[168].x = 15;
    comidas[168].y = 415;
    comidas[168].desenhar=1;
    comidas[169].x = 52;
    comidas[169].y = 415;
    comidas[169].desenhar=1;
    comidas[170].x = 15;
    comidas[170].y = 388;
    comidas[170].desenhar=1;
    comidas[171].x = 15;
    comidas[171].y = 470;
    comidas[171].desenhar=1;
    comidas[172].x = 52;
    comidas[172].y = 470;
    comidas[172].desenhar=1;
    comidas[173].x = 90;
    comidas[173].y = 470;
    comidas[173].desenhar=1;
    comidas[174].x = 15;
    comidas[174].y = 495;
    comidas[174].desenhar=1;
    comidas[175].x = 261;
    comidas[175].y = 495;
    comidas[175].desenhar=1;
    comidas[176].x = 187;
    comidas[176].y = 470;
    comidas[176].desenhar=1;
    comidas[177].x = 224;
    comidas[177].y = 470;
    comidas[177].desenhar=1;
    comidas[178].x = 261;
    comidas[178].y = 470;
    comidas[178].desenhar=1;
    comidas[179].x = 261;
    comidas[179].y = 470;
    comidas[179].desenhar=1;
    comidas[180].x = 318;
    comidas[180].y = 470;
    comidas[180].desenhar=1;
    comidas[181].x = 355;
    comidas[181].y = 470;
    comidas[181].desenhar=1;
    comidas[182].x = 393;
    comidas[182].y = 470;
    comidas[182].desenhar=1;
    comidas[183].x = 318;
    comidas[183].y = 495;
    comidas[183].desenhar=1;
    comidas[185].x = 187;
    comidas[185].y = 151;
    comidas[185].desenhar=1;
    comidas[186].x = 224;
    comidas[186].y = 151;
    comidas[186].desenhar=1;
    comidas[187].x = 261;
    comidas[187].y = 151;
    comidas[187].desenhar=1;
    comidas[188].x = 187;
    comidas[188].y = 122;
    comidas[188].desenhar=1;
    comidas[189].x = 261;
    comidas[189].y = 175;
    comidas[189].desenhar=1;
    comidas[190].x = 318;
    comidas[190].y = 175;
    comidas[190].desenhar=1;
    comidas[184].x = 318;
    comidas[184].y = 151;
    comidas[184].desenhar=1;
    comidas[191].x = 355;
    comidas[191].y = 151;
    comidas[191].desenhar=1;
    comidas[192].x = 393;
    comidas[192].y = 151;
    comidas[192].desenhar=1;
    comidas[193].x = 393;
    comidas[193].y = 122;
    comidas[193].desenhar=1;
}
int trilho1(int x, int y){
    printf ("X:%d Y:%d\n",x,y);
    if(y<0 || y>530 || x<0 || x>574)
        return 0;
    return 1;

}
void retirarTrilho(Comida * comida, int x, int y, int * score,int * score_atual){
    if((comida->x >= x-5 && comida->x <= x+15) && (comida->y >= y-5 && comida->y <= y+15) && comida->desenhar==1){
        comida->desenhar=0;
        *score+=10;
        *score_atual+=10;
    }
}
void verificarMorreu(Fantasma * fantasma,int x,int y, int *perdeu){
    if((fantasma->x >= x-15 && fantasma->x <= x+15) && (fantasma->y >= y-15 && fantasma->y <= y+15))
        *perdeu=1;
}
Fantasma moveFantasma(Fantasma fantasma){
    int v = 0;
    if(fantasma.direcao==DIREITA){
        if(trilho(fantasma.x+1,fantasma.y))
            fantasma.x++;
        else
            v++;
    }
    else if(fantasma.direcao==ESQUERDA ){
        if(trilho(fantasma.x-1,fantasma.y))
            fantasma.x--;
        else
            v++;
    }
    else if(fantasma.direcao==CIMA){
        if(trilho(fantasma.x,fantasma.y-1))
            fantasma.y--;

    }
    else if (fantasma.direcao==BAIXO){
        if(trilho(fantasma.x,fantasma.y+1))
            fantasma.y++;
    }
    if(v==1){
        if(fantasma.direcao==DIREITA){
            fantasma.direcao=ESQUERDA;
            fantasma.sprite_atual = fantasma.sprites[ESQUERDA];
        }
        else{
            fantasma.direcao=DIREITA;
            fantasma.sprite_atual = fantasma.sprites[DIREITA];
        }
    }
    return fantasma;

}
int trilho(Fantasma fantasma){
    return trilho(fantasma.x, fantasma.y);
}
//fun��o de aptid�o
double fitness(Fantasma fantasma){
    double x1 = fantasma.x;
    double y1 = fantasma.y;

    double x2 = fantasma.xp;
    double y2 = fantasma.yp;

    // Dist�ncia euclideana do fantasma ao pacman
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

bool comp_fitness(Fantasma fantasma1, Fantasma fantasma2){
    return fitness(fantasma1) < fitness(fantasma2);
}

//gera��o da nova popula��o
Fantasma new_pop(Fantasma fantasma){
    srand(rand()+fantasma.xp * fantasma.direcao - fantasma.x + fantasma.y/max((int)cromossomos.size(), 1));
    //cout << fitness(fantasma) << endl;
    //ordena os cromossomos pela aptid�o
    sort(cromossomos.begin(), cromossomos.end(), comp_fitness);

    //90% de chance de escolher o melhor caso, se a dist�ncia do fantasma ao pacman for menor que 260
    //caso esteja a uma distancia de 260 ou mais do pacman, escolhe o melhor caso sempre
    if(rand()%10 or fitness(fantasma) >= 260){
        fantasma.direcao = cromossomos.front().direcao;
        fantasma.sprite_atual = cromossomos.front().sprite_atual;
        //cout << cromossomos.front().x << " " << cromossomos.front().y << endl;
        return fantasma;
    }
    else{
        //cout << "q merda: " << fitness(fantasma) << endl;
        return cromossomos.back();
    }
}

bool backwards(int direcao1, int direcao2){
    if(direcao1 == CIMA) return direcao2 == BAIXO;
    if(direcao1 == BAIXO) return direcao2 == CIMA;
    if(direcao1 == ESQUERDA) return direcao2 == DIREITA;
    if(direcao1 == DIREITA) return direcao2 == ESQUERDA;
    else return false;
}
//muta��o
void generate_mutation(Fantasma fantasma){
    Fantasma aux[4] = {fantasma,fantasma,fantasma,fantasma};
    aux[0].x++;
    aux[0].direcao_anterior = fantasma.direcao;
    aux[0].direcao = DIREITA;
    aux[0].sprite_atual = fantasma.sprites[DIREITA];

    aux[1].x--;
    aux[1].direcao_anterior = fantasma.direcao;
    aux[1].direcao = ESQUERDA;
    aux[1].sprite_atual = fantasma.sprites[ESQUERDA];

    aux[2].y++;
    aux[2].direcao_anterior = fantasma.direcao;
    aux[2].direcao = BAIXO;
    aux[2].sprite_atual = fantasma.sprites[BAIXO];

    aux[3].y--;
    aux[3].direcao_anterior = fantasma.direcao;
    aux[3].direcao = CIMA;
    aux[3].sprite_atual = fantasma.sprites[CIMA];

    for(int i = 0; i < 4; ++i){
        if(trilho(aux[i]) && !backwards(aux[i].direcao, aux[i].direcao_anterior)){
            cromossomos.push_back(aux[i]);
        }
    }
    //cout << cromossomos.size() << endl;
}

Fantasma select(Fantasma fantasma){
    Fantasma default_move = moveFantasma(fantasma);
    if(cromossomos.size() > 1 || default_move == fantasma)
        return moveFantasma(new_pop(fantasma));
    else return default_move;
}

//roda o algoritmo gen�tico, caso aplic�vel
Fantasma genetic_algorithm(Fantasma fantasma){
    cromossomos.clear();
    generate_mutation(fantasma);
    return select(fantasma);
}

void setarFantasmas(Fantasma * fantasmas, int quantidade){
    int i;
    for (i=0;i<quantidade;i++){
        if(i%4==0){
            fantasmas[i].sprites[DIREITA] = load_bitmap("sprites/Fantasmas/vermelho_direita.bmp",NULL);
            fantasmas[i].sprites[ESQUERDA] = load_bitmap("sprites/Fantasmas/vermelho_esquerda.bmp",NULL);
            fantasmas[i].sprites[CIMA] = load_bitmap("sprites/Fantasmas/vermelho_cima.bmp",NULL);
            fantasmas[i].sprites[BAIXO] = load_bitmap("sprites/Fantasmas/vermelho_baixo.bmp",NULL);
            fantasmas[i].sprite_atual = fantasmas[i].sprites[DIREITA];
            fantasmas[i].x = MIN_XY;
            fantasmas[i].y = MIN_XY;
            fantasmas[i].direcao = DIREITA;
        }else if(i%4==1){
            fantasmas[i].sprites[DIREITA] = load_bitmap("sprites/Fantasmas/laranja_direita.bmp",NULL);
            fantasmas[i].sprites[ESQUERDA] = load_bitmap("sprites/Fantasmas/laranja_esquerda.bmp",NULL);
            fantasmas[i].sprites[CIMA] = load_bitmap("sprites/Fantasmas/laranja_cima.bmp",NULL);
            fantasmas[i].sprites[BAIXO] = load_bitmap("sprites/Fantasmas/laranja_baixo.bmp",NULL);
            fantasmas[i].sprite_atual = fantasmas[i].sprites[CIMA];
            fantasmas[i].x = MAX_X;
            fantasmas[i].y = MIN_XY;
            fantasmas[i].direcao = CIMA;
        }else if(i%4==2){
            fantasmas[i].sprites[DIREITA] = load_bitmap("sprites/Fantasmas/azul_direita.bmp",NULL);
            fantasmas[i].sprites[ESQUERDA] = load_bitmap("sprites/Fantasmas/azul_esquerda.bmp",NULL);
            fantasmas[i].sprites[CIMA] = load_bitmap("sprites/Fantasmas/azul_cima.bmp",NULL);
            fantasmas[i].sprites[BAIXO] = load_bitmap("sprites/Fantasmas/azul_baixo.bmp",NULL);
            fantasmas[i].sprite_atual = fantasmas[i].sprites[BAIXO];
            fantasmas[i].x = MIN_XY;
            fantasmas[i].y = MAX_Y;
            fantasmas[i].direcao = BAIXO;
        }else if(i%4==3){
            fantasmas[i].sprites[DIREITA] = load_bitmap("sprites/Fantasmas/rosa_direita.bmp",NULL);
            fantasmas[i].sprites[ESQUERDA] = load_bitmap("sprites/Fantasmas/rosa_esquerda.bmp",NULL);
            fantasmas[i].sprites[CIMA] = load_bitmap("sprites/Fantasmas/rosa_cima.bmp",NULL);
            fantasmas[i].sprites[BAIXO] = load_bitmap("sprites/Fantasmas/rosa_baixo.bmp",NULL);
            fantasmas[i].sprite_atual = fantasmas[i].sprites[DIREITA];
            fantasmas[i].x = MAX_X/2;
            fantasmas[i].y = 194;
            fantasmas[i].direcao = DIREITA;
        }
        fantasmas[i].xp = 555;
        fantasmas[i].yp = 515;
    }
}
void setarDificuldade(int dificuldade,int * velocidade,int * velocidade_fantasma,int * att_quadrante,int * numero_fantasmas){
    if(dificuldade==1){
        *velocidade = 5;
        *velocidade_fantasma = 10;
        *att_quadrante = 1000;
        *numero_fantasmas = 1;
    }else if(dificuldade==2){
        *velocidade = 5;
        *velocidade_fantasma = 10;
        *att_quadrante = 1000;
        *numero_fantasmas = 2;
    }else if(dificuldade==3){
        *velocidade = 5;
        *velocidade_fantasma = 10;
        *att_quadrante = 1000;
        *numero_fantasmas = 3;
    }else if(dificuldade==4){
        *velocidade = 5;
        *velocidade_fantasma = 9;
        *att_quadrante = 500;
        *numero_fantasmas = 4;
    }else if(dificuldade==5){
        *velocidade = 3;
        *velocidade_fantasma = 5;
        *att_quadrante = 500;
        *numero_fantasmas = 4;
    }else if(dificuldade>=6){
        *velocidade = 5;
        *velocidade_fantasma = 10;
        *att_quadrante = 250;
        *numero_fantasmas = 16;
    }
}

END_OF_FUNCTION(fecha_programa);

int main ()
{
    allegro_init(); //Vai inicializar umas coisas basicas da biblioteca
    install_timer(); //Instalar os timers padr�o, funcionar o mouse e tocar audio etc
    install_keyboard(); //Para instalar o teclado,tambem pode instalar mouse etc
    set_color_depth(32); //Parametros s�o a quantidade de cores, 32 bits,16 bits etc
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,555,0,0); //Autodetect detecta o driver de v�deo, � o recomendado, windowed e fullsc
    set_window_title("PACMAN"); //Titulo da janela do programa

    exit_programa=FALSE;
    LOCK_FUNCTION(exit_program);
    LOCK_VARIABLE(fecha_programa);
    set_close_button_callback(fecha_programa);
    srand( (unsigned)time(NULL) );

    BITMAP *direita[2];
    BITMAP *esquerda[2];
    BITMAP *cima[2];
    BITMAP *baixo[2];
    direita[0] = load_bitmap("sprites/pacman1.bmp",NULL);
    direita[1] = load_bitmap("sprites/pacman11.bmp",NULL);
    esquerda[0] = load_bitmap("sprites/pacman3.bmp",NULL);
    esquerda[1] = load_bitmap("sprites/pacman33.bmp",NULL);
    cima[0] = load_bitmap("sprites/pacman4.bmp",NULL);
    cima[1] = load_bitmap("sprites/pacman44.bmp",NULL);
    baixo[0] = load_bitmap("sprites/pacman2.bmp",NULL);
    baixo[1] = load_bitmap("sprites/pacman22.bmp",NULL);

    Fantasma fantasmas[16];

    //int quadrante=4;  //1 2
                        //3 4

    int quantidade_fantasmas=4;
    int VELOCIDADE=10;
    int VELOCIDADE_FANTASMA=10;
    int ATT_QUADRANTE=1000;
    int dificuldade=0;

    FONT * font1 = load_font("font1.pcx",NULL,NULL);

    BITMAP *buffer = create_bitmap(801,801);
    BITMAP *sprite_atual = cima[0]; //Ponteiro pro Boneco
    BITMAP *comida = load_bitmap("sprites/comida.bmp",NULL);//Ponteiro pra comida
    BITMAP *mapa = load_bitmap("sprites/mapa.bmp",NULL); //Ponteiro pro mapa
    BITMAP *menu1 = load_bitmap("sprites/menu.bmp",NULL);
    int score=0;
    int score_passado=0;
    int i = 0;
    int tempo;
    int tempo_andar = 0;
    int tempo_fantasma = 0;
    int tempo_sprite = 0;
    int pos_x=555,pos_y=515;
    int direcao_atual=DIREITA; //
    //GAME LOOP

    //CRIAR VETOR DO TAMANHO DE COMIDAS
    int quantidade_comidas=197;
    Comida comidas[quantidade_comidas];


    int jogar=0;
    do{
        if(jogar==1){
            setarDificuldade(dificuldade,&VELOCIDADE,&VELOCIDADE_FANTASMA,&ATT_QUADRANTE,&quantidade_fantasmas);
            setarFantasmas(fantasmas,quantidade_fantasmas);
            setarPixelComidas(comidas);
            direcao_atual=DIREITA;
            int PERDEU=0;
            int score_atual=0;
            while (!exit_programa && !PERDEU) //Condi��o para fechar o programa, array Key[estado da tecla]
            {
                int j;

                //textout_centre_ex(screen,font,"OI ATAIDE, SOU O MELHOR STORM SPIRIT",SCREEN_W/2, SCREEN_H/2,makecol(255,255,255),-1);
                tempo=clock();

                //INPUT
                //Detecta as entradas
                    if(key[KEY_ESC]){
                      fecha_programa();
                    }

                    if(key[KEY_D]){
                        if(trilho(pos_x+1,pos_y))
                            direcao_atual=DIREITA;
                    }

                    if(key[KEY_S]){
                       if(trilho(pos_x,pos_y+1))
                            direcao_atual=BAIXO;
                    }
                    if(key[KEY_A]){
                       if(trilho(pos_x-1,pos_y))
                            direcao_atual=ESQUERDA;
                    }
                    if(key[KEY_W]){
                       if(trilho(pos_x,pos_y-1))
                            direcao_atual=CIMA;
                    }

                    //printf ("tempo:%d andar:%d\n",tempo, tempo_andar);
                    //movimento do pacman
                    if(tempo >= tempo_andar){
                        //printf ("X:%d Y:%d\n",pos_x,pos_y);
                        tempo_andar +=VELOCIDADE;
                        if(direcao_atual==DIREITA){
                            if(trilho(pos_x+1,pos_y))
                                pos_x++;
                        }
                        else if(direcao_atual==ESQUERDA){
                            if(trilho(pos_x-1,pos_y))
                                pos_x--;
                        }
                        else if(direcao_atual==CIMA){
                            if(trilho(pos_x,pos_y-1))
                                pos_y--;
                        }
                        else if (direcao_atual==BAIXO){
                            if(trilho(pos_x,pos_y+1))
                                pos_y++;
                        }
                    }

                    if(tempo >= tempo_fantasma){
                        //printf ("X:%d Y:%d\n",pos_x,pos_y);
                        tempo_fantasma +=VELOCIDADE_FANTASMA;
                        for (j=0;j<quantidade_fantasmas;j++){ // movimenta os fantasmas
                            //int v=0;
                            //atualiza posi��o do pacman nos fantasmas
                            fantasmas[j].xp = pos_x;
                            fantasmas[j].yp = pos_y;
                            //movimenta o fantasma
                            //cout << "ANTES" << fantasmas[j].x << " " << fantasmas[j].y << endl;
                            fantasmas[j] = genetic_algorithm(fantasmas[j]);
                            //cout << "DEPOIS" << fantasmas[j].x << " " << fantasmas[j].y << endl;

                        }

                    }

                    if(tempo >= tempo_sprite){
                        i++;
                        tempo_sprite+=VELOCIDADE_SPRITE;
                        if(i>1)
                            i=0;
                        if(direcao_atual==0){
                            sprite_atual = direita[i];
                        }
                        else if(direcao_atual==1){
                            sprite_atual = esquerda[i];
                        }
                        else if(direcao_atual==2){
                            sprite_atual = cima[i];
                        }
                        else if (direcao_atual==3){
                            sprite_atual = baixo[i];
                        }
                    }


                    //printf ("tempo:%d clock:%d\n",tempo,clock());


                //UPDATE
                //Atualiza o estado do jogo
                //pos_x++; //Variar a posi��o do circulo ao longo do tempo

                //DRAW
                //Parte de desenho - Ponteiro para BITMAP que � o "screen", tudo que vc desenhar, aparece na tela

                draw_sprite(buffer,mapa,0,0);

                for (j=0;j<quantidade_comidas;j++){
                    retirarTrilho(&comidas[j],pos_x,pos_y,&score,&score_atual);
                    if(comidas[j].desenhar && comidas[j].x!=0 && comidas[j].y!=0)
                        draw_sprite(buffer,comida,comidas[j].x+5,comidas[j].y);
                }

                for (j=0;j<quantidade_fantasmas;j++){
                    draw_sprite(buffer,fantasmas[j].sprite_atual,fantasmas[j].x,fantasmas[j].y);
                    verificarMorreu(&fantasmas[j],pos_x,pos_y,&PERDEU);
                    //if(fantasmas[j].x == pos_x && fantasmas[j].y == pos_y)
                    //   score=-9999;
                }
                draw_sprite(buffer,sprite_atual,pos_x,pos_y);
                char scor[20];
                sprintf(scor,"%d",score);
                textout_ex(buffer, font1, scor, 650, 50,makecol(255, 255, 255), -1);

                char nivel[20];
                sprintf(nivel,"Dificuldade: %d",dificuldade);
                textout_ex(buffer, font, nivel, (MAX_X/2)-40, MAX_Y/2,makecol(255, 255, 255), -1);

                if(score_atual==1850){
                    dificuldade++;
                    setarDificuldade(dificuldade,&VELOCIDADE,&VELOCIDADE_FANTASMA,&ATT_QUADRANTE,&quantidade_fantasmas);
                    setarFantasmas(fantasmas,quantidade_fantasmas);
                    setarPixelComidas(comidas);
                    pos_x = MAX_X;
                    pos_y = MAX_Y;
                    score_atual = 0;
                    direcao_atual=DIREITA;
                }

                if(PERDEU==1){
                    score_passado=score;
                    score=0;
                    jogar=0;
                    buffer = create_bitmap(801,801);
                    pos_x = MAX_X;
                    pos_y = MAX_Y;
                }
                draw_sprite(screen,buffer,0,0); //Sprite em que eu quero desenhar, buffer na screen
            }
        }else{
            //ESCOLHER DIFICULDADE
            if(key[KEY_ESC]){
                fecha_programa();
            }

            if(key[KEY_1]){
                dificuldade=1;
                jogar=1;
            }
            if(key[KEY_2]){
                dificuldade=2;
                jogar=1;
            }
            if(key[KEY_3]){
                dificuldade=3;
                jogar=1;
            }
            if(key[KEY_4]){
                dificuldade=4;
                jogar=1;
            }
            if(key[KEY_5]){
                dificuldade=5;
                jogar=1;
            }

            if(key[KEY_6]){
                dificuldade=6;
                jogar=1;
            }
            tempo_andar = clock();
            tempo_fantasma = clock();
            tempo_sprite = clock();

            draw_sprite(buffer,menu1,0,0);
            char scor[20];
            sprintf(scor,"%d",score_passado);
            textout_ex(buffer, font1, scor, 310, 250,makecol(255, 255, 255), -1);

            draw_sprite(screen,buffer,0,0); //Sprite em que eu quero desenhar, buffer na screen
        }

    }while(!exit_programa);



    //FINALIZA��O
    destroy_bitmap(buffer);
    destroy_bitmap(sprite_atual);
    destroy_bitmap(mapa);



    return 0;
}
END_OF_MAIN() //Tem que botar por quest�es de compatiblidade
