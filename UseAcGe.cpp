#include "UseAcGe.h"
#include <genurb3d.h>
#include <iostream>

void UseAcGe::testInsert()
{
	AcGeLine2d line(AcGePoint2d::kOrigin, AcGePoint2d(50, 0));
	AcGeLine2d line1(AcGePoint2d(25, 0), AcGePoint2d(25, 100));

	AcGePoint2d pt;
	line.intersectWith(line1, pt);

	std::cout << "交点 x: " << pt.x << " y: " << pt.y;

}

void UseAcGe::CreateBSpline()
{
	// 定义起始点和起始向量
	AcGePoint3d startPoint(38654.2750969712, 16499.9999811757, 5795.54101467122);
	AcGeVector3d startVector(36801.6355494103, 16463.147993944, 5350.85547346213);
	startVector.normalize();

	// 定义终止点和终止向量
	AcGePoint3d endPoint(-273.366753058261, -3.61443798542878, 134.76124873432);
	AcGeVector3d endVector(-180.225889920184, 91.8448920317317, -228.004790322829);
	endVector.normalize();

	// 定义插值点
	AcGePoint3d interpolationPoint(37727.9553231907, 16481.5739875598, 5673.19824406668);

	// 创建控制点数组
	AcGePoint3dArray controlPoints;
	controlPoints.append(startPoint);
	controlPoints.append(interpolationPoint);
	controlPoints.append(endPoint);

	// 创建节点向量数组
	AcGeKnotVector knots;
	knots.append(0);
	knots.append(0);
	knots.append(0);
	knots.append(0);
	knots.append(0.5);
	knots.append(0.5);
	knots.append(1);
	knots.append(1);
	knots.append(1);
	knots.append(1);

	// 创建 B 样条曲线
	AcGeNurbCurve3d nurbCurve(controlPoints, startVector, endVector, Adesk::kTrue, Adesk::kTrue, AcGe::kCustomParameterization);

	// 输出插值点
	for (int i = 0; i < nurbCurve.numFitPoints(); i++)
	{
		AcGePoint3d pt;
		nurbCurve.getFitPointAt(i, pt);
		std::cout << "X: " << pt.x << "Y: " << pt.y << "Z: " << pt.z << std::endl;
	}
}