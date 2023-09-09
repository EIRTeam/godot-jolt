/* THIS FILE IS GENERATED DO NOT EDIT */
#ifndef JOLT_PHYSICS_DIRECT_SPACE_STATE_3D_GEN_HPP
#define JOLT_PHYSICS_DIRECT_SPACE_STATE_3D_GEN_HPP
#define GDMODULE_IMPL

#pragma once


#if defined(GDEXTENSION) || defined(GDMODULE_IMPL)

class JoltBodyImpl3D;
class JoltShapeImpl3D;
class JoltSpace3D;

class JoltPhysicsDirectSpaceState3D final : public PhysicsDirectSpaceState3D {
	GDCLASS_NO_WARN(JoltPhysicsDirectSpaceState3D, PhysicsDirectSpaceState3D)

private:
	static void bind_methods() { }

public:
	JoltPhysicsDirectSpaceState3D() = default;

	explicit JoltPhysicsDirectSpaceState3D(JoltSpace3D* p_space);

	bool _intersect_ray(
		const Vector3& p_from,
		const Vector3& p_to,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		bool p_hit_from_inside,
		bool p_hit_back_faces,
		bool p_pick_ray,
		PhysicsServer3DExtensionRayResult* p_result
	) GDEX_OVERRIDE_EX_ONLY;

	int32_t _intersect_point(
		const Vector3& p_position,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		PhysicsServer3DExtensionShapeResult* p_results,
		int32_t p_max_results
	) GDEX_OVERRIDE_EX_ONLY;

	int32_t _intersect_shape(
		RID p_shape_rid,
		const Transform3D& p_transform,
		const Vector3& p_motion,
		real_t p_margin,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		PhysicsServer3DExtensionShapeResult* p_results,
		int32_t p_max_results
	) GDEX_OVERRIDE_EX_ONLY;

	bool _cast_motion(
		RID p_shape_rid,
		const Transform3D& p_transform,
		const Vector3& p_motion,
		real_t p_margin,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		float* p_closest_safe,
		float* p_closest_unsafe,
		PhysicsServer3DExtensionShapeRestInfo* p_info
	) GDEX_OVERRIDE_EX_ONLY;

	bool _collide_shape(
		RID p_shape_rid,
		const Transform3D& p_transform,
		const Vector3& p_motion,
		real_t p_margin,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		void* p_results,
		int32_t p_max_results,
		int32_t* p_result_count
	) GDEX_OVERRIDE_EX_ONLY;

	bool _rest_info(
		RID p_shape_rid,
		const Transform3D& p_transform,
		const Vector3& p_motion,
		real_t p_margin,
		uint32_t p_collision_mask,
		bool p_collide_with_bodies,
		bool p_collide_with_areas,
		PhysicsServer3DExtensionShapeRestInfo* p_info
	) GDEX_OVERRIDE_EX_ONLY;

	Vector3 _get_closest_point_to_object_volume(RID p_object, const Vector3& p_point)
		const GDEX_OVERRIDE_EX_ONLY;

	bool test_body_motion(
		const JoltBodyImpl3D& p_body,
		const Transform3D& p_transform,
		const Vector3& p_motion,
		float p_margin,
		int32_t p_max_collisions,
		bool p_collide_separation_ray,
		bool p_recovery_as_collision,
		PhysicsServer3DExtensionMotionResult* p_result
	) const;

	JoltSpace3D& get_space() const { return *space; }

#ifndef GDEXTENSION
	thread_local static const HashSet<RID> *exclude;

	bool is_body_excluded_from_query(const RID &p_body) const {
		return exclude && exclude->has(p_body);
	}
	
