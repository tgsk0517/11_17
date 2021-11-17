#include<stdio.h>

class Object
{
public:
	virtual void SetVec(float x,float y,float z)
	{
		vecX = x;
		vecY = y;
		vecZ = z;
	}

	virtual void SetVecX(float n)
	{
		vecX = n;
	}

	virtual void SetVecY(float n)
	{
		vecY = n;
	}

	virtual void SetVecZ(float n)
	{
		vecZ = n;
	}

	float GetVecX()
	{
		printf("%f\n", vecX);
		return vecX;
	}

	float GetVecY()
	{
		printf("%f\n", vecY);
		return vecY;
	}

	float GetVecZ()
	{
		printf("%f\n", vecZ);
		return vecZ;
	}

	virtual void Update() {};

protected:
	float vecX = 0;
	float vecY = 0;
	float vecZ = 0;
};

class Vehicle : public Object
{
public:
	
	virtual void SetSpeed() {};

	float GetSpeed()
	{
		printf("%f\n", speed);
		return speed;
	}

	float GetAccel()
	{
		printf("%f\n", accel);
		return accel;
	}

	virtual void Update(){};

protected:
	float speed = 0;
	float accel = 0;

};


class Car : public Vehicle
{
public:
	virtual void SetSpeed()
	{
		if (speed + accel < 0 || speed + accel >100)
		{
			printf("値が範囲外です。\n");
			return;
		}

		speed += accel;
	}

	virtual void SetAccel(float n)
	{
		if (n < -5 || n>5)
		{
			printf("値が範囲外です。\n");
			return;
		}

		accel = n;
	}

	void Update()
	{
		SetSpeed();
	}

};

int main()
{
	Car car;

	car.SetAccel(2);

	for (int i = 0; i < 100; i++)
	{
		car.Update();
		car.GetSpeed();
	}
}