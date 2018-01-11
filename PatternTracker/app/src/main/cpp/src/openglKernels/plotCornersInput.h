static const char *plotCornersInput_kernel =
"#version 310 es\n"
"#define LOCAL_SIZE 1\n"
"\n"
"#extension GL_ANDROID_extension_pack_es31a : require\n"
"layout(local_size_x = LOCAL_SIZE, local_size_y = LOCAL_SIZE) in;\n"
"layout(binding=0, rgba32f) uniform mediump writeonly image2D output_image;\n"
"layout(std430, binding = 2) buffer pts_ssbo {float pts[];};\n"
"layout(std430, binding = 3) buffer colVals_ssbo {float colVals[];};\n"
"void main()\n"
"{\n"
"	float r = colVals[0];\n"
"	float g = colVals[1];\n"
"	float b = colVals[2];\n"
"	\n"
"\t\tint p0 = int(gl_GlobalInvocationID.x);\n"
"\t\tivec2 pos;\n"
"\t\tvec4 pixelf;\n"
"\t\t\n"
"\t\tint x = int(pts[p0*2]);\n"
"\t\tint y = int(pts[p0*2+1]);\n"
"\t\t\n"
"\t\tint s=5;\n"
"\t\tint flag=0;\n"
"\t\tfor(int i=-s;i<s;i++){\n"
"\t\t\t\tfor(int j=-s;j<s;j++){\n"
"\t\t\t\t\t\t pos.x=y+j;\n"
"\t\t\t\t\t\t pos.y=x+i;\n"
"\t\t\t\t\t\t if(pos.x>=0 && pos.x<1920 && pos.y>=0 && pos.y<1080){\n"
"\t\t\t\t\t\t\t\t pixelf.x = r;\n"
"\t\t\t\t\t\t\t\t pixelf.y = g;\n"
"\t\t\t\t\t\t\t\t pixelf.z = b;\n"
"\t\t\t\t\t\t\t\t pixelf.w = 1.0;\n"
"				 imageStore(output_image, pos, pixelf);\n"
"\t\t\t\t\t\t\t\t //write_imagef(out_image, pos, pixelf);\n"
"\t\t\t\t\t\t}\n"
"\t\t\t\t}\n"
"\t\t}\t\n"
"}\n";
