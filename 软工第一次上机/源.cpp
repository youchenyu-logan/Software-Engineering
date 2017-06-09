#include<stdio.h>
#include<math.h>

typedef struct Circle {
	double x;
	double y;
	double r;
	Circle *next;
}CIRCLE;
bool ifOverlap2(double x, double y, double r) {
	CIRCLE *temp = circlesHead->next;
	while (temp!=null) {
		if (temp->r + r > sqrt((temp->x - x)*(temp->x - x) + (temp->y - y)*(temp->y - y)))
			return false;
		temp = temp->next;
	}
	return true;
}
void Brute_Force_max2d()
{
	CIRCLE *add = new CIRCLE, *temp;
	add->r = 1;
	add->x = 0;
	add->y = 0;
	add->next = NULL;
	CieclesHead->next = add;

	for (int i = 1; i < M; i++)
	{
		for (double r = 0.180; r > 0; r -= STEPSIZE)
		{
			for (double x = -1.0 + r; x < 1.0 - r; x += STEPSIZE)//三四象限
				for (double y = -1.0 + r; y <(-1) * sqrt(1 - x * x); y += STEPSIZE)
				{
					if (ifOverlap2(x, y, r))
					{
						temp = new CIRCLE;
						temp->r = r;
						temp->x = x;
						temp->y = y;
						temp->next = NULL;
						add->next = temp;
						add = add->next;
						goto exit;
					}
				}
			for (double x = -1.0 + r; x < 1.0 - r; x += STEPSIZE)//一二象限
				for (double y = sqrt(1 - x * x); y < 1.0 - r; y += STEPSIZE)
				{
					if (ifOverlap2(x, y, r))
					{
						temp = new CIRCLE;
						temp->r = r;
						temp->x = x;
						temp->y = y;
						temp->next = NULL;
						add->next = temp;
						add = add->next;
						goto exit;
					}
				}

		}
	exit:
		continue;
	}
}
