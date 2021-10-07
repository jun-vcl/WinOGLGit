#include "stdafx.h"
#include "pch.h"
#include "AdminControl.h"


CAdminControl::CAdminControl()
{
	AppendShape();
}

CAdminControl::~CAdminControl()
{
	shape_head->FreeShape();
}

//描画処理
void CAdminControl::Draw()
{
	DrawPoints();
	DrawLines();
	DrawShape();
}

void CAdminControl::DrawPoints()
{
	CShape* nowS = shape_head;
	CVertex* nowV = nowS->GetVertexHead();

	while (nowS != NULL)
	{
		nowV = nowS->GetVertexHead();
		while (nowV != NULL)
		{
			glPointSize(5);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(nowV->GetX(), nowV->GetY());
			glEnd();

			nowV = nowV->GetNextVertex();
		}
		nowS = nowS->GetNextShape();
	}
}

void CAdminControl::DrawLines()
{
	CVertex* nowV = shape_final->GetVertexHead();

	glLineWidth(1.5);

	glBegin(GL_LINE_STRIP);

	while (nowV != NULL)
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(nowV->GetX(), nowV->GetY());
		nowV = nowV->GetNextVertex();
	}

	glEnd();
}


void CAdminControl::DrawShape()
{
	CShape* nowS = shape_head;
	CVertex* nowV = nowS->GetVertexHead();

	while (nowS != NULL)
	{
		if (nowS->close == true)
		{
			nowV = nowS->GetVertexHead();

			glBegin(GL_LINE_LOOP);
			glColor3f(1.0, 1.0, 1.0);
			while (nowV != NULL)
			{			
				glVertex2f(nowV->GetX(), nowV->GetY());			
				nowV = nowV->GetNextVertex();
			}
			glEnd();
		}
		nowS = nowS->GetNextShape();
	}
}


//頂点，図形の追加
void CAdminControl::SaveClick(float x, float y)
{
	CVertex* nowV = shape_final->GetVertexHead();

	if (nowV == NULL)
	{
		shape_final->AppendVertex(x, y);
	}
	else
	{
		//クリックした点とVertexの最後の点の距離が一定以下の時
		if (math.CalcDistance(x, y, shape_final->GetVertexHead()->GetX(), shape_final->GetVertexHead()->GetY()) < 0.1)
		{
			shape_final->close = true;
			AppendShape();
		}
		else
		{
			shape_final->AppendVertex(x, y);
		}
	}
	
}

//Shapeの追加
CShape* CAdminControl::AppendShape()
{
	CShape* nowS = shape_head;
	CShape* newS = new CShape();

	if (nowS != NULL)
	{
		shape_final->SetNextShape(newS);
		newS->SetPreShape(shape_final);
		shape_final = newS;
	}
	else
	{
		shape_head = newS;
		shape_final = newS;
	}

	return newS;
}



