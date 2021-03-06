#pragma once
#include "Vertex.h"

class CShape
{
public:
	CShape();
	~CShape();

private:
	CShape* pre_shape;
	CShape* next_shape;

	CVertex* vertex_head;
	CVertex* vertex_final;

public:
	//図形が閉じているか
	bool close = false;

	//前のVertexを取得
	CShape* GetPreShape();
	//前のVertexを設定
	CShape* SetPreShape(CShape* shape);
	//次のVertexを取得
	CShape* GetNextShape();
	//次のVertexを設定
	CShape* SetNextShape(CShape* shape);
	//Shapeの削除
	void FreeShape();


	//Vertexの追加
	CVertex* AppendVertex(float x, float y);
	//最初のVertexを取得
	CVertex* GetVertexHead();
	//最後のVertexを取得
	CVertex* GetVertexFinal();

};