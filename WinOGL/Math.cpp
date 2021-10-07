#include "pch.h"
#include "Math.h"

//“ñ“_ŠÔ‚Ì‹——£‚ÌŒvŽZ
float CMath::CalcDistance(CVertex* V1, CVertex* V2)
{
	return sqrt(pow(V1->GetX() - V2->GetX(), 2) + pow(V1->GetY() - V2->GetY(), 2));
}

float CMath::CalcDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}