/* THIS FILE IS GENERATED DO NOT EDIT */
#ifndef JOLT_JOINT_GIZMO_PLUGIN_3D_GEN_HPP
#define JOLT_JOINT_GIZMO_PLUGIN_3D_GEN_HPP
#define GDMODULE_IMPL

#pragma once

#ifdef GDJ_CONFIG_EDITOR


#if defined(GDEXTENSION) || defined(GDMODULE_IMPL)

class JoltJointGizmoPlugin3D final : public EditorNode3DGizmoPlugin {
	GDCLASS_NO_WARN(JoltJointGizmoPlugin3D, EditorNode3DGizmoPlugin)

private:
	static void bind_methods();

public:
	JoltJointGizmoPlugin3D() = default;

	explicit JoltJointGizmoPlugin3D(EditorInterface* p_editor_interface);

	bool has_gizmo(Node3D* p_node) GDEX_CONST_EX_ONLY override;

	Ref<EditorNode3DGizmo> create_gizmo(Node3D* p_node) GDEX_CONST_EX_ONLY override;

	String get_gizmo_name() const override;

	void _redraw(const Ref<EditorNode3DGizmo>& p_gizmo) GDEX_OVERRIDE_EX_ONLY;

	void redraw_gizmos();

#ifndef GDEXTENSION
	void redraw(EditorNode3DGizmo *p_gizmo) override {
		Ref<EditorNode3DGizmo> gizmo = Ref<EditorNode3DGizmo>(p_gizmo);
		_redraw(gizmo);
	};
#endif

private:
	void _create_materials();

	void _create_redraw_timer(const Ref<EditorNode3DGizmo>& p_gizmo);

	mutable HashSetJolt<Ref<EditorNode3DGizmo>> gizmos;

	EditorInterface* editor_interface = nullptr;

	bool initialized = false;
};

#endif // GDJ_CONFIG_EDITOR
#endif
#undef GDMODULE_IMPL
#endif // JOLT_JOINT_GIZMO_PLUGIN_3D_GEN_HPP