#ifndef SCORE_H_
#define SCORE_H_
class Score
{
public:
	Score();

private:
	int Corrent; // 현재길이
	int growth;	   // grow 아이템 먹은 수 
	int growthMi;  // 요구치
	int poison;    // poison 먹은 수
	int poisonMi;  //	요구치
	int G;				 // 게이트 진입 수
	int GMi;       // 요구치
	int Best;			 // 최대길이
	int BestMi;
	friend class Snake;
};
#endif
