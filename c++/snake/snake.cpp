#include "snake.h"
#include <ncurses.h>

enum BLOCKS{
    NONE,
    EMPTY,
    WALL,
    IMMUNE_WALL,
    HEAD,
    BODY,
    GATE,
    GROWTH,
    POISON,
};

Snake::Snake(){
    v[0].x = 3; v[0].y = 5;
    v[1].x = 4; v[1].y = 5;
    v[2].x = 5; v[2].y = 5;

    dir = 'd';

    growth.x = -1; growth.y = -1;
    poison.x = -1; poison.y = -1;
    gate[0].x = -1; gate[0].y = -1;
    gate[1].x = -1; gate[1].y = -1;

    isPoison = false;
    isGrowth = false;
    isGate = false;
}

void Snake::colorInit(){
    start_color();
    init_pair(EMPTY,COLOR_BLACK,COLOR_BLACK);
    init_pair(WALL, COLOR_RED, COLOR_RED);
    init_pair(IMMUNE_WALL, COLOR_CYAN, COLOR_CYAN);
    init_pair(HEAD,COLOR_BLUE,COLOR_BLUE);
    init_pair(BODY,COLOR_GREEN,COLOR_GREEN);
    init_pair(GATE,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(GROWTH,COLOR_GREEN,COLOR_GREEN);
    init_pair(POISON,COLOR_MAGENTA,COLOR_MAGENTA);
}

void Snake::init(){
    /** remove cursor**/
    curs_set(0);
    starttime = time(NULL);
    /** screen init**/
    initscr();
    noecho();

    /** color init **/
    colorInit();
    /** window init**/
    //@박승현
    resize_term(35,75);
    border('*','*','*','*','*','*','*','*');

    // draw via MAP @SKrns -----
    map_win = newwin(NLINE,NCOL,2,4);
    generateMap();

    // wborder(map_win,'+','+','+','+','+','+','+','+');
    // ------------------

    score_win = newwin(12,25,1,45);
    wborder(score_win,'-','-','-','-','-','-','-','-');
    mvwprintw(score_win,1,7,"Score Board");
    mvwprintw(score_win,2,2,"B : ");
    mvwprintw(score_win,2,2,"A : ");
    mvwprintw(score_win,4,2,"+ : ");
    mvwprintw(score_win,6,2,"- : ");
    mvwprintw(score_win,8,2,"G : ");
    mvwprintw(score_win,10,2,"Timer : ");
    mvwprintw(score_win,2,6,"%d",len-1 );
    mvwprintw(score_win,2,8,"/");
    mvwprintw(score_win,2,10,"%d",score.Best );
    mvwprintw(score_win,4,6,"%d",score.growth );
    mvwprintw(score_win,6,6,"%d",score.poison );
    mvwprintw(score_win,8,6,"%d",score.G );
    Mission_win = newwin(10,25,13,45);
    wborder(Mission_win,'-','-','-','-','-','-','-','-');
    mvwprintw(Mission_win,1,7,"Mission (V)");
    mvwprintw(Mission_win,2,2,"B : 10 (");
    mvwprintw(Mission_win,2,11,")");
    mvwprintw(Mission_win,4,2,"+ : 5  (");
    mvwprintw(Mission_win,4,11,")");
    mvwprintw(Mission_win,6,2,"- : 2  (");
    mvwprintw(Mission_win,6,11,")");
    mvwprintw(Mission_win,8,2,"G : 1  (");
    mvwprintw(Mission_win,8,11,")");
    refresh();

    /** generate Items**/
    srand(time(NULL));
    generateGate();
    generateGrowth();
    generatePoison();

    wrefresh(map_win);
    wrefresh(Mission_win);
    wrefresh(score_win);
}
void Snake::timer(){
    int end = time(NULL);
    Time = end - starttime;
    if(end - growthTime >= 5)
        generateGrowth();
    mvwprintw(score_win,10,10,"%d",Time);
    wrefresh (score_win);
}
void Snake::drawSnake(){
        // score.B = len;
    attron(COLOR_PAIR(BODY));
    for(int i = 0; i < len; i++)
        mvwprintw(map_win,v[i].y,v[i].x,"#");
    attroff(COLOR_PAIR(BODY));
}

void Snake::moveSnake(char key){
    //이전 snake를 지우기.
    if((MiGrowItem == true) && (MiBest == true) && (MiPoisonItem == true) && (MiG == true)){
      exit(1);
    }
    wattron(map_win,COLOR_PAIR(EMPTY));
    for(int i = 0; i < len; i++)
        mvwprintw(map_win,v[i].y,v[i].x," ");
    wattroff(map_win,COLOR_PAIR(EMPTY));
    wrefresh(map_win);

    //cout << key;

    if(key != 'n')
        dir = key;

    if(dir == 'w'){
        if(v[0].x == growth.x && v[0].y - 1 == growth.y)
            eatGrowth();
        else if(v[0].x == poison.x && v[0].y -1 == poison.y)
            eatPoison();
        else if((v[0].x == gate[0].x && v[0].y -1 == gate[0].y) || (v[0].x == gate[1].x && v[0].y -1 == gate[1].y))
            gotoGate();
        else{
            for(int i = len; i >= 1; i--){
                v[i].x = v[i-1].x; v[i].y = v[i-1].y;
            }
            v[0].x = v[1].x; v[0].y = v[1].y - 1;
        }

    }
    else if(dir == 'a'){
        if(v[0].x -1 == growth.x && v[0].y == growth.y)
            eatGrowth();
        else if(v[0].x -1== poison.x && v[0].y == poison.y)
            eatPoison();
        else if((v[0].x -1 == gate[0].x && v[0].y == gate[0].y) || (v[0].x -1 == gate[1].x && v[0].y == gate[1].y))
            gotoGate();
        else{
            for(int i = len; i >= 1; i--){
                v[i].x = v[i-1].x; v[i].y = v[i-1].y;
            }
            v[0].x = v[1].x - 1; v[0].y = v[1].y;
        }

    }
    else if(dir == 's'){
        if(v[0].x == growth.x && v[0].y + 1 == growth.y)
            eatGrowth();
        else if(v[0].x == poison.x && v[0].y + 1 == poison.y)
            eatPoison();
        else if((v[0].x == gate[0].x && v[0].y + 1 == gate[0].y) || (v[0].x == gate[1].x && v[0].y + 1 == gate[1].y))
            gotoGate();
        else{
            for(int i = len; i >= 1; i--){
                v[i].x = v[i-1].x; v[i].y = v[i-1].y;
            }
            v[0].x = v[1].x; v[0].y = v[1].y + 1;
        }

    }
    else if(dir == 'd'){
        if(v[0].x + 1 == growth.x && v[0].y == growth.y)
            eatGrowth();
        else if(v[0].x + 1== poison.x && v[0].y == poison.y)
            eatPoison();
        else if((v[0].x + 1 == gate[0].x && v[0].y == gate[0].y) || (v[0].x + 1 == gate[1].x && v[0].y  == gate[1].y))
            gotoGate();
        else{
            for(int i = len; i >= 1; i--){
                v[i].x = v[i-1].x; v[i].y = v[i-1].y;
            }
            v[0].x = v[1].x + 1; v[0].y = v[1].y;
        }

    }

    wattron(map_win,COLOR_PAIR(BODY));
    for(int i = 1; i < len; i++)
        mvwprintw(map_win,v[i].y,v[i].x,"#");
    wattroff(map_win,COLOR_PAIR(BODY));

    wattron(map_win,COLOR_PAIR(HEAD));
    mvwprintw(map_win,v[0].y,v[0].x,"#");
    wattroff(map_win,COLOR_PAIR(HEAD));
    wrefresh(map_win);

    // 벽에 부딫혔을 때 종료처리
    if (MAP[v[0].y][v[0].x] == 1)
    {
        // 꼭 변경!!!!!!!!!
        exit(1);
    }
}

// Map 배열대로 그리기
void Snake::generateMap() {
    for (int y = 0; y < NLINE; ++y)
    {
        for (int x = 0; x < NCOL; ++x)
        {
            if (MAP[y][x] == 1) // WALL
            {
                wattron(map_win,COLOR_PAIR(WALL));
                mvwprintw(map_win,y,x,"+");
                wattroff(map_win,COLOR_PAIR(WALL));
            }
            if (MAP[y][x] == 2) // IMMUNE_WALL
            {
                wattron(map_win,COLOR_PAIR(IMMUNE_WALL));
                mvwprintw(map_win,y,x,"+");
                wattroff(map_win,COLOR_PAIR(IMMUNE_WALL));
            }
        }
    }
}

//35 x 21
void Snake::generateGate() {
    int x, y;
    bool conti = true;
    while(conti){
        conti = false;
        x = rand()%35;
        y = rand()%21;
        // snake와 겹치는지 확인
        for(int i = 0; i < len; i++){
            if(v[i].x == x && v[i].y == y){
                conti = true;
                break;
            }
        }
        //poison item과 겹치는지 확인
        if(x == poison.x && y == poison.y)
            conti = true;
        //growth item과 겹치는지 확인
        if(x == growth.x && y == growth.y)
            conti = true;
        //Wall 안에 없는지 확인
        if(1 != MAP[y][x])
            conti = true;
    }
    gate[0].x = x; gate[0].y = y;

    conti = true;
    while(conti){
        conti = false;
        x = rand()%35;
        y = rand()%21;
        // snake와 겹치는지 확인
        for(int i = 0; i < len; i++){
            if(v[i].x == x && v[i].y == y){
                conti = true;
                break;
            }
        }
        //poison item과 겹치는지 확인
        if(x == poison.x && y == poison.y)
            conti = true;

        //growth item과 겹치는지 확인
        if(x == growth.x && y == growth.y)
            conti = true;

        //Wall 안에 없는지 확인
        if(1 != MAP[y][x])
            conti = true;

        //gate1이 gate0 주변 범위 1 안에 있는지 확인 => 진입 방향 검출 때문
        if(gate[0].x <= x+1 && gate[0].x >= x-1 && gate[0].y <= y+1 && gate[0].y >= y-1)
            conti = true;
    }

    gate[1].x = x; gate[1].y = y;
    isGate = true;

    wattron(map_win,COLOR_PAIR(GATE));
    mvwprintw(map_win,gate[0].y,gate[0].x,"#");
    mvwprintw(map_win,gate[1].y,gate[1].x,"#");
    wattroff(map_win,COLOR_PAIR(GATE));
    wrefresh(map_win);

}

void Snake::generatePoison(){
    int x,y;
    bool conti = true;

    while(conti){
        conti = false;
        //gate의 경우 양 끝점에 나와도 되지만, item들과 같은 경우 경계선에 있으면 안된다.
        x = rand()%33 + 1;
        y = rand()%19 + 1;

        //snake과 겹치는 지 확인
        for(int i = 0; i < len; i++){
            if(v[i].x == x && v[i].y == y){
                conti = true;
                break;
            }
        }

        //growth 겹치는 지 확인
        if(growth.x == x && growth.y == y)
            conti = true;

        //gate과 겹치는 지 확인
        for(int i = 0; i < 2; i++){
            if(gate[i].x == x && gate[i].y == y){
                conti = true;
                break;
            }
        }
    }
    poison.x = x; poison.y = y;
    isPoison = true;

    wattron(map_win,COLOR_PAIR(POISON));
    mvwprintw(map_win,y,x,"#");
    wattroff(map_win,COLOR_PAIR(POISON));
    wrefresh(map_win);
}

void Snake::generateGrowth(){
    int x,y;
    bool conti = true;
    growthTime = time(NULL);
    mvwprintw(map_win,growth.y,growth.x," ");
    while(conti){
        conti = false;
        x = rand()%33 + 1;
        y = rand()%19 + 1;

        //snake과 겹치는 지 확인
        for(int i = 0; i < len; i++){
            if(v[i].x == x && v[i].y == y){
                conti = true;
                break;
            }
        }

        //poison과 겹치는 지 확인
        if(poison.x == x && poison.y == y)
            conti = true;

        //gate과 겹치는 지 확인
        for(int i = 0; i < 2; i++){
            if(gate[i].x == x && gate[i].y == y){
                conti = true;
                break;
            }
        }
    }
    growth.x = x; growth.y = y;
    isGrowth = true;

    wattron(map_win,COLOR_PAIR(GROWTH));
    mvwprintw(map_win,growth.y,growth.x,"#");
    wattroff(map_win,COLOR_PAIR(GROWTH));
    wrefresh(map_win);

}

void Snake::eatGrowth(){
    cordinate* temp = new cordinate[len];
    for(int i = 0; i < len; i++){
        temp[i].x = v[i].x; temp[i].y = v[i].y;
    }

    len++;
    score.growth++;
    if(score.Best <= len-1)
      score.Best++;
    mvwprintw(score_win,2,6,"%d",len-1);
    mvwprintw(score_win,2,8,"/");
    mvwprintw(score_win,2,10,"%d",score.Best );
    mvwprintw(score_win,4,6,"%d",score.growth );
    if(score.Best >= score.BestMi){ // 숫자 !!
      mvwprintw(Mission_win,2,10,"V");
      MiBest = true;
    }
    if(score.growth >= score.growthMi) { // ,,
      mvwprintw(Mission_win,4,10,"V");
      MiGrowItem = true;
    }
    wrefresh(score_win);
    wrefresh(Mission_win);
    delete[] v;
    v = new cordinate[len];
    for(int i = 1; i < len; i++){
        v[i].x = temp[i-1].x; v[i].y = temp[i-1].y;
    }
    v[0].x = growth.x; v[0].y = growth.y;

    isGrowth = false;
}
void Snake::eatPoison(){
    cordinate* temp = new cordinate[len];
    for(int i = 0; i < len; i++){
        temp[i].x = v[i].x; temp[i].y = v[i].y;
    }

    len--;
    if(len-1 < 3){
      exit(1);
    }
    score.poison++;
    if(len-1 == 9){
      mvwprintw(score_win,2,7," ");
    }
    mvwprintw(score_win,2,6,"%d",len-1 );
    mvwprintw(score_win,6,6,"%d",score.poison );
    if(score.poison >= score.poisonMi){ //숫자 바꾸기
      mvwprintw(Mission_win,6,10,"V");
      MiPoisonItem = true;
    }
    wrefresh(score_win);
    wrefresh(Mission_win);
    delete[] v;
    v = new cordinate[len];
    v[0].x = poison.x; v[0].y = poison.y;
    for(int i = 1; i < len; i++){
        v[i].x = temp[i-1].x; v[i].y = temp[i-1].y;
    }
    score.poison++;
    isPoison = false;
}

void Snake::gotoGate(){
    isGate = false;     //!!!!!!
    // score.B++;
    score.G++;
    mvwprintw(score_win,8,6,"%d",score.G );
    if(score.G >= score.GMi) {
      mvwprintw(Mission_win,8,10,"V" );
      MiG = true;
    }
    wrefresh(score_win);
    wrefresh(Mission_win);
    bool jumpGateNum = 1;
    const int x_seq[] ={0,1,0,-1};
    const int y_seq[] = {-1,0,1,0};
    const char keyboard_seq[] = {'w', 'd', 's', 'a'};

    // gate[0] gate[1] 구분
    if(gate[1].x <= v[0].x+1 && gate[1].x >= v[0].x-1 && gate[1].y <= v[0].y+1 && gate[1].y >= v[0].y-1)
        jumpGateNum = 0;

    // #1 먼저 가장자리일 경우
    // 상단 벽
    if(gate[jumpGateNum].y == 0)
    {
        v[0].x = gate[jumpGateNum].x+x_seq[2];
        v[0].y = gate[jumpGateNum].y+y_seq[2];
        dir = keyboard_seq[2];
        return;
    }
    // 하단 벽
    if(gate[jumpGateNum].y == NLINE-1)
    {
        v[0].x = gate[jumpGateNum].x+x_seq[0];
        v[0].y = gate[jumpGateNum].y+y_seq[0];
        dir = keyboard_seq[0];
        return;
    }
    // 좌측 벽
    if(gate[jumpGateNum].x == 0)
    {
        v[0].x = gate[jumpGateNum].x+x_seq[1];
        v[0].y = gate[jumpGateNum].y+y_seq[1];
        dir = keyboard_seq[1];
        return;
    }
    // 우측 벽
    if(gate[jumpGateNum].x == NCOL-1)
    {
        v[0].x = gate[jumpGateNum].x+x_seq[3];
        v[0].y = gate[jumpGateNum].y+y_seq[3];
        dir = keyboard_seq[3];
        return;
    }

    // #2 가장자리가 아닌 경우
    // 시계 방향 회전
    int cur_seqnum;
    for (int j = 0; j < 4; ++j)
    {
        if (dir == keyboard_seq[j])
        {
            cur_seqnum = j;
            break;
        }
    }
    while(1)
    {
        if(MAP[gate[jumpGateNum].y+y_seq[cur_seqnum]][gate[jumpGateNum].x+x_seq[cur_seqnum]] != 1)
            break;
        if(++cur_seqnum == 4)
            cur_seqnum = 0;
    }
    v[0].x = gate[jumpGateNum].x+x_seq[cur_seqnum];
    v[0].y = gate[jumpGateNum].y+y_seq[cur_seqnum];
    dir = keyboard_seq[cur_seqnum];

}

void Snake::play(){
    timeout(200);
    int key;
    //p누르면 pause;
    // timer();
    while((key=getch())!='p'){
      timer();
      if((MiGrowItem == true) && (MiBest == true) && (MiPoisonItem == true) && (MiG == true)){
        exit(1); //모든 조건 달성 시 탈출 코드
      }
        if(isPoison == false)
            generatePoison();
        if(isGrowth == false)
            generateGrowth();
        if(isGate == false) {
            generateMap();
            generateGate();
        }

        // 해야할일 그 전에 움직였던 흔적만 지우기.
        if(key == 'w' || key == 'a' || key == 's' || key == 'd'){
            moveSnake(key);

        }
        else
            moveSnake();

        curs_set(0);

    }
}