	virtual bool intersect_ray(const RayParameters &p_parameters, RayResult &r_result) override {
		exclude = &p_parameters.exclude;
		bool ret = _intersect_ray(p_parameters.from, p_parameters.to, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, p_parameters.hit_from_inside, p_parameters.hit_back_faces, p_parameters.pick_ray, &r_result);
		exclude = nullptr;
		return ret;
	}
	virtual int intersect_point(const PointParameters &p_parameters, ShapeResult *r_results, int p_result_max) override {
		exclude = &p_parameters.exclude;
		int ret = _intersect_point(p_parameters.position, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, r_results, p_result_max);
		exclude = nullptr;
		return ret;
	}
	virtual int intersect_shape(const ShapeParameters &p_parameters, ShapeResult *r_results, int p_result_max) override {
		exclude = &p_parameters.exclude;
		int ret = 0; _intersect_shape(p_parameters.shape_rid, p_parameters.transform, p_parameters.motion, p_parameters.margin, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, r_results, p_result_max);
		exclude = nullptr;
		return ret;
	}
	virtual bool cast_motion(const ShapeParameters &p_parameters, real_t &p_closest_safe, real_t &p_closest_unsafe, ShapeRestInfo *r_info = nullptr) override {
		exclude = &p_parameters.exclude;
		bool ret = _cast_motion(p_parameters.shape_rid, p_parameters.transform, p_parameters.motion, p_parameters.margin, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, &p_closest_safe, &p_closest_unsafe, r_info);
		exclude = nullptr;
		return ret;
	}
	virtual bool collide_shape(const ShapeParameters &p_parameters, Vector3 *r_results, int p_result_max, int &r_result_count) override {
		exclude = &p_parameters.exclude;
		bool ret = _collide_shape(p_parameters.shape_rid, p_parameters.transform, p_parameters.motion, p_parameters.margin, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, r_results, p_result_max, &r_result_count);
		exclude = nullptr;
		return ret;
	}
	virtual bool rest_info(const ShapeParameters &p_parameters, ShapeRestInfo *r_info) override {
		exclude = &p_parameters.exclude;
		bool ret = _rest_info(p_parameters.shape_rid, p_parameters.transform, p_parameters.motion, p_parameters.margin, p_parameters.collision_mask, p_parameters.collide_with_bodies, p_parameters.collide_with_areas, r_info);
		exclude = nullptr;
		return ret;
	}

	virtual Vector3 get_closest_point_to_object_volume(RID p_object, const Vector3 p_point) const override {
		Vector3 ret = _get_closest_point_to_object_volume(p_object, p_point);
		return ret;
	}
#endif

private:
	bool _cast_motion_impl(
		const JPH::Shape& p_jolt_shape,
		const Transform3D& p_transform_com,
		const Vector3& p_scale,
		const Vector3& p_motion,
		bool p_ignore_overlaps,
		const JPH::CollideShapeSettings& p_settings,
		const JPH::BroadPhaseLayerFilter& p_broad_phase_layer_filter,
		const JPH::ObjectLayerFilter& p_object_layer_filter,
		const JPH::BodyFilter& p_body_filter,
		const JPH::ShapeFilter& p_shape_filter,
		float& p_closest_safe,
		float& p_closest_unsafe
	) const;

	bool body_motion_recover(
		const JoltBodyImpl3D& p_body,
		const Transform3D& p_transform,
		float p_margin,
		Vector3& p_recovery
	) const;

	bool body_motion_cast(
		const JoltBodyImpl3D& p_body,
		const Transform3D& p_transform,
		const Vector3& p_scale,
		const Vector3& p_motion,
		bool p_collide_separation_ray,
		float& p_safe_fraction,
		float& p_unsafe_fraction
	) const;

	bool body_motion_collide(
		const JoltBodyImpl3D& p_body,
		const Transform3D& p_transform,
		float p_distance,
		float p_margin,
		int32_t p_max_collisions,
		PhysicsServer3DExtensionMotionResult* p_result
	) const;

	JoltSpace3D* space = nullptr;
};
#endif
#undef GDMODULE_IMPL
#endif // JOLT_PHYSICS_DIRECT_SPACE_STATE_3D_GEN_HPP