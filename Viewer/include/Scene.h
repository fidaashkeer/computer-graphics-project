#pragma once

#include <vector>
#include <memory>

#include "Camera.h"
#include "MeshModel.h"
#include "light.h"

class Scene {
public:
	Scene();

	void AddModel(const std::shared_ptr<MeshModel>& mesh_model);
	int GetModelCount() const;

	std::shared_ptr<MeshModel>GetModel(int index) const;
	//MeshModel& GetActiveModel() const;
	std::shared_ptr<MeshModel> GetActiveModel() const;
	
	void AddCamera(const std::shared_ptr<Camera>& camera);
	int GetCameraCount() const;
	Camera& GetCamera(int index);
	Camera& GetActiveCamera() const;

	void SetActiveCameraIndex(int index);
	int GetActiveCameraIndex() const;

	void SetActiveModelIndex(int index);
	int GetActiveModelIndex() const;

	void AddLight(const std::shared_ptr<light>& light);
	void SetActiveLightIndex(int index);
	int GetActiveLightIndex() const;
	std::shared_ptr<light> GetActivelight() const;
	int Get_count_oflights() const;
	std::shared_ptr<light> GetLight(int index) const;
	int GetshadingLight() const;
	void Setshading(int index);
	void Setfog(int index);
	void SetFogDensity(int index);
	int getfog() const;
	int getFogDensity() const;
	
private:
	std::vector<std::shared_ptr<MeshModel>> mesh_models_;
	std::vector<std::shared_ptr<Camera>> cameras_;
	std::vector<std::shared_ptr<light>> lights_;

	int active_camera_index_;
	int active_model_index_;
	int active_light_index_;
	int shading = 0;
	int count_oflights = 0;
	int fog = 0; // 0 linear , 1 e
	float FogDensity = 5;
};