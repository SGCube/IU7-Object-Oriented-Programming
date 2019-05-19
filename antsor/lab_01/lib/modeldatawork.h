#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadData(ModelType& model, const FileWorkParamType param);

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param);

ErrorType modelDrawData(const VertexArrayType& verticesArray,
						const EdgeArrayType& edgesArray,
						DrawParamType& param);

ErrorType modelMoveData(VertexArrayType& verticesArray,
						const MoveParamType param);

ErrorType modelScaleData(VertexArrayType& verticesArray,
						 const ScaleParamType param);

ErrorType modelRotateData(VertexArrayType& verticesArray,
						  const RotateParamType param);

ErrorType modelProjParallelData(VertexArrayType& verticesArray,
								const ProjParallelParamType param);

ErrorType modelProjCentralData(VertexArrayType& verticesArray,
							   const ProjCentralParamType param);

#endif // MODELDATAWORK_H
