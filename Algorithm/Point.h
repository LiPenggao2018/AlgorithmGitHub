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
	bool tile;                      //已贴瓷砖的基本小单元则为true
};

