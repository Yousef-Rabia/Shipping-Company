#include"Cargo.h"

Cargo::Cargo (CARGO_TYPE T, const Time& PT, int id, float DD, float LT, double C) {
	Preparation_Time = PT;
	Load_Unload_Time = LT;
	Delivery_Distance = DD;
	Type = T;
	Cost = C;
	ID = id;
}
Cargo::Cargo(int id)  //Fake cargo just for comparison with id
{
	ID = id;
}
float Cargo::GetDistance() const
{
	return Delivery_Distance;
}
double Cargo::GetCost() const
{
	return Cost;
}
float Cargo::GetLU_Time() const
{
	return Load_Unload_Time;
}
CARGO_TYPE Cargo::GetType() const
{
	return Type;

}
Time& Cargo::GetPrepTime()
{
	return Preparation_Time;
}
void Cargo:: PromoteToVip(double ExtraMoney)
{
	Type = CARGO_TYPE::VIP;
	Cost += ExtraMoney;
}
bool Cargo:: operator==(Cargo* ptr)
{
	if (this->ID == ptr->ID)
		return true;
	return false;
}
int Cargo::GetID() const
{
	return ID;
}
void Cargo::Set_Truck_ID(int id)
{
	Truck_ID = id;
}
int Cargo::Get_Truck_ID()
{
	return Truck_ID;
}
void Cargo::Set_DT(Time t)
{
	DT = t;
}
void Cargo::Set_WT(int t)
{
	WT.setTime(t);
	
}
Time& Cargo::Get_DT()
{
	return DT;
}
Time& Cargo::Get_WT()
{
	return WT;
}
Time& Cargo::Get_Preparation_Time()
{
	return Preparation_Time;
}
ostream& operator<<(ostream& out, const Cargo* c)
{
	out << c->GetID();
	return out;
}