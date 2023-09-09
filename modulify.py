import os
import SCons.Node

def make_module(target, source, env):
    dst = target[0].get_path()
    blacklist = source[1].read()
    function_params = source[2].read()
    src = dst.replace(".gen.hpp", ".hpp")
    src = src.replace(".gen.cpp", ".cpp")
    f = open(src, "r")
    out = open(dst, "w", encoding="utf-8")

    print(src, " : ", dst)

    header_file_name = os.path.basename(dst).replace(".gen.cpp", ".gen.h")
    header_guard_name = header_file_name.replace('.', '_').upper()

    out.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    if src.endswith(".hpp"):
        out.write(f"#ifndef {header_guard_name}\n")
        out.write(f"#define {header_guard_name}\n")
        out.write(f"#define GDMODULE_IMPL\n\n")

    for line in f:
        if header_file_name in line:
            continue
        got_blacklisted = False
        for function_name in blacklist:
            line = line.replace("const RID&", "RID")
            
            if ("::" + function_name) in line:
                out.write(line)
                got_blacklisted = True
                break
            if (" " + function_name) in line:
                line = line.replace(" override;", ";")
                out.write(line)
                got_blacklisted = True
                break
        if got_blacklisted:
            continue
        for function_name in function_params:
            if ("::" + function_name) in line or (" " + function_name) in line:
                if "override_return_type" in function_params[function_name]:
                    parts = line.split(" ")
                    line =  " ".join([function_params[function_name]["override_return_type"]] + parts[1:])
                if "text_replace" in function_params[function_name]:
                    line = line.replace(function_params[function_name]["text_replace"][0], function_params[function_name]["text_replace"][1])

        out.write(
            line.replace(" _", " ")
                .replace("(_", "(")
                .replace("::_", "::")
                .replace("PhysicsServer3DExtension ", "PhysicsServer3D ")
                .replace("PhysicsServer3DExtension)", "PhysicsServer3D)")
                .replace("PhysicsDirectBodyState3DExtension ", "PhysicsDirectBodyState3D ")
                .replace("PhysicsDirectBodyState3DExtension)", "PhysicsDirectBodyState3D)")
                .replace("PhysicsDirectSpaceState3DExtension ", "PhysicsDirectSpaceState3D ")
                .replace("PhysicsDirectSpaceState3DExtension)", "PhysicsDirectSpaceState3D)")
                .replace("const RID&", "RID")
                .replace("double", "real_t")
                .replace("uint64_t p_id", "ObjectID p_id")
        )

    out.write("\n")
    if src.endswith(".hpp"):
        out.write(f"#undef GDMODULE_IMPL\n")
        out.write(f"#endif // {header_guard_name}")

    out.close()
    f.close()

def modulify(env, file_path, blacklist = [], function_params = {}, sources = []):
    output_path = file_path.replace(".hpp", ".gen.hpp")
    output_path_cpp = file_path.replace(".hpp", ".gen.cpp")
    env.Depends(
        output_path,
        [file_path, "modulify.py"]
    )
    env.Depends(
        output_path_cpp.replace(".gen.cpp", ".cpp"),
        [output_path_cpp, "modulify.py"]
    )
    print("DAB", output_path_cpp.replace(".gen.cpp", ".cpp"))
    env.CommandNoCache(
        output_path,
        ["modulify.py", env.Value(blacklist), env.Value(function_params)],
        env.Run(make_module, f"Building file {output_path}.", subprocess=False),
    )
    env.CommandNoCache(
        output_path_cpp,
        ["modulify.py", env.Value(blacklist), env.Value(function_params)],
        env.Run(make_module, f"Building file {output_path_cpp}.", subprocess=False),
    )

    path_cpp = output_path_cpp.replace(".gen.cpp", ".cpp")
    for source in sources:
        path = ""
        if not type(source) is str:
            path = source.get_path()
        else:
            path = source
        if path_cpp == path:
            sources.remove(source)
            break
    found = False
    for source in sources:
        path = ""
        if not type(source) is str:
            path = source.get_path()
        else:
            path = source
        if output_path_cpp == path:
            found = True
            break
    if not found:
        sources.append(output_path_cpp)