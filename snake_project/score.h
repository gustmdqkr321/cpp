#ifndef SCORE_H_
#define SCORE_H_
//@author 20191595 박승현
class Score
{
public:
	Score();

private:
	int Corrent;
	int growth;
	int growthMi;
	int poison;
	int poisonMi;
	int G;
	int GMi;
	int Best;
	int BestMi;
	friend class Snake;
};
#endif
