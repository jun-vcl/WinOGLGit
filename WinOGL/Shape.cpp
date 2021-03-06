#include "stdafx.h"
#include "pch.h"
#include "Shape.h"
#include "Vertex.h"


CShape::CShape()
{
}


CShape::~CShape()
{
	vertex_head->FreeVertex();
}

//Shapeの削除
void CShape::FreeShape()
{
	CShape* nowS = this;
	while (nowS != NULL)
	{
		CShape* del_cell = nowS;
		nowS = nowS->GetNextShape();
		delete del_cell;
	}
}

//前のVertexを取得
CShape* CShape::GetPreShape()
{
	return pre_shape;
}

//前のVertexを設定
CShape* CShape::SetPreShape(CShape* shape)
{
	return pre_shape = shape;
}

//次のVertexを取得
CShape* CShape::GetNextShape()
{
	return next_shape;
}

//次のVertexを設定
CShape* CShape::SetNextShape(CShape* shape)
{
	return next_shape = shape;
}

CVertex* CShape::AppendVertex(float x, float y)
{
	CVertex* nowV = vertex_head;
	CVertex* newVertex = new CVertex(x, y);

	if (nowV != NULL)
	{
		newVertex->SetPreVertex(vertex_final);
		vertex_final->SetNextVertex(newVertex);
		vertex_final = newVertex;
	}
	else
	{
		vertex_head = newVertex;
		vertex_final = newVertex;
	}

	return newVertex;
}

//最初のVertexを取得
CVertex* CShape::GetVertexHead()
{
	return vertex_head;
}

//最後のVertexを取得
CVertex* CShape::GetVertexFinal()
{
	return vertex_final;
}
