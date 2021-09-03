class Move
{
private:
    int from;
    int to;
public:

    Move(int start,int finish);
    Move();
    int getFrom(){return from;}
    int getTo(){ return to;}
};

