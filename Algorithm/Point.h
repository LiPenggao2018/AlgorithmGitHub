class Point
{
public:
	Point();
	~Point();

	double getX();
	void setX(double x);

	double getY();
	void setY(double y);

	bool getTile();
	void setTile(bool tile);
private:
	double x;
	double y;
	bool tile;                      //������ש�Ļ���С��Ԫ��Ϊtrue
};

